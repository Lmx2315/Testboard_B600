#include <string.h>
#include "w5200.h"
#include "w5200driver.h"
#include "system_timer.h"

typedef enum
{
	ws_Reset,
	ws_Wait_Reset = 0x33,
	ws_Setup = 0xAA,
	ws_Wait = 0x55,
	ws_Work = 0xCC
}W5200_Status_State_Typedef;

typedef struct
{
	W5200_Status_State_Typedef State;
	unsigned Ready :1;
	unsigned :7;
}W5200_Status_Typedef;

static uint8_t MAC[6];
W5200_Status_Typedef W5200_Status;
static int8_t W5200_Timer;
static Network_Typedef Network;
static CallBack_Typedef CallBack; //Функция возврата после передачи буфера по SPI
static void (*IPConflict_Handler)(void) = 0;
uint8_t WBuffer[2248];
uint8_t RBuffer[2048];
uint8_t* WBuffer_Ptr = WBuffer;
Call_Back_Struct_Typedef CallBack_Param;
Header_Typedef Header;
uint8_t Socket_Temp;
Socket_Callback_Typedef Socket_CallBack[MAX_SOCK_NUM];
uint8_t Connecting = 0; //errata connect;

Socket_Typedef Socket[MAX_SOCK_NUM];

/**
@brief	This function read and writes the data into W5200 registers.
*/

uint8_t W5200_Add_To_Buff(const uint8_t* Source, uint16_t addr, uint16_t Length, uint8_t Write)
{
	if(!Length) return 0;
	if(WBuffer_Ptr + Length + 4 - WBuffer > sizeof(WBuffer))return 0;
	*WBuffer_Ptr++ = addr >> 8;
	*WBuffer_Ptr++ = addr;
	*WBuffer_Ptr++ = (Length >> 8) | (!!Write << 7);
	*WBuffer_Ptr++ = Length;
	if(Write)
		memcpy(WBuffer_Ptr, Source, Length);
	else
		memset(WBuffer_Ptr, 0, Length);
	WBuffer_Ptr += Length;
	return 1;
}

uint8_t W5200_Add_To_Buff_Byte_Const(uint16_t addr, const uint8_t Byte)
{
	return W5200_Add_To_Buff(&Byte, addr, 1, 1);
}

/**
@brief	This function is for resetting of the iinchip. Initializes the iinchip to work in whether DIRECT or INDIRECT mode
*/ 
uint8_t W5200_Add_Reset(void)
{	
	return W5200_Add_To_Buff_Byte_Const(MR, MR_RST);
}

/**
@brief	This function sets up gateway IP address.
*/

uint8_t W5200_Add_Set_GAR(uint8_t * addr)
{
	return W5200_Add_To_Buff(addr, GAR0, 4, 1);
}

/**
@brief	It sets up SubnetMask address
*/

void saveSUBR(uint8_t * addr)	/**< a pointer to a 4 -byte array responsible to set the SubnetMask address */
{
	*(uint32_t*)Network.Mask = *(uint32_t*)addr;
}

uint8_t W5200_Add_Set_SUBR(void)
{   
	return W5200_Add_To_Buff(Network.Mask, SUBR0, 4, 1);
}

uint8_t W5200_Add_Clear_SUBR(void)
{
	const uint8_t zero[4] = {0,0,0,0};
	return W5200_Add_To_Buff(zero, SUBR0, 4, 1);
}

/**
@brief	This function sets up MAC address.
*/

uint8_t W5200_Add_Set_SHAR(const uint8_t * addr)	/**< a pointer to a 6 -byte array responsible to set the MAC address. */
{
	return W5200_Add_To_Buff((uint8_t*)addr, SHAR0, 6, 1);
}

/**
@brief	This function sets up Source IP address.
*/
uint8_t W5200_Add_Set_SIPR(uint8_t * addr)	/**< a pointer to a 4 -byte array responsible to set the Source IP address. */
{
	return W5200_Add_To_Buff((uint8_t*)addr, SIPR0, 4, 1);
}

