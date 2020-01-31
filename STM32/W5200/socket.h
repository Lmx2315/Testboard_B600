#ifndef	_SOCKET_H_
#define	_SOCKET_H_

#include <stdint.h>

#define	MAX_SOCK_NUM				8	/**< Maxmium number of SocketOpen  */

#define SOCK_CLOSED					0x00		/**< closed */
#define SOCK_INIT 					0x13		/**< init state */
#define SOCK_LISTEN					0x14		/**< listen state */
#define SOCK_SYNSENT	   		0x15		/**< connection state */
#define SOCK_SYNRECV		   	0x16		/**< connection state */
#define SOCK_ESTABLISHED		0x17		/**< success to connect */
#define SOCK_FIN_WAIT				0x18		/**< closing state */
#define SOCK_CLOSING		   	0x1A		/**< closing state */
#define SOCK_TIME_WAIT			0x1B		/**< closing state */
#define SOCK_CLOSE_WAIT			0x1C		/**< closing state */
#define SOCK_LAST_ACK				0x1D		/**< closing state */
#define SOCK_UDP						0x22		/**< udp SocketOpen */
#define SOCK_IPRAW					0x32		/**< ip raw mode SocketOpen */
#define SOCK_MACRAW					0x42		/**< mac raw mode SocketOpen */
#define SOCK_PPPOE					0x5F		/**< pppoe SocketOpen */

/* Sn_MR values */
#define Sn_MR_CLOSE					0x00		/**< unused SocketOpen */
#define Sn_MR_TCP						0x01		/**< TCP */
#define Sn_MR_UDP						0x02		/**< UDP */
#define Sn_MR_IPRAW	        0x03		/**< IP LAYER RAW SOCK */
#define Sn_MR_MACRAW				0x04		/**< MAC LAYER RAW SOCK */
#define Sn_MR_PPPOE					0x05		/**< PPPoE */
#define Sn_MR_ND						0x20		/**< No Delayed Ack(TCP) flag */
#define Sn_MR_MULTI					0x80		/**< support multicating */

static __inline uint16_t SWAP16(uint16_t half)
{
	uint8_t bytes[2];
	bytes[0] = half >> 8;
	bytes[1] = half;
	return *(uint16_t*)bytes;
}

static __inline uint32_t SWAP32(uint32_t word)
{
	uint8_t bytes[4];
	bytes[0] = ((uint8_t*)&word)[3];
	bytes[1] = ((uint8_t*)&word)[2];
	bytes[2] = ((uint8_t*)&word)[1];
	bytes[3] = ((uint8_t*)&word)[0];
	return *(uint32_t*)bytes;
}

typedef int8_t SOCKET;

typedef enum { false, true } bool;

typedef __packed struct
{
	uint8_t IP[4];
	uint16_t PortHL;
	uint16_t LengthHL;
}UDP_Header_Typedef;

typedef __packed struct
{
	uint8_t IP[4];
	uint16_t LengthHL;
}IPRAW_Header_Typedef;

typedef __packed struct
{
	uint16_t LengthHL;
}MACRAW_Header_Typedef;

typedef __packed union
{
	UDP_Header_Typedef UDP;
	IPRAW_Header_Typedef IPRAW;
	MACRAW_Header_Typedef MACRAW;
	MACRAW_Header_Typedef TCP;
}Header_Typedef;

typedef __packed struct
{
	unsigned Connect: 1;
	unsigned Disconnect: 1;
	unsigned Receive: 1;
	unsigned TimeOut: 1;
	unsigned Send_OK: 1;
	unsigned Open:1;
	unsigned Request: 1;
	unsigned :1;
}Socket_Event_Typedef;

typedef __packed struct
{
	Socket_Event_Typedef Event;
	uint8_t Status;
	uint8_t Index;
	uint16_t RX_Filled_Size;
	uint16_t TX_Free_Size;
}Socket_Param_Typedef;

typedef struct
{
	uint8_t IP[4];
	uint8_t Mask[4];
	uint8_t Gateway[4];
}Network_Typedef;

typedef void (*Socket_Callback_Typedef)(Header_Typedef* Header, uint8_t* Body, Socket_Param_Typedef* Param);
typedef void (*CallBack_Typedef)(SOCKET s);

//#include "w5200.h"

extern uint8_t Socket_Init(SOCKET s, Socket_Callback_Typedef Callback);
extern uint8_t Socket_Open(SOCKET s, uint8_t protocol, uint16_t port, uint8_t flag); // Opens a SocketOpen(TCP or UDP or IP_RAW mode)
extern uint8_t Socket_UDP_Send(SOCKET s, const uint8_t* Source, uint16_t Length, uint8_t* IP, uint16_t Port); // Send data (UDP/IP RAW)
extern uint8_t Socket_Close(SOCKET s); // Close Socket
extern uint8_t Socket_Listen(SOCKET s);	// Establish TCP connection (Passive connection)
extern uint8_t Socket_Connect(SOCKET s, uint8_t * addr, uint16_t port); // Establish TCP connection (Active connection)
extern uint8_t Socket_Disconnect(SOCKET s); // disconnect the connection
extern uint16_t Socket_TCP_Send(SOCKET s, const uint8_t * Source, uint32_t Length, bool Retry);
extern uint8_t W5200_Set_Network(Network_Typedef* Network);
extern uint8_t W5200_Send_CallBack(SOCKET s, CallBack_Typedef _CallBack);

//extern uint16_t igmpsend(SOCKET s, const uint8_t * buf, uint16_t len);
#endif
/* _SOCKET_H_ */
