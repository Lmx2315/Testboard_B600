/*
@file		w5200.h
*/
#ifndef	_W5200_H_
#define	_W5200_H_

#include <stdint.h>

#pragma anon_unions

#define COMMON_BASE								0x0000

#define MR												(COMMON_BASE + 0x0000) 
/**
 @brief Gateway IP Register address
 */
#define GAR0											(COMMON_BASE + 0x0001)
/**
 @brief Subnet mask Register address
 */
#define SUBR0											(COMMON_BASE + 0x0005)
/**
 @brief Source MAC Register address
 */
#define SHAR0											(COMMON_BASE + 0x0009)
/**
 @brief Source IP Register address
 */
#define SIPR0											(COMMON_BASE + 0x000F)
/**
 @brief Interrupt Register
 */
#define IR												(COMMON_BASE + 0x0015)
/**
 @brief Socket Interrupt Register
 */
#define IR2												(COMMON_BASE + 0x0034) 
/**
 @brief PHY Status Register
 */
#define PHY												(COMMON_BASE + 0x0035)
/**
 @brief Interrupt mask register
 */
#define _IMR											(COMMON_BASE + 0x0036)
/**
 @brief Socket Interrupt Mask Register
 */
#define IMR2											(COMMON_BASE + 0x0016)
/**
 @brief Timeout register address( 1 is 100us )
 */
#define RTR												(COMMON_BASE + 0x0017)
/**
 @brief Retry count reigster
 */
#define _RCR											(COMMON_BASE + 0x0019)
/**
 @brief Authentication type register address in PPPoE mode
 */
#define PATR0											(COMMON_BASE + 0x001C)
#define PPPALGO										(COMMON_BASE + 0x001E)
/**
 @briefPPP LCP Request Timer register  in PPPoE mode
 */
#define PTIMER										(COMMON_BASE + 0x0028)
/**
 @brief PPP LCP Magic number register  in PPPoE mode
 */
#define PMAGIC										(COMMON_BASE + 0x0029)
/**
 @brief chip version register address
 */
#define VERSIONR									(COMMON_BASE + 0x001F)   
/**
 @brief Unreachable IP register address in UDP mode
 */
#define UIPR0											(COMMON_BASE + 0x002A)
/**
 @brief Unreachable Port register address in UDP mode
 */
#define UPORT0										(COMMON_BASE + 0x002E)
/**
 @brief set Interrupt low level timer register address
 */
#define INTLEVEL0									(COMMON_BASE + 0x0030)
#define INTLEVEL1									(COMMON_BASE + 0x0031)
/**
 @brief SocketOpen register
*/
#define CH_BASE										(COMMON_BASE + 0x4000)
/**
 @brief	size of each channel register map
 */
#define CH_SIZE										0x0100
/**
 @brief SocketOpen Mode register
 */
#define Sn_MR(ch)									(CH_BASE + ch * CH_SIZE + 0x0000)
/**
 @brief channel Sn_CR register
 */
#define Sn_CR(ch)									(CH_BASE + ch * CH_SIZE + 0x0001)
/**
 @brief channel interrupt register
 */
#define Sn_IR(ch)									(CH_BASE + ch * CH_SIZE + 0x0002)
/**
 @brief channel status register
 */
#define Sn_SR(ch)									(CH_BASE + ch * CH_SIZE + 0x0003)
/**
 @brief source port register
 */
#define Sn_PORT0(ch)							(CH_BASE + ch * CH_SIZE + 0x0004)
/**
 @brief Peer MAC register address
 */
#define Sn_DHAR0(ch)							(CH_BASE + ch * CH_SIZE + 0x0006)
/**
 @brief Peer IP register address
 */
#define Sn_DIPR0(ch)							(CH_BASE + ch * CH_SIZE + 0x000C)
/**
 @brief Peer port register address
 */
#define Sn_DPORT0(ch)							(CH_BASE + ch * CH_SIZE + 0x0010)
/**
 @brief Maximum Segment Size(Sn_MSSR0) register address
 */
#define Sn_MSSR0(ch)							(CH_BASE + ch * CH_SIZE + 0x0012)
/**
 @brief Protocol of IP Header field register in IP raw mode
 */
#define Sn_PROTO(ch)							(CH_BASE + ch * CH_SIZE + 0x0014)

/** 
 @brief IP Type of Service(TOS) Register 
 */
#define Sn_TOS(ch)								(CH_BASE + ch * CH_SIZE + 0x0015)
/**
 @brief IP Time to live(TTL) Register 
 */
#define Sn_TTL(ch)								(CH_BASE + ch * CH_SIZE + 0x0016)
/**
 @brief Receive memory size reigster
 */
#define Sn_RXMEM_SIZE(ch)	        (CH_BASE + ch * CH_SIZE + 0x001E)
/**
 @brief Transmit memory size reigster
 */