/**
@brief	This function sets up Source IP address.
*/
uint8_t W5200_Add_Get_GAR(uint8_t **addr)  //указатель на указатель. Передаем адрес указателя,
//который после обработки будет хранить адрес на массив c данными во временном буфере. Для сохранения нужно использовать memcpy
{
	*addr = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, GAR0, 4, 0);
}

void getSUBR(uint8_t * addr)
{
	*(uint32_t*)addr = *(uint32_t*)Network.Mask;
}

uint8_t W5200_Add_Get_SHAR(uint8_t **addr) //по аналогии с W5200_Add_Get_GAR
{
	*addr = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, SHAR0, 6, 0);
}

uint8_t W5200_Add_Get_SIPR(uint8_t **addr) //по аналогии с W5200_Add_Get_GAR
{
	*addr = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, SIPR0, 4, 0);
}

uint8_t W5200_Add_Set_MR(uint8_t val)
{
	return W5200_Add_To_Buff((uint8_t*)&val, MR, 1, 1);
}

uint8_t W5200_Add_Set_IMR2(uint8_t mask)
{
	return W5200_Add_To_Buff((uint8_t*)&mask, IMR2, 1, 1);
}

uint8_t W5200_Add_Set_IMR(uint8_t mask)
{
	return W5200_Add_To_Buff((uint8_t*)&mask, _IMR, 1, 1);
}

uint8_t W5200_Add_Set_IR(uint8_t mask)
{
	return W5200_Add_To_Buff((uint8_t*)&mask, IR, 1, 1);
}

uint8_t W5200_Add_Get_IMR2(uint8_t **Imr2)
{
	*Imr2 = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, IMR2, 1, 0);
}

uint8_t W5200_Add_Get_IR2(uint8_t **Ir2)
{
	*Ir2 = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, IR2, 1, 0);
}

uint8_t W5200_Add_Get_Sn_RX_RD(SOCKET s, uint8_t** Sn_RX_RD)
{
	*Sn_RX_RD = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, Sn_RX_RD0(s), 2, 0);
}

uint8_t W5200_Add_Get_Sn_TX_WR(SOCKET s, uint8_t** Sn_TX_WR)
{
	*Sn_TX_WR = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, Sn_TX_WR0(s), 2, 0);
}

uint8_t W5200_Add_Get_PHY(uint8_t** Phy)
{
	*Phy = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, PHY, 1, 0);
}

/**
@brief	This function gets Interrupt register in common register.
 */

uint8_t W5200_Add_Get_IR(uint8_t **Ir)
{
	*Ir = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, IR, 1, 0);
}

/**
@brief	This function sets up Retransmission time.

If there is no response from the peer or delay in response then retransmission 
will be there as per RTR (Retry Time-value Register)setting
*/

uint8_t W5200_Add_Set_RTR(uint16_t Timeout)
{
	uint16_t swp = SWAP16(Timeout);
	return W5200_Add_To_Buff((uint8_t*)&swp, RTR, 2, 1);
}

/**
@brief	This function set the number of Retransmission.

If there is no response from the peer or delay in response then recorded time 
as per RTR & RCR register seeting then time out will occur.
*/

uint8_t W5200_Add_Set_RCR(uint8_t Retry)
{
	return W5200_Add_To_Buff((uint8_t*)&Retry, _RCR, 1, 1);
}

/**
@brief	This sets the maximum segment size of TCP in Active Mode), while in Passive Mode this is set by peer
*/

uint8_t W5200_Add_Set_MSS(SOCKET s, uint16_t Sn_MSSR0)
{
	uint16_t swp = SWAP16(Sn_MSSR0);
	return W5200_Add_To_Buff((uint8_t*)&swp, Sn_MSSR0(s), 2, 1);
}

uint8_t W5200_Add_Set_Sn_RX_RD(SOCKET s, uint16_t Sn_RX_RD)
{
	uint16_t swp = SWAP16(Sn_RX_RD);
	return W5200_Add_To_Buff((uint8_t*)&swp, Sn_RX_RD0(s), 2, 1);
}

uint8_t W5200_Add_Set_Sn_TTL(SOCKET s, uint8_t ttl)
{
	return W5200_Add_To_Buff_Byte_Const(Sn_TTL(s), ttl);
}

