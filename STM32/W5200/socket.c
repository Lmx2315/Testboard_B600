#include <string.h>
#include "w5200.h"

extern Socket_Typedef Socket[MAX_SOCK_NUM];
extern Call_Back_Struct_Typedef CallBack_Param;
extern Socket_Callback_Typedef Socket_CallBack[MAX_SOCK_NUM];
extern uint8_t Connecting; //errata

uint8_t W5200_Set_Network(Network_Typedef* Network)
{
	uint8_t Ok;
	Ok = W5200_Add_Set_SIPR(Network->IP);
	saveSUBR(Network->Mask);
	Ok &= W5200_Add_Set_GAR(Network->Gateway);
	return Ok;
}

//Инициализация сокета.
uint8_t Socket_Init(SOCKET s, Socket_Callback_Typedef Callback)
{
	if((s < MAX_SOCK_NUM) && !Socket[s].Param.Event.Open)
	{
		Socket_CallBack[s] = Callback;
		return 1;
	}
	return 0;
}

/**
@brief	This function close the socket and parameter is "s" which represent the socket number
*/

uint8_t Socket_Close(SOCKET s)
{
	uint8_t Ok;
	Ok = W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_CLOSE);
	Ok &= W5200_Add_To_Buff(0, Sn_CR(s), 1, 0);
	if(Ok)
	{
		memset(&Socket[s].Param, 0, sizeof(Socket_Param_Typedef));
		Socket[s].Param.Index = s;
		Connecting &= ~(1 << s);
	}
	Ok &= W5200_Send_CallBack(0, 0);
	return Ok;
}

static uint8_t Socket_Open_Repeat_Counter = 0;
static const uint8_t Protocol_Table[6] = {0, SOCK_INIT, SOCK_UDP, SOCK_IPRAW, SOCK_MACRAW, SOCK_PPPOE};
static void Socket_Open_Verify(SOCKET s);

static uint8_t Socket_Open_Repeat(SOCKET s)
{
	uint8_t Ok;
	uint16_t swp = SWAP16(Socket[s].Port);
	Ok = W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_CLOSE);
	Ok &= W5200_Add_To_Buff(0, Sn_CR(s), 1, 0);
	Ok &= W5200_Add_To_Buff_Byte_Const(Sn_MR(s), Socket[s].Protocol | Socket[s].flag);
	Ok &= W5200_Add_To_Buff((uint8_t*)&swp, Sn_PORT0(s), 2, 1);
	Ok &= W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_OPEN); // run sockinit Sn_CR
	Ok &= W5200_Add_Get_Sn_SR(s, &CallBack_Param.Buffers[0].Address);
	Ok &= W5200_Add_Get_Sn_RX_RD(s, &CallBack_Param.Buffers[1].Address);
	Ok &= W5200_Add_Get_Sn_TX_WR(s, &CallBack_Param.Buffers[2].Address);
	Ok &= W5200_Send_CallBack(s, Socket_Open_Verify);
	return Ok;
}

static void Socket_Open_Verify(SOCKET s)
{
	Socket[s].Param.Status = *(CallBack_Param.Buffers[0].Address);
	if(Socket[s].Param.Status == Protocol_Table[Socket[s].Protocol])
	{
		Socket[s].RX_RD = SWAP16(*(uint16_t*)CallBack_Param.Buffers[1].Address);
		Socket[s].TX_WR = SWAP16(*(uint16_t*)CallBack_Param.Buffers[2].Address);
		Socket[s].Param.Event.Open = 1;
	}
	else
	{
		if(Socket_Open_Repeat_Counter)
		{
			Socket_Open_Repeat_Counter--;
			Socket_Open_Repeat(s);
		}
		else
		{
			W5200_Reset();
		}
	}
};

/**
@brief	This Socket function initialize the channel in perticular mode, and set the port and wait for W5200 done it.
@return 	1 for sucess else 0.
*/

uint8_t Socket_Open(SOCKET s, uint8_t protocol, uint16_t port, uint8_t flag)
{
	if ((protocol >= Sn_MR_TCP) && (protocol <= Sn_MR_PPPOE) && (port != 0))
	{
		Socket[s].Protocol = protocol;
		Socket[s].Port = port;
		Socket[s].flag = flag;
		Socket_Open_Repeat_Counter = 3;
		return Socket_Open_Repeat(s);
	}
	return 0;
}