#define Sn_TXMEM_SIZE(ch)	        (CH_BASE + ch * CH_SIZE + 0x001F)
/**
 @brief Transmit free memory size register
 */
#define Sn_TX_FSR0(ch)		        (CH_BASE + ch * CH_SIZE + 0x0020)
/**
 @brief Transmit memory read pointer register address
 */
#define Sn_TX_RD0(ch)							(CH_BASE + ch * CH_SIZE + 0x0022)
/**
 @brief Transmit memory write pointer register address
 */
#define Sn_TX_WR0(ch)							(CH_BASE + ch * CH_SIZE + 0x0024)
/**
 @brief Received data size register
 */
#define Sn_RX_RSR0(ch)		        (CH_BASE + ch * CH_SIZE + 0x0026)
/**
 @brief Read point of Receive memory
 */
#define Sn_RX_RD0(ch)							(CH_BASE + ch * CH_SIZE + 0x0028)
/**
 @brief Write point of Receive memory
 */
#define Sn_RX_WR0(ch)							(CH_BASE + ch * CH_SIZE + 0x002A)
/**
 @brief SocketOpen interrupt mask register
 */
#define Sn_IMR(ch)								(CH_BASE + ch * CH_SIZE + 0x002C)
/**
 @brief frag field value in IP header register
 */
#define Sn_FRAG(ch)								(CH_BASE + ch * CH_SIZE + 0x002D)
/**
 @brief Keep Timer register
 */
#define Sn_KEEP_TIMER(ch)					(CH_BASE + ch * CH_SIZE + 0x002F)

/* MODE register values */
#define MR_RST				0x80 /**< reset */
#define MR_WOL				0x20 /**< Wake on Lan */
#define MR_PB					0x10 /**< ping block */
#define MR_PPPOE			0x08 /**< enable pppoe */
#define MR_LB  		    0x04 /**< little or big endian selector in indirect mode */
#define MR_AI					0x02 /**< auto-increment in indirect mode */
#define MR_IND				0x01 /**< enable indirect mode */

/* IR register values */
#define IR_CONFLICT	        0x80 /**< check ip confict */
#define IR_UNREACH	        0x40 /**< get the destination unreachable message in UDP sending */
#define IR_PPPoE						0x20 /**< get the PPPoE SocketClose message */
#define IR_MAGIC						0x10 /**< get the magic packet interrupt */
#define IR_SOCK(ch)	        (0x01 << ch) /**< check SocketOpen interrupt */

/* Sn_CR values */
#define Sn_CR_OPEN					0x01		/**< initialize or open SocketOpen */
#define Sn_CR_LISTEN				0x02		/**< wait connection request in tcp mode(Server mode) */
#define Sn_CR_CONNECT				0x04		/**< send connection request in tcp mode(Client mode) */
#define Sn_CR_DISCON				0x08		/**< send closing reqeuset in tcp mode */
#define Sn_CR_CLOSE					0x10		/**< SocketClose SocketOpen */
#define Sn_CR_SEND					0x20		/**< update txbuf pointer, send data */
#define Sn_CR_SEND_MAC			0x21		/**< send data with MAC address, so without ARP process */
#define Sn_CR_SEND_KEEP			0x22		/**<  send keep alive message */
#define Sn_CR_RECV					0x40		/**< update rxbuf pointer, recv data */

#ifdef __DEF_IINCHIP_PPP__
	#define Sn_CR_PCON				0x23		 
	#define Sn_CR_PDISCON			0x24		 
	#define Sn_CR_PCR					0x25		 
	#define Sn_CR_PCN					0x26		
	#define Sn_CR_PCJ					0x27		
#endif

/* Sn_IR values */
#ifdef __DEF_IINCHIP_PPP__
	#define Sn_IR_PRECV				0x80		
	#define Sn_IR_PFAIL				0x40		
	#define Sn_IR_PNEXT				0x20		
#endif
#define Sn_IR_SEND_OK				0x10		/**< complete sending */
#define Sn_IR_TIMEOUT				0x08		/**< assert timeout */
#define Sn_IR_RECV					0x04		/**< receiving data */
#define Sn_IR_DISCON				0x02		/**< closed SocketOpen */
#define Sn_IR_CON						0x01		/**< established connection */

/* IP PROTOCOL */
#define IPPROTO_IP          0           /**< Dummy for IP */
#define IPPROTO_ICMP        1           /**< Control message protocol */
#define IPPROTO_IGMP        2           /**< Internet group management protocol */
#define IPPROTO_GGP         3           /**< Gateway^2 (deprecated) */
#define IPPROTO_TCP         6           /**< TCP */
#define IPPROTO_PUP         12          /**< PUP */
#define IPPROTO_UDP         17          /**< UDP */
#define IPPROTO_IDP         22          /**< XNS idp */
#define IPPROTO_ND          77          /**< UNOFFICIAL net disk protocol */
#define IPPROTO_RAW         255         /**< Raw IP packet */