uint8_t W5200_Add_Set_Sn_IR(SOCKET s, uint8_t Ir)
{
	return W5200_Add_To_Buff_Byte_Const(Sn_IR(s), Ir);
}

/**
@brief	These below function is used to setup the Protocol Field of IP Header when
		executing the IP Layer RAW mode.
*/

uint8_t W5200_Add_Set_PROTO(SOCKET s, uint8_t proto)
{
	return W5200_Add_To_Buff_Byte_Const(Sn_PROTO(s), proto);
}

/**
@brief	get SocketOpen interrupt status

These below functions are used to read the Interrupt & Soket Status register
*/

uint8_t W5200_Add_Get_Sn_IR(SOCKET s, uint8_t** Sn_IR)
{
	*Sn_IR = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, Sn_IR(s), 1, 0);
}

uint8_t W5200_Add_Res_Sn_IR(SOCKET s, uint8_t flag) // reset SocketOpen interrupt status
{
	return W5200_Add_To_Buff_Byte_Const(Sn_IR(s),flag);
}

/**
@brief	 get SocketOpen status
*/

uint8_t W5200_Add_Get_Sn_SR(SOCKET s, uint8_t ** Sn_SR) // get SocketOpen status
{
	*Sn_SR = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, Sn_SR(s), 1, 0);
}

/**
@brief	get SocketOpen TX free buf size

This gives free buffer size of transmit buffer. This is the data size that user can transmit.
User shuold check this value first and control the size of transmitting data
*/

uint8_t W5200_Add_Get_Sn_TX_FSR(SOCKET s, uint8_t** Sn_TX_FSR)
{
	*Sn_TX_FSR = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, Sn_TX_FSR0(s), 2, 0);
}

/**
@brief	 get SocketOpen RX recv buf size

This gives size of received data in receive buffer. 
*/

uint8_t W5200_Add_Get_Sn_RX_RSR(SOCKET s, uint8_t** Sn_RX_RSR)
{
	*Sn_RX_RSR = &WBuffer_Ptr[4];
	return W5200_Add_To_Buff(0, Sn_RX_RSR0(s), 2, 0);
}

/**
@brief	for copy the data form application buffer to Transmite buffer of the chip.

This function is being used for copy the data form application buffer to Transmite
buffer of the chip. It calculate the actual physical address where one has to write
the data in transmite buffer. Here also take care of the condition while it exceed
the Tx memory uper-bound of SocketOpen.
*/

uint8_t W5200_Add_Write_Data(SOCKET s, const uint8_t *Source, uint16_t Length)
{
	uint8_t Ok;
	uint16_t size;
	uint16_t dst_mask;
	uint16_t dst_ptr;
	Socket_Typedef *S = &Socket[s];
	dst_mask = S->TX_WR & S->TX_Mask;
	dst_ptr = S->TX_StartAddress | dst_mask;

	if (dst_mask + Length > S->TX_Size)
	{
		size = S->TX_Size - dst_mask;
		Ok = W5200_Add_To_Buff(Source, dst_ptr, size, 1);
		Source += size;
		size = Length - size;
		dst_ptr = S->TX_StartAddress;
		Ok &= W5200_Add_To_Buff(Source, dst_ptr, size, 1);
	}
	else
	{
		Ok = W5200_Add_To_Buff(Source, dst_ptr, Length, 1);
	}
	S->TX_WR += Length;
	size = SWAP16(S->TX_WR);
	Ok &= W5200_Add_To_Buff((uint8_t*)&size, Sn_TX_WR0(s), 2, 1);
	return Ok;
}

uint8_t W5200_Send_CallBack(SOCKET s, CallBack_Typedef _CallBack)
{
	uint16_t Length = WBuffer_Ptr - WBuffer;
	uint8_t Ok;
	if(_CallBack)
		Socket_Temp = s;
	CallBack = _CallBack;
	Ok = ((Length)&&(Length <= sizeof(WBuffer)));
	W5200_Status.Ready = !Ok;
	if(Ok)
		Eth_RW_SPI(WBuffer, WBuffer_Ptr - WBuffer);
	WBuffer_Ptr = WBuffer;
	return Ok;
}