/**
@brief	This function established  the connection for the channel in passive (server) mode. This function waits for the request from the peer.
@return	1 for success else 0.
*/

static void Socket_Get_Status(SOCKET s)
{
	Socket[s].Param.Status = *(CallBack_Param.Buffers[0].Address);	
}

uint8_t Socket_Listen(SOCKET s)
{
	uint8_t Ok = 0;
	if(Socket[s].Param.Status == SOCK_INIT)
	{
		Ok = W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_LISTEN);
		Ok &= W5200_Add_To_Buff(0, Sn_SR(s), 1, 0);
		Ok &= W5200_Add_Get_Sn_SR(s, &CallBack_Param.Buffers[0].Address);
		Ok &= W5200_Send_CallBack(s, Socket_Get_Status);
	}
	return Ok;
}


/**
@brief	This function established  the connection for the channel in Active (client) mode. 
		This function waits for the untill the connection is established.
		
@return	1 for success else 0.
*/ 
uint8_t Socket_Connect(SOCKET s, uint8_t * addr, uint16_t port)
{
	uint8_t Ok = 0;
	uint8_t swp;
	if ((*(uint32_t*)addr != 0xFFFFFFFF) && (*(uint32_t*)addr != 0x00000000) &&	(port != 0x00))
	{
		swp = SWAP16(port);
		Ok = W5200_Add_To_Buff(addr, Sn_DIPR0(s), 4, 1);		// set destination IP
		Ok &= W5200_Add_To_Buff((uint8_t*)&swp, Sn_PORT0(s), 2, 1); // set port
		Ok &= W5200_Add_Set_SUBR();	// set subnet mask errata
		Ok &= W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_CONNECT); // run sockinit Sn_CR
		Ok &= W5200_Add_Get_Sn_SR(s, &CallBack_Param.Buffers[0].Address);
		Connecting |= 1 << s;
		Ok &= W5200_Send_CallBack(s, Socket_Get_Status);
	}
	return Ok;
}

/**
@brief	This function used for disconnect the SocketOpen and parameter is "s" which represent the SocketOpen number
@return	1 for success else 0.
*/ 

uint8_t Socket_Disconnect(SOCKET s)
{
	uint8_t Ok;
	Ok = W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_DISCON); // run sockinit Sn_CR
	Ok &= W5200_Add_To_Buff(0, Sn_SR(s), 1, 0);
	Ok &= W5200_Add_Get_Sn_SR(s, &CallBack_Param.Buffers[0].Address);
	Ok &= W5200_Send_CallBack(s, Socket_Get_Status);
	return Ok;
}

/**
@brief	This function used to send the data in TCP mode
@return	1 for success else 0.
*/ 
uint16_t Socket_TCP_Send(SOCKET s, const uint8_t * Source, uint32_t Length, bool Retry)
{
	uint8_t Ok = 0;
	if(Length <= Socket[s].Param.TX_Free_Size)
	{
		Ok = W5200_Add_Write_Data(s, Source, Length);
		Ok &= W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_SEND);
		Ok &= W5200_Send_CallBack(0, 0);
	}
	return Ok;
}

uint8_t Socket_UDP_Send(SOCKET s, const uint8_t* Source, uint16_t Length, uint8_t* IP, uint16_t Port)
{
	uint8_t Ok = 0;
	uint16_t swp;
	if ((Length < Socket[s].TX_Size)&&(*(uint32_t*)IP != 0x00000000) &&	(Port != 0x00))
	{
		swp = SWAP16(Port);
		Ok = W5200_Add_To_Buff(IP, Sn_DIPR0(s), 4, 1);
		Ok &= W5200_Add_To_Buff((uint8_t*)&swp, Sn_DPORT0(s), 2, 1);
 		Ok &= W5200_Add_Write_Data(s, Source, Length);
		Ok &= W5200_Add_Set_SUBR();	//errata
		Ok &= W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_SEND);
		Ok &= W5200_Send_CallBack(0, 0);
	}
	return Ok;
}