#define __DEF_IINCHIP_MAP_TXBUF__ 			(COMMON_BASE + 0x8000) /* Internal Tx buffer address of the iinchip */
#define __DEF_IINCHIP_MAP_RXBUF__ 			(COMMON_BASE + 0xC000) /* Internal Rx buffer address of the iinchip */

#include "socket.h"

typedef __packed struct
{
	uint8_t Protocol;
	uint8_t flag;
	uint16_t Port;
	uint16_t RX_Size;
	uint16_t TX_Size;
	uint16_t RX_Mask;
	uint16_t TX_Mask;
	uint16_t RX_StartAddress;
	uint16_t TX_StartAddress;
	uint16_t TX_WR;
	uint16_t RX_RD;
	Socket_Param_Typedef Param;
}Socket_Typedef;

typedef struct
{
	uint8_t* Address;
	uint16_t Length;
}Buffer_Struct_Typedef;

typedef struct
{
	uint32_t Count;
	Buffer_Struct_Typedef Buffers[(MAX_SOCK_NUM + 2) * 4];
}Call_Back_Struct_Typedef;

/*********************************************************
* iinchip access function
*********************************************************/

extern void saveSUBR(uint8_t * addr);
extern void getSUBR(uint8_t * addr);
extern uint8_t W5200_Add_Clear_SUBR(void);
extern uint8_t W5200_Add_Set_MR(uint8_t val);
extern uint8_t W5200_Add_Set_IMR2(uint8_t mask);
extern uint8_t W5200_Add_Set_GAR(uint8_t * addr);
extern uint8_t W5200_Add_Set_SUBR(void);
extern uint8_t W5200_Add_Set_IMR(uint8_t mask);
extern uint8_t W5200_Add_Set_IR(uint8_t mask);
extern uint8_t W5200_Add_Set_SHAR(const uint8_t * addr);
extern uint8_t W5200_Add_Set_SIPR(uint8_t * addr);
extern uint8_t W5200_Add_Set_MSS(SOCKET s, uint16_t Sn_MSSR0); // set maximum segment size
extern uint8_t W5200_Add_Set_PROTO(SOCKET s, uint8_t proto); // set IP Protocol value using IP-Raw mode
extern uint8_t W5200_Add_Set_Sn_TTL(SOCKET s, uint8_t ttl);
extern uint8_t W5200_Add_Set_RTR(uint16_t Timeout);// set retry duration for data transmission, connection, closing ...
extern uint8_t W5200_Add_Set_RCR(uint8_t Retry); // set retry count (above the value, assert timeout interrupt)
extern uint8_t W5200_Add_Get_GAR(uint8_t **addr);
extern uint8_t W5200_Add_Get_SHAR(uint8_t **addr);
extern uint8_t W5200_Add_Get_SIPR(uint8_t **addr);
extern uint8_t W5200_Add_Get_IMR2(uint8_t **Imr2);
extern uint8_t W5200_Add_Get_IR2(uint8_t **Ir2);
extern uint8_t W5200_Add_Get_IR(uint8_t **Ir);
extern uint8_t W5200_Add_Get_PHY(uint8_t** Phy);
extern uint8_t W5200_Add_Get_Sn_SR(SOCKET s, uint8_t** Sn_SR); // get SocketOpen status
extern uint8_t W5200_Add_Get_Sn_TX_FSR(SOCKET s, uint8_t** Sn_TX_FSR); // get SocketOpen TX free buf size
extern uint8_t W5200_Add_Get_Sn_RX_RSR(SOCKET s, uint8_t** Sn_RX_RSR); // get SocketOpen RX recv buf size
extern uint8_t W5200_Add_Get_Sn_RX_RD(SOCKET s, uint8_t** Sn_RX_RD);
extern uint8_t W5200_Add_Get_Sn_TX_WR(SOCKET s, uint8_t** Sn_TX_WR);
extern uint8_t W5200_Add_Get_Sn_IR(SOCKET s, uint8_t** Sn_IR); // get SocketOpen interrupt status
extern uint8_t W5200_Add_Res_Sn_IR(SOCKET s, uint8_t flag); // reset SocketOpen interrupt status
extern uint8_t W5200_Add_To_Buff(const uint8_t* Source, uint16_t addr, uint16_t len, uint8_t Write);
extern uint8_t W5200_Add_To_Buff_Byte_Const(uint16_t addr, const uint8_t Byte);
extern uint8_t W5200_Add_Write_Data(SOCKET s, const uint8_t *Source, uint16_t Length);
extern void Init_W5200(uint8_t* MACAddress, void (*_IPConflict_Handler)(void));
extern void W5200_Reset(void);
extern uint8_t W5200_Send_CallBack(SOCKET s, CallBack_Typedef _CallBack);
extern void W5200(void);

#endif