/**
@brief	This function set the transmit & receive buffer size as per the channels is used
Note for TMSR and RMSR bits are as follows\n
bit 1-0 : memory size of channel #0 \n
bit 3-2 : memory size of channel #1 \n
bit 5-4 : memory size of channel #2 \n
bit 7-6 : memory size of channel #3 \n
bit 9-8 : memory size of channel #4 \n
bit 11-10 : memory size of channel #5 \n
bit 12-12 : memory size of channel #6 \n
bit 15-14 : memory size of channel #7 \n
Maximum memory size for Tx, Rx in the W5200 is 16K Bytes,\n
In the range of 16KBytes, the memory size could be allocated dynamically by each channel.\n
Be attentive to sum of memory size shouldn't exceed 8Kbytes\n
and to data transmission and receiption from non-allocated channel may cause some problems.\n
If the 16KBytes memory is already  assigned to centain channel, \n
other 3 channels couldn't be used, for there's no available memory.\n
If two 4KBytes memory are assigned to two each channels, \n
other 2 channels couldn't be used, for there's no available memory.\n
*/

uint8_t W5200_Socket_Init(const uint8_t * tx_size, const uint8_t * rx_size)
{
	int8_t i;
	uint8_t Ok = 1;
	uint16_t RX_Address, TX_Address;
	TX_Address = (__DEF_IINCHIP_MAP_TXBUF__);		/* Set base address of Tx memory for channel #0 */
	RX_Address = (__DEF_IINCHIP_MAP_RXBUF__);	  /* Set base address of Rx memory for channel #0 */
  for (i = 0 ; i < MAX_SOCK_NUM; i++)       // Set the size, masking and base address of Tx & Rx memory by each channel
	{
		Ok &= W5200_Add_To_Buff_Byte_Const(Sn_TXMEM_SIZE(i), tx_size[i]);
		Ok &= W5200_Add_To_Buff_Byte_Const(Sn_RXMEM_SIZE(i), rx_size[i]);
		Ok &= W5200_Add_To_Buff_Byte_Const(Sn_IR(i), 0xFF);
		Ok &= W5200_Add_To_Buff_Byte_Const(Sn_IMR(i), 0x1F);
		Socket[i].RX_StartAddress = RX_Address;
		Socket[i].TX_StartAddress = TX_Address;
		Socket[i].RX_Size = (uint16_t)rx_size[i] << 10;
		Socket[i].TX_Size = (uint16_t)tx_size[i] << 10;
		Socket[i].RX_Mask = Socket[i].RX_Size -1;
		Socket[i].TX_Mask = Socket[i].TX_Size -1;
		TX_Address += Socket[i].TX_Size;
		RX_Address += Socket[i].RX_Size;
	}
	return Ok;
}

void Init_W5200(uint8_t* MACAddress, void (*_IPConflict_Handler)(void))
{
	IPConflict_Handler = _IPConflict_Handler;
	Init_W5200Driver();
	W5200_Timer = System_Timer_Add(tm_Once, SYSTEM_TIMER_FREQUENCY * 0.1);
	if (MACAddress != MAC)
		memcpy(MAC, MACAddress, 6);
	W5200_Status.State = ws_Reset;
	W5200_Status.Ready = 0;
}

const uint8_t TX_Size[8] = {2, 2, 2, 2, 2, 2, 2, 2};
const uint8_t RX_Size[8] = {2, 2, 2, 2, 2, 2, 2, 2};

uint8_t W5200_Add_Read_Data(SOCKET s, uint8_t* Buffer, uint16_t Length) //Читаем из области RX данных сокетов
{
	uint8_t Ok = 1;
	uint16_t size;
	uint16_t src_mask;
	uint16_t src_ptr;
	src_mask = (Socket[s].RX_RD & Socket[s].RX_Mask);
	src_ptr = src_mask  | Socket[s].RX_StartAddress;
	CallBack_Param.Buffers[0].Address = Buffer;
	CallBack_Param.Buffers[0].Length = Length;
	CallBack_Param.Buffers[1].Address = WBuffer_Ptr + 4;
	if((src_mask + Length) > Socket[s].RX_Size) 
	{
		CallBack_Param.Count = 2;
		size = Socket[s].RX_Size - src_mask;
		CallBack_Param.Buffers[1].Length = size;
		Ok &= W5200_Add_To_Buff(0, src_ptr, size, 0);
		size = Length - size;
		CallBack_Param.Buffers[2].Address = WBuffer_Ptr + 4;
		CallBack_Param.Buffers[2].Length = size;
		Ok &= W5200_Add_To_Buff(0, Socket[s].RX_StartAddress, size , 0);
	}
	else
	{
		CallBack_Param.Count = 1;
		CallBack_Param.Buffers[1].Length = Length;
		Ok &= W5200_Add_To_Buff(0, src_ptr, Length, 0);
	}
	Socket[s].RX_RD += Length;
	return Ok;
}

uint16_t W5200_Copy_Receive_Data(void) //Склеиваем принятые данные и копируем в выделенный буфер
{
	uint8_t* ptr = CallBack_Param.Buffers[0].Address;
	uint16_t Length1 = CallBack_Param.Buffers[1].Length;
	switch (CallBack_Param.Count)
	{
		case 2:
			memcpy(ptr + Length1, CallBack_Param.Buffers[2].Address, CallBack_Param.Buffers[2].Length);
		case 1:
			memcpy(ptr, CallBack_Param.Buffers[1].Address, Length1);
			return CallBack_Param.Buffers[0].Length;
		default:
			break;
	}
	return 0;
}

uint8_t W5200_Add_Header_Read(SOCKET s) //Запрос на считывание заголовков
{
	uint8_t Ok = 1;
	switch(Socket[s].Protocol)
	{
		case Sn_MR_UDP:
			Ok &= W5200_Add_Read_Data(s, (uint8_t*)&Header, 8);
			break;
		case Sn_MR_IPRAW:
			Ok &= W5200_Add_Read_Data(s, (uint8_t*)&Header, 6);
			break;
		case Sn_MR_MACRAW:
			Ok &= W5200_Add_Read_Data(s, (uint8_t*)&Header, 2);
			break;
		default:
			CallBack_Param.Count = 0;
			break;
	}
	return Ok;
}

void Body_Callback(SOCKET s)
{
	W5200_Copy_Receive_Data();
	if(Socket_CallBack[s])
	{
		Socket_CallBack[s](&Header, RBuffer, &Socket[s].Param);
		Socket[s].Param.Event.Receive = 0;
	}
}

void Header_Callback(SOCKET s)
{
	uint16_t Length;
	W5200_Copy_Receive_Data();
	switch(Socket[s].Protocol)
	{
	case Sn_MR_UDP:
		Length = SWAP16(Header.UDP.LengthHL);
		break;
	case Sn_MR_IPRAW:
		Length = SWAP16(Header.IPRAW.LengthHL);
		break;
	case Sn_MR_MACRAW:
		Length = SWAP16(Header.MACRAW.LengthHL);
		break;
	case Sn_MR_TCP:
		Length = Socket[s].Param.RX_Filled_Size;
		Header.TCP.LengthHL = SWAP16(Length);
		break;
	default:
		while(1);
	}
	if(Length < 1600)
	{
		W5200_Add_Read_Data(s, RBuffer, Length);
		W5200_Add_Set_Sn_RX_RD(s, Socket[s].RX_RD);
		W5200_Add_To_Buff_Byte_Const(Sn_CR(s), Sn_CR_RECV); // run sockinit Sn_CR
		W5200_Send_CallBack(s, Body_Callback);
	}
	else
	{
		while(1);//Закрыть сокет.
	}
}

void Interrupt_Callback(SOCKET s)
{
	static uint8_t Socket_Interrupt;
	uint8_t i;
	uint8_t Ir = *CallBack_Param.Buffers[0].Address;				// Читаем регистры прерываний из буфера
	uint8_t Sn_Ir;
	uint8_t Sn_Sr;
	uint16_t Sn_RSR = 0;
	uint16_t Sn_FSR = 0;
	uint16_t Sn_TX_RD;
	uint16_t Sn_TX_WR;
	static uint8_t Connected = 0; //errata
	if(Ir & 0x80)
	{
		W5200_Add_Set_IR(0x80);
		if(IPConflict_Handler)
			IPConflict_Handler();
	}
	for(i = 0; i < MAX_SOCK_NUM; i++)
	{
		Socket_Interrupt = (Socket_Interrupt + 1) % MAX_SOCK_NUM;
		if(Socket[Socket_Interrupt].Param.Event.Open)
		{
			Sn_Ir = *CallBack_Param.Buffers[(Socket_Interrupt << 2) + 1].Address;
			Sn_Sr = *CallBack_Param.Buffers[(Socket_Interrupt << 2) + 2].Address;
			if(Sn_Ir)
			{
				*(uint8_t*)&Socket[Socket_Interrupt].Param.Event = (*(uint8_t*)&Socket[Socket_Interrupt].Param.Event & 0xE0) | (Sn_Ir & 0x1F);
				Socket[Socket_Interrupt].Param.Status = Sn_Sr;
				if((Connecting & (1 << i)) && (Sn_Ir & (Sn_IR_CON | Sn_IR_TIMEOUT)))
				{
					Connecting &= ~(1 << i);
					Connected = 1;
				}
				if(!Connecting && 
					(Connected ||((Sn_Ir & Sn_IR_SEND_OK) && (Socket[Socket_Interrupt].Protocol == Sn_MR_UDP || Socket[Socket_Interrupt].Protocol == Sn_MR_IPRAW))))		//Очищаем согласно Errata
				{
					W5200_Add_Clear_SUBR();
					Connected = 0;
				}
				if(Socket[Socket_Interrupt].Protocol == Sn_MR_TCP)
				{
					Sn_FSR = SWAP16(*(uint16_t*)CallBack_Param.Buffers[(Socket_Interrupt << 2) + 3].Address);
					Sn_TX_RD = SWAP16(*(uint16_t*)(CallBack_Param.Buffers[(Socket_Interrupt << 2) + 3].Address + 2));
					Sn_TX_WR = SWAP16(*(uint16_t*)(CallBack_Param.Buffers[(Socket_Interrupt << 2) + 3].Address + 4));
					Sn_RSR = SWAP16(*(uint16_t*)(CallBack_Param.Buffers[(Socket_Interrupt << 2) + 3].Address + 6));
					Socket[Socket_Interrupt].Param.RX_Filled_Size = Sn_RSR;
					Socket[Socket_Interrupt].Param.TX_Free_Size = Sn_FSR;
					Socket[Socket_Interrupt].TX_WR = Sn_TX_WR;
				}
				if(Sn_Ir & Sn_IR_RECV)
				{
					W5200_Add_Set_Sn_IR(Socket_Interrupt, Sn_IR_RECV);
					W5200_Add_Header_Read(Socket_Interrupt);
					if(Socket[Socket_Interrupt].Protocol != Sn_MR_TCP)
						W5200_Send_CallBack(Socket_Interrupt, Header_Callback);
					else
						Header_Callback(Socket_Interrupt);
					return;
				}
				W5200_Add_Set_Sn_IR(Socket_Interrupt, Sn_Ir & (~Sn_IR_RECV));
				if((Sn_Ir & Sn_IR_SEND_OK) && (Sn_TX_WR != Sn_TX_RD) && Socket[Socket_Interrupt].Protocol == Sn_MR_TCP)	//errata
					W5200_Add_To_Buff_Byte_Const(Sn_CR(Socket_Interrupt), Sn_CR_SEND);
				else
					if(Socket_CallBack[Socket_Interrupt])
					{
						Socket_CallBack[Socket_Interrupt](0, 0, &Socket[Socket_Interrupt].Param);
						*(uint8_t*)&Socket[Socket_Interrupt].Param.Event &= 0xE0;
					}
				W5200_Send_CallBack(0, 0);
				return;
			}
		}
	}
}

void W5200(void)
{
	uint8_t i;
	static CallBack_Typedef CallBack_Temp = 0;
	static uint8_t Socket_Current = 0;
	W5200_Status.Ready = 0;
	switch(W5200_Status.State)
	{
		case ws_Reset:
			Eth_Reset(0); //Сброс Ножка RESET
			memset(&Network, 0, sizeof(Network));
			memset(&Socket, 0, sizeof(Socket));
			for(i = 0; i < MAX_SOCK_NUM; i++)
				Socket[i].Param.Index = i;
			System_Timer_Reset_Status(W5200_Timer);
			System_Timer_Set_Compare(W5200_Timer, SYSTEM_TIMER_FREQUENCY * 0.01);
			System_Timer_Set_Mode(W5200_Timer, tm_Once);
			W5200_Status.State = ws_Wait_Reset;
			break;
		case ws_Wait_Reset:
			if(System_Timer_Get_Status(W5200_Timer))
			{
				Eth_Reset(1); //Подняли ножку RESET
				W5200_Status.State = ws_Setup;
				System_Timer_Reset_Status(W5200_Timer);
				System_Timer_Set_Compare(W5200_Timer, SYSTEM_TIMER_FREQUENCY * 2.5);
				System_Timer_Set_Mode(W5200_Timer, tm_Once);
			}
			break;
		case ws_Setup:
			if(System_Timer_Get_Status(W5200_Timer))
			{
				W5200_Add_Reset();
				W5200_Add_To_Buff(0, MR, 1, 0);
				W5200_Add_Set_SHAR(MAC);
				W5200_Add_Set_SIPR(Network.IP);
				W5200_Add_Set_GAR(Network.Gateway);
				W5200_Add_Clear_SUBR();
				W5200_Socket_Init(TX_Size, RX_Size);
				W5200_Add_Set_IMR2(0xFF);
				W5200_Add_Set_IMR(0x80);
				W5200_Send_CallBack(0, 0);
				W5200_Status.State = ws_Wait;
			}
			break;
		case ws_Wait:
			if(!Eth_Busy())
				W5200_Status.State = ws_Work;
			else
				break;
		case ws_Work:
			if(!Eth_Busy())
			{
				if (CallBack)
				{
					CallBack_Temp = CallBack;
					CallBack = 0;
					CallBack_Temp(Socket_Temp);
				}
				else
				{
					if(Eth_GetInterrupt())
					{
						W5200_Add_Get_IR(&CallBack_Param.Buffers[0].Address);
						for(i = 0; i < MAX_SOCK_NUM; i++)
						{
							if(Socket[i].Param.Event.Open)
							{
								W5200_Add_Get_Sn_IR(i, &CallBack_Param.Buffers[(i << 2) + 1].Address);
								W5200_Add_Get_Sn_SR(i, &CallBack_Param.Buffers[(i << 2) + 2].Address);
								if(Socket[i].Protocol == Sn_MR_TCP)
								{
									CallBack_Param.Buffers[(i << 2) + 3].Address = WBuffer_Ptr + 4; //TX_FSR, TX_RD, TX_WR, RX_RSR
									W5200_Add_To_Buff(0, Sn_TX_FSR0(i), 8, 0);
								}
							}
						}
						W5200_Send_CallBack(Socket_Current, Interrupt_Callback); //Читаем регистры прерываний и идем на обработку всех прерываний
					}
					else
					{
						//Вызов обработки плановых задач.
						W5200_Status.Ready = 1;
						for(i = 0; i < MAX_SOCK_NUM; i++)
						{
							Socket_Current = (Socket_Current + 1) % MAX_SOCK_NUM;
							if(Socket_CallBack[Socket_Current])
							{
								Socket[Socket_Current].Param.Event.Request = 1;
								Socket_CallBack[Socket_Current](&Header, RBuffer, &Socket[Socket_Current].Param);
								Socket[Socket_Current].Param.Event.Request = 0;
								if(!W5200_Status.Ready)
									return;
							}
						}		
					}
				}
			}
			break;
	}
}

void W5200_Reset(void)
{
	W5200_Status.State = ws_Reset;
}
