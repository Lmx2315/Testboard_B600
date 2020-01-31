#include "global_var.h"

// START ADDRESS REGISTERs
#define COMMON_BASE 	  0x0000
#define Ip_address        0x000F
#define Gateway_address   0x0001
#define Mask_address      0x0006
#define Hard_address      0x0010
#define Sn_MR_address     0x4000  //Socket n-th-th Mode Register [R/W]
#define Sn_CR_address     0x4001  //Socket n-th Command Register [R/W] [0x4001
#define Sn_IR_address     0x4002  //Socket n-th Interrupt Register [R] [0x4002+0x0n00]
#define Sn_SR_address     0x4003  //Socket n-th Status Register [R] [0x4003+0x0n00]
#define Sn_PORT_address   0x4004  //Socket  n-th Source  Port  Register [R/W]  [0x4004
#define Sn_DHAR_address   0x4006  //Socket n-th Destination Hardware Address Register [R/W]
#define Sn_DIPR_address   0x400C  //Socket  n-th Destination  IP  Address  Register R/W][0x400C
#define Sn_DPORT_address  0x4010  //Socket  n-th Destination  Port  Register[R/W][0x4010
#define Sn_MSS_address    0x4012  //Socket  n-th Maximum  Segment  Size  Register [R/W][0x4012
#define Sn_TOS_address    0x4015  //Socket n-th IP Type Of Service Register) [R/W] [0x4015
#define Sn_TTL_address    0x4016  //Socket n-th IP Time To Live Register) [R/W] [0x4016
#define Sn_RXMEM_SIZE_address 0x401E //Socket n-th RX Memory Size Register) [R/W] [0x401E
#define Sn_TXMEM_SIZE_address 0x401F //Socket n-th TX Memory size Register) [R/W][0x401F
#define Sn_TX_FSR_address 0x4020  //Socket  n-th TX  Free  Size  Register)  [R]  [0x4020
#define Sn_TX_RD_address  0x4022  //Socket  n-th TX  Read  Pointer  Register)  [R]  [0x4022
#define Sn_TX_WR_address  0x4024  //Socket  n-th TX  Write  Pointer  Register)  [R/W]  [0x4024
#define Sn_RX_RSR_address 0x4026  //SOCKET  n-th Received  Size  Register)  [R]  [0x4026
#define Sn_RX_RD_address  0x4028  //Socket n-th RX Read Pointer Register) [R/W] [0x4028
#define Sn_RX_WR_address  0x402A //Socket n-th RX Write Pointer Register)[R/W][(0x402A
#define Sn_IMR_address    0x402C  //Socket n-th Interrupt Mask Register)[R/W][0x402C
#define Sn_FRAG_address   0x402D  //Socket n-th Fragment Register)[R/W][0x402D
#define Sn_MR_UPD_aadress 0x4000  //This register sets up socket option or protocol type for each socket
#define Socet_receive     0xC000  // Base adress Socket 0 receive
#define Socket_transmit   0x8000  // Base adress Socket 0 transmit  
#define Sn_CR_Open        0x01
#define Sn_CR_Close       0x10
#define Sn_CR_Send        0x20
#define Sn_CR_Send_Mac    0x21
#define Sn_CR_Recv        0x40
#define Sn_CR_Open        0x01
#define WRITE_1Byte 0x8001
#define Read_1Byte  0x0001

//-------------------------------------------

#define PPP_OPTION_BUF_LEN 64	  
#define SOCK_CONFIG		2	// UDP
#define SOCK_DNS		2	// UDP
#define SOCK_DHCP		3	// UDP
#define KEEP_ALIVE_TIME	30	// 30sec

#define ON	1
#define OFF	0

#define HIGH		  1
#define LOW		      0
#define	MAX_SOCK_NUM  2	

#define MR			(COMMON_BASE + 0x0000) 

 //@brief Gateway IP Register address

#define GAR0	    (COMMON_BASE + 0x0001)
/**
 @brief Subnet mask Register address
 */
#define SUBR0	    (COMMON_BASE + 0x0005)
/**
 @brief Source MAC Register address
 */
#define SHAR0		(COMMON_BASE + 0x0009)
/**
 @brief Source IP Register address
 */
#define SIPR0		(COMMON_BASE + 0x000F)
/**
 @brief Interrupt Register
 */
#define IR			(COMMON_BASE + 0x0015)
/**
 @brief Socket Interrupt Register
 */
#define IR2			(COMMON_BASE + 0x0034) 
/**
 @brief PHY Status Register
 */
#define PHY			(COMMON_BASE + 0x0035)
/**
 @brief Interrupt mask register
 */
#define IMR			(COMMON_BASE + 0x0016)  // #define IMR				(COMMON_BASE + 0x0036)
/**
 @brief Socket Interrupt Mask Register
 */
#define IMR2		(COMMON_BASE + 0x0036)  //#define IMR2				(COMMON_BASE + 0x0016)
/**
 @brief Timeout register address( 1 is 100us )
 */
#define RTR			(COMMON_BASE + 0x0017)
/**
 @brief Retry count reigster
 */
#define RCR			(COMMON_BASE + 0x0019)
/**
 @brief Authentication type register address in PPPoE mode
 */
#define PATR0	    (COMMON_BASE + 0x001C)
#define PPPALGO     (COMMON_BASE + 0x001E)
/**
 @briefPPP LCP Request Timer register  in PPPoE mode
 */
#define PTIMER 	    (COMMON_BASE + 0x0028)
/**
 @brief PPP LCP Magic number register  in PPPoE mode
 */
#define PMAGIC 	    (COMMON_BASE + 0x0029)
/**
 @brief chip version register address
 */
#define VERSIONR	(COMMON_BASE + 0x001F)   
/**
 @brief Unreachable IP register address in UDP mode
 */
#define UIPR0		(COMMON_BASE + 0x002A)
/**
 @brief Unreachable Port register address in UDP mode
 */
#define UPORT0	    (COMMON_BASE + 0x002E)
/**
 @brief set Interrupt low level timer register address
 */
#define INTLEVEL0			(COMMON_BASE + 0x0030)
#define INTLEVEL1			(COMMON_BASE + 0x0031)
/**
 @brief socket register
*/
#define CH_BASE      (COMMON_BASE + 0x4000)
/**
 @brief	size of each channel register map
 */
#define CH_SIZE	       0x0100
/**
 @brief socket Mode register
 */
#define Sn_MR(ch)	    (CH_BASE + ch * CH_SIZE + 0x0000)
/**
 @brief channel Sn_CR register
 */
#define Sn_CR(ch)	    (CH_BASE + ch * CH_SIZE + 0x0001)
/**
 @brief channel interrupt register
 */
#define Sn_IR(ch)	    (CH_BASE + ch * CH_SIZE + 0x0002)
/**
 @brief channel status register
 */
#define Sn_SR(ch)	    (CH_BASE + ch * CH_SIZE + 0x0003)
/**
 @brief source port register
 */
#define Sn_PORT0(ch)	(CH_BASE + ch * CH_SIZE + 0x0004)
/**
 @brief Peer MAC register address
 */
#define Sn_DHAR0(ch)	(CH_BASE + ch * CH_SIZE + 0x0006)
/**
 @brief Peer IP register address
 */
#define Sn_DIPR0(ch)	(CH_BASE + ch * CH_SIZE + 0x000C)
/**
 @brief Peer port register address
 */
#define Sn_DPORT0(ch)	(CH_BASE + ch * CH_SIZE + 0x0010)
/**
 @brief Maximum Segment Size(Sn_MSSR0) register address
 */
#define Sn_MSSR0(ch)	(CH_BASE + ch * CH_SIZE + 0x0012)
/**
 @brief Protocol of IP Header field register in IP raw mode
 */
#define Sn_PROTO(ch)	(CH_BASE + ch * CH_SIZE + 0x0014)

/** 
 @brief IP Type of Service(TOS) Register 
 */
#define Sn_TOS(ch)		(CH_BASE + ch * CH_SIZE + 0x0015)
/**
 @brief IP Time to live(TTL) Register 
 */
#define Sn_TTL(ch)		(CH_BASE + ch * CH_SIZE + 0x0016)
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
#define Sn_TX_RD0(ch)			    (CH_BASE + ch * CH_SIZE + 0x0022)
/**
 @brief Transmit memory write pointer register address
 */
#define Sn_TX_WR0(ch)				(CH_BASE + ch * CH_SIZE + 0x0024)
/**
 @brief Received data size register
 */
#define Sn_RX_RSR0(ch)		        (CH_BASE + ch * CH_SIZE + 0x0026)
/**
 @brief Read point of Receive memory
 */
#define Sn_RX_RD0(ch)				(CH_BASE + ch * CH_SIZE + 0x0028)
/**
 @brief Write point of Receive memory
 */
#define Sn_RX_WR0(ch)				(CH_BASE + ch * CH_SIZE + 0x002A)
/**
 @brief socket interrupt mask register
 */
#define Sn_IMR(ch)					(CH_BASE + ch * CH_SIZE + 0x002C)
/**
 @brief frag field value in IP header register
 */
#define Sn_FRAG(ch)					(CH_BASE + ch * CH_SIZE + 0x002D)
/**
 @brief Keep Timer register
 */
#define Sn_KEEP_TIMER(ch)			(CH_BASE + ch * CH_SIZE + 0x002F)

/* MODE register values */
#define MR_RST			0x80 /**< reset */
#define MR_WOL			0x20 /**< Wake on Lan */
#define MR_PB			0x10 /**< ping block */
#define MR_PPPOE		0x08 /**< enable pppoe */
#define MR_LB  	        0x04 /**< little or big endian selector in indirect mode */
#define MR_AI			0x02 /**< auto-increment in indirect mode */
#define MR_IND			0x01 /**< enable indirect mode */

/* IR register values */
#define IR_CONFLICT	        0x80 /**< check ip confict */
#define IR_UNREACH	        0x40 /**< get the destination unreachable message in UDP sending */
#define IR_PPPoE    		0x20 /**< get the PPPoE close message */
#define IR_MAGIC	    	0x10 /**< get the magic packet interrupt */
#define IR_SOCK(ch)	       (0x01 << ch) /**< check socket interrupt */

/* Sn_MR values */
#define Sn_MR_CLOSE			0x00		/**< unused socket */
#define Sn_MR_TCP			0x01		/**< TCP */
#define Sn_MR_UDP			0x02		/**< UDP */
#define Sn_MR_IPRAW	        0x03		/**< IP LAYER RAW SOCK */
#define Sn_MR_MACRAW	    0x04		/**< MAC LAYER RAW SOCK */
#define Sn_MR_PPPOE			0x05		/**< PPPoE */
#define Sn_MR_ND			0x20		/**< No Delayed Ack(TCP) flag */
#define Sn_MR_MULTI			0x80		/**< support multicating */

/* Sn_CR values */
#define Sn_CR_OPEN			0x01		/**< initialize or open socket */
#define Sn_CR_LISTEN		0x02		/**< wait connection request in tcp mode(Server mode) */
#define Sn_CR_CONNECT	    0x04		/**< send connection request in tcp mode(Client mode) */
#define Sn_CR_DISCON		0x08		/**< send closing reqeuset in tcp mode */
#define Sn_CR_CLOSE			0x10		/**< close socket */
#define Sn_CR_SEND			0x20		/**< update txbuf pointer, send data */
#define Sn_CR_SEND_MAC	    0x21		/**< send data with MAC address, so without ARP process */
#define Sn_CR_SEND_KEEP     0x22		/**<  send keep alive message */
#define Sn_CR_RECV			0x40		/**< update rxbuf pointer, recv data */


#define Sn_CR_PCON		0x23		 
#define Sn_CR_PDISCON	0x24		 
#define Sn_CR_PCR		0x25		 
#define Sn_CR_PCN		0x26		
#define Sn_CR_PCJ		0x27		


/* Sn_IR values */

#define Sn_IR_PRECV		0x80		
#define Sn_IR_PFAIL		0x40		
#define Sn_IR_PNEXT		0x20		

#define Sn_IR_SEND_OK		0x10		/**< complete sending */
#define Sn_IR_TIMEOUT		0x08		/**< assert timeout */
#define Sn_IR_RECV			0x04		/**< receiving data */
#define Sn_IR_DISCON		0x02		/**< closed socket */
#define Sn_IR_CON			0x01		/**< established connection */

/* Sn_SR values */
#define SOCK_CLOSED				0x00		/**< closed */
#define SOCK_INIT 				0x13		/**< init state */
#define SOCK_LISTEN				0x14		/**< listen state */
#define SOCK_SYNSENT	   		0x15		/**< connection state */
#define SOCK_SYNRECV		   	0x16		/**< connection state */
#define SOCK_ESTABLISHED		0x17		/**< success to connect */
#define SOCK_FIN_WAIT			0x18		/**< closing state */
#define SOCK_CLOSING		   	0x1A		/**< closing state */
#define SOCK_TIME_WAIT			0x1B		/**< closing state */
#define SOCK_CLOSE_WAIT			0x1C		/**< closing state */
#define SOCK_LAST_ACK			0x1D		/**< closing state */
#define SOCK_UDP				0x22		/**< udp socket */
#define SOCK_IPRAW				0x32		/**< ip raw mode socket */
#define SOCK_MACRAW				0x42		/**< mac raw mode socket */
#define SOCK_PPPOE				0x5F		/**< pppoe socket */

/* IP PROTOCOL */
#define IPPROTO_IP              0           /**< Dummy for IP */
#define IPPROTO_ICMP            1           /**< Control message protocol */
#define IPPROTO_IGMP            2           /**< Internet group management protocol */
#define IPPROTO_GGP             3           /**< Gateway^2 (deprecated) */
#define IPPROTO_TCP             6           /**< TCP */
#define IPPROTO_PUP             12          /**< PUP */
#define IPPROTO_UDP             17          /**< UDP */
#define IPPROTO_IDP             22          /**< XNS idp */
#define IPPROTO_ND              77          /**< UNOFFICIAL net disk protocol */
#define IPPROTO_RAW             255         /**< Raw IP packet */

uint8 MAC[6]    ={0x64, 0xA2, 0x32, 0x01, 0x03,NB};//MAC Address
uint8 IP[4]     ={1, 3,  1,NB+60};//IP Address  
uint8 GateWay[4]={1, 3,  1, 254};// Gateway Address
uint8 SubNet[4] ={255, 255, 255,  0};//SubnetMask Address

uint8_t 	 Hard_reg [6]={0xe0,0x69,0x95,0x04,0xdf,0x96};     //SHAR Source Hardware Address Register
char		 Receive_DATA[16];
uint8_t		 Receive_IP[4]= {1, 3, 1, 151};//{192, 168, 10, 15};//IP Address;
uint8_t 	 Receive_Port_destination[2]={0, 23};
uint8_t 	 Receive_byte_size[2];
uint8_t 	 Rec_Flag;
uint16_t 	 size; 

//FOR TCP Client
//Configuration Network Information of TEST PC
u8  Dest_IP[4] = {1, 3, 1, 1}; //DST_IP Address 
u16 Dest_PORT = 23; //DST_IP port

#define PA4_0  GPIOA->BRR  = GPIO_Pin_4
#define PA4_1  GPIOA->BSRR = GPIO_Pin_4  
#define CS_WIZ_1  PA4_1
#define CS_WIZ_0  PA4_0

typedef struct  reg_w5200  // объявляю структуру 
{
	u8 R[256];

	u8 MR 					:8;//MR (Mode Register) [R/W] [0x0000] [0x00]
    u8 RST 					:1;
    u8 WOL   				:1;
    u8 PB        			:1;
    u8 PPPoE        		:1;

    u32 GAR 				   ;//GAR (Gateway IP Address Register) [R/W] [0x0001 – 0x0004] [0x00]
    u32 SUBR          		:32;//(Subnet Mask Register) [R/W] [0x0005 – 0x0008] [0x00]
    u32 SHAR    			:32;//(Source Hardware Address Register) [R/W] [0x0009 – 0x000E] [0x00]
    u32 SIPR				:32;//SIPR (Source IP Address Register) [R/W] [0x000F – 0x0012] [0x00]
    
    u16 IR					:16;//IR (Interrupt Register) [R] [0x0015] [0x00]
    u8 CONFLICT        		:1;
    u8 IP_PPPoE       		:1;

    u16 IMR					:16;//IMR(Interrupt Mask Register)[R/W][0x0016][0x00]
    u8 S7_IMR				:1;
    u8 S6_IMR				:1;
    u8 S5_IMR				:1;
    u8 S4_IMR				:1;
    u8 S3_IMR				:1;
    u8 S2_IMR				:1;
    u8 S1_IMR				:1;
    u8 S0_IMR				:1;

    u16 RTR					:16;//RTR (Retry Time-value Register) [R/W] [0x0017 – 0x0018] [0x07D0]
    u8  RCR					:8;//RCR (Retry Count Register) [R/W] [0x0019] [0x08]

    u16 PATR 				:16;// PATR (Authentication Type in PPPoE mode) [R] [0x001C-0x001D] [0x0000]
    u8  PPPALGO 			:8;//PPPALGO(Authentication Algorithm in PPPoE mode)[R][0x001E][0x00]
    u8  VERSIONR 			:8;// VERSIONR (W5200 Chip Version Register)[R][0x001F][0x03]
    u8  PTIMER				:8;//PTIMER (PPP Link Control Protocol Request Timer Register) [R/W] [0x0028]
    u8  PMAGIC				:8;//PMAGIC (PPP Link Control Protocol Magic number Register) [R/W] [0x0029][0x00]
    u16 INTLEVEL			:16;//INTLEVEL (Interrupt Low Level Timer Register)[R/W][0x0030 – 0x0031][0x0000]
   
    u8  IR2 				:8;//IR2(W5200 SOCKET Interrupt Register)[R/W][0x0034][0x00]
    u8  S7_INT				:1;
    u8  S6_INT 				:1;
    u8  S5_INT 				:1;
    u8  S4_INT				:1;
    u8  S3_INT 				:1;
    u8  S2_INT 				:1;
    u8  S1_INT 				:1;
    u8  S0_INT				:1;

    u8  PHYSTATUS			:8;//PHYSTATUS(W5200 PHY status Register)[R/W][0x0035][0x00]
    u8  Link 				:1;//Link Status Register[Read Only]
    u8  POWERDOWN			:1;//Power down mode of PHY[Read/Write]

    u8 IMR2 				:8;//(Socket Interrupt Mask Register2) [R/W] [0x0036] [0x00]
    u8 IM_IR7				:1;//IP Conflict Enable
    u8 IM_IR5 				:1;//PPPoE Close Enable

    u8 S0_MR 				:8;//
    u8 S0_MR_MULTI			:1;//Multicasting
    u8 S0_MR_MF 			:1;//MAC Filter
    u8 S0_MR_ND_MC			:1;//Use No Delayed ACK
    u8 S0_MR_PROTOCOL		:4;//Sets up corresponding socket as TCP, UDP, or IP RAW mode (S0_MR_MACRAW and S0_MR_PPPoE are valid only in SOCKET 0)!!!
 
    //------------------------------

    u8 S0_CR 				:8;//Socket n is initialized and opened according to the protocol selected
    u8 S1_CR 				:8;
    u8 S2_CR 				:8;
    u8 S3_CR 				:8;
    u8 S4_CR 				:8;
    u8 S5_CR 				:8;
    u8 S6_CR 				:8;
    u8 S7_CR 				:8;

    u8 S0_IR 				:8;
    u8 S0_IR_PRECV			:1;
    u8 S0_IR_PFAIL			:1; 
    u8 S0_IR_PNEXT			:1; 
    u8 S0_IR_SEND_OK		:1;
    u8 S0_IR_TIMEOUT		:1;
    u8 S0_IR_RECV    		:1;
    u8 S0_IR_DISCON    		:1;
    u8 S0_IR_CON    		:1;

    u8 S0_SR 				:8;
    u8 S1_SR 				:8;
    u8 S2_SR 				:8;
    u8 S3_SR 				:8;
    u8 S4_SR 				:8;
    u8 S5_SR 				:8;
    u8 S6_SR 				:8;
    u8 S7_SR 				:8;

    u16 S0_PORT				:16;
    u16 S1_PORT				:16;
    u16 S2_PORT				:16;
    u16 S3_PORT				:16;
    u16 S4_PORT				:16;
    u16 S5_PORT				:16;
    u16 S6_PORT				:16;
    u16 S7_PORT				:16;

    u64 S0_DHAR				:48;//(Socket n Destination Hardware Address Register) 
    u64 S1_DHAR				:48;
    u64 S2_DHAR				:48;
    u64 S3_DHAR				:48;
    u64 S4_DHAR				:48;
    u64 S5_DHAR				:48;
    u64 S6_DHAR				:48;
    u64 S7_DHAR				:48;

    u32 S0_DIPR				:32;// (Socket n Destination IP Address Register)
    u32 S1_DIPR				:32;
    u32 S2_DIPR				:32;
    u32 S3_DIPR				:32;
    u32 S4_DIPR				:32;
    u32 S5_DIPR				:32;
    u32 S6_DIPR				:32;
    u32 S7_DIPR				:32;

    u16 S0_DPORT 			:16;//(Socket n Destination Port Register)
    u16 S1_DPORT 			:16;
    u16 S2_DPORT 			:16;
    u16 S3_DPORT 			:16;
    u16 S4_DPORT 			:16;
    u16 S5_DPORT 			:16;
    u16 S6_DPORT 			:16;
    u16 S7_DPORT 			:16;

    u16 S0_MSS				:16;//(Socket n Maximum Segment Size Register)
    u16 S1_MSS				:16;
	u16 S2_MSS				:16;
	u16 S3_MSS				:16;
    u16 S4_MSS				:16;
    u16 S5_MSS				:16;
    u16 S6_MSS				:16;
    u16 S7_MSS				:16;

    u8 S0_PROTO 			:8;//(Socket n IP Protocol Register) [R/W]
    u8 S1_PROTO 			:8;
    u8 S2_PROTO 			:8;
    u8 S3_PROTO 			:8;
    u8 S4_PROTO 			:8;
    u8 S5_PROTO 			:8;
    u8 S6_PROTO 			:8;
    u8 S7_PROTO 			:8;

    u8 S0_TOS 				:8;// (Socket n IP Type Of Service Register) [R/W] 
    u8 S1_TOS 				:8;
    u8 S2_TOS 				:8;
    u8 S3_TOS 				:8;
    u8 S4_TOS 				:8;
    u8 S5_TOS 				:8;
    u8 S6_TOS 				:8;
    u8 S7_TOS 				:8; 

    u8 S0_TTL				:8;//(Socket n IP Time To Live Register) [R/W]
    u8 S1_TTL				:8;
    u8 S2_TTL				:8;
    u8 S3_TTL				:8;
    u8 S4_TTL				:8;
    u8 S5_TTL				:8;
    u8 S6_TTL				:8;
    u8 S7_TTL				:8;

    u8 S0_RXMEM_SIZE		:8;//(Socket n RX Memory Size Register) [R/W]
    u8 S1_RXMEM_SIZE		:8;
    u8 S2_RXMEM_SIZE		:8;
    u8 S3_RXMEM_SIZE		:8;
    u8 S4_RXMEM_SIZE		:8;
    u8 S5_RXMEM_SIZE		:8;
    u8 S6_RXMEM_SIZE		:8;
    u8 S7_RXMEM_SIZE		:8;

    u8 S0_TXMEM_SIZE		:8;//(Socket n TX Memory size Register) [R/W]
    u8 S1_TXMEM_SIZE		:8;
    u8 S2_TXMEM_SIZE		:8;
    u8 S3_TXMEM_SIZE		:8;
    u8 S4_TXMEM_SIZE		:8;
    u8 S5_TXMEM_SIZE		:8;
    u8 S6_TXMEM_SIZE		:8;
    u8 S7_TXMEM_SIZE		:8;

    u16 S0_TX_FSR			:16;// (Socket n TX Free Size Register) [R]
    u16 S1_TX_FSR			:16;
 	u16 S2_TX_FSR			:16;
 	u16 S3_TX_FSR			:16;
 	u16 S4_TX_FSR			:16;
 	u16 S5_TX_FSR			:16;
 	u16 S6_TX_FSR			:16;
 	u16 S7_TX_FSR			:16;

 	u16 S0_TX_RD			:16;//(Socket n TX Read Pointer Register) [R]
 	u16 S1_TX_RD			:16;
 	u16 S2_TX_RD			:16;
 	u16 S3_TX_RD			:16;
 	u16 S4_TX_RD			:16;
 	u16 S5_TX_RD			:16;
 	u16 S6_TX_RD			:16;
 	u16 S7_TX_RD			:16;

 	u16 S0_TX_WR			:16;//(Socket n TX Write Pointer Register) [R/W]
 	u16 S1_TX_WR			:16;
 	u16 S2_TX_WR			:16;
 	u16 S3_TX_WR			:16;
 	u16 S4_TX_WR			:16;
 	u16 S5_TX_WR			:16;
 	u16 S6_TX_WR			:16;
 	u16 S7_TX_WR			:16;

 	u16 S0_RX_RSR			:16;//(SOCKET n Received Size Register) [R]
 	u16 S1_RX_RSR			:16;
 	u16 S2_RX_RSR			:16;
 	u16 S3_RX_RSR			:16;
 	u16 S4_RX_RSR			:16;
 	u16 S5_RX_RSR			:16;
 	u16 S6_RX_RSR			:16;
 	u16 S7_RX_RSR			:16;

 	u16 S0_RX_RD			:16;//(Socket n RX Read Pointer Register) [R/W]
 	u16 S1_RX_RD			:16;
 	u16 S2_RX_RD			:16;
 	u16 S3_RX_RD			:16;
 	u16 S4_RX_RD			:16;
 	u16 S5_RX_RD			:16;
 	u16 S6_RX_RD			:16;
 	u16 S7_RX_RD			:16;

 	u16 S0_RX_WR			:16;//(Socket n RX Write Pointer Register)[R/W]
 	u16 S1_RX_WR			:16;
 	u16 S2_RX_WR			:16;
 	u16 S3_RX_WR			:16;
 	u16 S4_RX_WR			:16;
 	u16 S5_RX_WR			:16;
 	u16 S6_RX_WR			:16;
 	u16 S7_RX_WR			:16;

 	u8 S0_IMR 				:8;//(Socket n Interrupt Mask Register)[R/W]
 	u8 S0_IMR_PRECV			:1;
 	u8 S0_IMR_PFAIL 		:1;
 	u8 S0_IMR_PNEXT			:1;
 	u8 S0_IMR_SENDOK		:1;
 	u8 S0_IMR_TIMEOUT		:1;
 	u8 S0_IMR_RECV 			:1;
 	u8 S0_IMR_DISCON		:1;
    u8 S0_IMR_CON 			:1;

    u16 S0_FRAG				:16;//(Socket n Fragment Register)[R/W]
    u16 S1_FRAG				:16;
    u16 S2_FRAG				:16;
    u16 S3_FRAG				:16;
    u16 S4_FRAG				:16;
    u16 S5_FRAG				:16;
    u16 S6_FRAG				:16;
    u16 S7_FRAG				:16;
 
} reg_w5200;

 reg_w5200 eth1;

 typedef struct 
{
	uint8 Mac[6];
	uint8 Lip[4];
	uint8 Sub[4];
	uint8 Gw[4];
	uint8 DNS_Server_IP[4];	
	uint8  DHCP;
}
CONFIG_MSG;

typedef struct 
{
	uint16 port;
	uint8 destip[4];
}CHCONFIG_TYPE_DEF;

 CONFIG_MSG Config_Msg;
 
 CHCONFIG_TYPE_DEF Chconfig_Type_Def; 


//----------------------------------------

void init_ETH (reg_w5200 *eth)
{

}

void IINCHIP_CSoff(u8 a)
{
	if (a==0) CS_WIZ_0;
	else 	  CS_WIZ_1;
}

u8  IINCHIP_SpiSendData(uint8 dat)
{
	return(SPI2_Send(dat));
}

uint8 IINCHIP_WRITE(uint16 addr,uint8 data)
{
//SPI MODE I/F
IINCHIP_CS(0);                            // CS=0, SPI start

IINCHIP_SpiSendData((addr & 0xFF00) >> 8);  // Address byte 1
IINCHIP_SpiSendData(addr & 0x00FF);         // Address byte 2
IINCHIP_SpiSendData(0x80);                  // Data write command and Write data length 1
IINCHIP_SpiSendData(0x01);                  // Write data length 2
IINCHIP_SpiSendData(data);                  // Data write (write 1byte data)

IINCHIP_CS(1);                             // CS=1,  SPI end

	return 1;
}

uint8 IINCHIP_READ(uint16 addr)
{
uint8 data;

IINCHIP_CSoff();                             // CS=0, SPI start
	
IINCHIP_SpiSendData((addr & 0xFF00) >> 8);   // Address byte 1
IINCHIP_SpiSendData(addr & 0x00FF);          // Address byte 2
IINCHIP_SpiSendData(0x00);                   // Data read command and Read data length 1
IINCHIP_SpiSendData(0x01);                   // Read data length 2   	
data = IINCHIP_SpiSendData(0x00);            // Data read (read 1byte data)
	
IINCHIP_CSon();                              // CS=1,  SPI end
	
return data;
}

//-----------------------------
void setMR(uint8 val)
{
	IINCHIP_WRITE(MR,val);
}

u8 getMR(void)
{
u8 a[4];
a[0] = IINCHIP_READ(MR);
return ((a[0]<<0));	
}

void iinchip_init(void)
{	
	setMR(MR_RST);	
}

uint8 getIR( void )
{
   return IINCHIP_READ(IR);
}


uint8 getRCR( void )
{
   return IINCHIP_READ(RCR);
}

u16 getRTR (void)
{
u8 a[2];
a[1] = IINCHIP_READ(RTR + 0);
a[0] = IINCHIP_READ(RTR + 1);
return ((a[1]<<8)+(a[0]<<0));	
}

void setRTR(uint16 timeout)
{
	IINCHIP_WRITE(RTR,(uint8)((timeout & 0xff00) >> 8));
	IINCHIP_WRITE((RTR + 1),(uint8)(timeout & 0x00ff));
}

void setRCR(uint8 retry)
{
	IINCHIP_WRITE(RCR,retry);
}

void setIMR(uint8 mask)
{
	IINCHIP_WRITE(IMR,mask); // must be setted 0x10.
}

u8 getIMR(void)
{
return IINCHIP_READ(IMR);	
}

void setSn_MSS(SOCKET s, uint16 Sn_MSSR0)
{
	IINCHIP_WRITE(Sn_MSSR0(s),(uint8)((Sn_MSSR0 & 0xff00) >> 8));
	IINCHIP_WRITE((Sn_MSSR0(s) + 1),(uint8)(Sn_MSSR0 & 0x00ff));
}

void setSn_TTL(SOCKET s, uint8 ttl)
{
   IINCHIP_WRITE(Sn_TTL(s), ttl);
}

void setSn_PROTO(SOCKET s, uint8 proto)
{
	IINCHIP_WRITE(Sn_PROTO(s),proto);
}

uint8 getSn_IR(SOCKET s)
{
   return IINCHIP_READ(Sn_IR(s));
}

uint8 getSn_SR(SOCKET s)
{
   return IINCHIP_READ(Sn_SR(s));
}

/**
@brief	get socket TX free buf size

This gives free buffer size of transmit buffer. This is the data size that user can transmit.
User shuold check this value first and control the size of transmitting data
*/
uint16 getSn_TX_FSR(SOCKET s)
{
	uint16 val=0,val1=0;
	do
	{
		val1 = IINCHIP_READ(Sn_TX_FSR0(s));
		val1 = (val1 << 8) + IINCHIP_READ(Sn_TX_FSR0(s) + 1);
      if (val1 != 0)
		{
   			val = IINCHIP_READ(Sn_TX_FSR0(s));
   			val = (val << 8) + IINCHIP_READ(Sn_TX_FSR0(s) + 1);
		}
	} while (val != val1);
   return val;
}


/**
@brief	 get socket RX recv buf size

This gives size of received data in receive buffer. 
*/
uint16 getSn_RX_RSR(SOCKET s)
{
	uint16 val=0,val1=0;
	do
	{
		val1 = IINCHIP_READ(Sn_RX_RSR0(s));
		val1 = (val1 << 8) + IINCHIP_READ(Sn_RX_RSR0(s) + 1);
      if(val1 != 0)
		{
   			val = IINCHIP_READ(Sn_RX_RSR0(s));
   			val = (val << 8) + IINCHIP_READ(Sn_RX_RSR0(s) + 1);
		}
	} while (val != val1);
   return val;
}

void setSHAR (u64 a)
{
IINCHIP_WRITE((SHAR0 + 0),a);
IINCHIP_WRITE((SHAR0 + 1),a>>8);
IINCHIP_WRITE((SHAR0 + 2),a>>16);
IINCHIP_WRITE((SHAR0 + 3),a>>24);
IINCHIP_WRITE((SHAR0 + 4),a>>32);
IINCHIP_WRITE((SHAR0 + 5),a>>40);
}

void setSIPR (u32 a)
{
IINCHIP_WRITE((SIPR0 + 0),a);
IINCHIP_WRITE((SIPR0 + 1),a>>8);
IINCHIP_WRITE((SIPR0 + 2),a>>16);
IINCHIP_WRITE((SIPR0 + 3),a>>24);
}

void setSUBR(u32 a)
{   
IINCHIP_WRITE((SUBR0 + 0),a);
IINCHIP_WRITE((SUBR0 + 1),a>>8);
IINCHIP_WRITE((SUBR0 + 2),a>>16);
IINCHIP_WRITE((SUBR0 + 3),a>>24);
}

void setGAR(u32 a)
{
IINCHIP_WRITE((GAR0 + 0),a);
IINCHIP_WRITE((GAR0 + 1),a>>8);
IINCHIP_WRITE((GAR0 + 2),a>>16);
IINCHIP_WRITE((GAR0 + 3),a>>24);
}

u32 getGAR(void)
{
	u8 a[4];
	a[0] = IINCHIP_READ(GAR0);
	a[1] = IINCHIP_READ(GAR0+1);
	a[2] = IINCHIP_READ(GAR0+2);
	a[3] = IINCHIP_READ(GAR0+3);
	return ((a[3]<<24)+(a[2]<<16)+(a[1]<<8)+(a[0]<<0));
}

u32 getSUBR(void)
{
	u8 a[4];
	a[0] = IINCHIP_READ(SUBR0);
	a[1] = IINCHIP_READ(SUBR0+1);
	a[2] = IINCHIP_READ(SUBR0+2);
	a[3] = IINCHIP_READ(SUBR0+3);
	return ((a[3]<<24)+(a[2]<<16)+(a[1]<<8)+(a[0]<<0));
}

u32 getSIPR(void)
{
	u8 a[4];
	a[0] = IINCHIP_READ(SIPR0);
	a[1] = IINCHIP_READ(SIPR0+1);
	a[2] = IINCHIP_READ(SIPR0+2);
	a[3] = IINCHIP_READ(SIPR0+3);
	return ((a[3]<<24)+(a[2]<<16)+(a[1]<<8)+(a[0]<<0));
}

u64 getSHAR(void)
{
	u8 a[6];
	a[0] = IINCHIP_READ(SHAR0);
	a[1] = IINCHIP_READ(SHAR0+1);
	a[2] = IINCHIP_READ(SHAR0+2);
	a[3] = IINCHIP_READ(SHAR0+3);
	a[4] = IINCHIP_READ(SHAR0+4);
	a[5] = IINCHIP_READ(SHAR0+5);

	return ((a[5]<<40)+(a[4]<<32)+(a[3]<<24)+(a[2]<<16)+(a[1]<<8)+(a[0]<<0));
}

u16 getSn_PORT (void)
{
u8 a[2];
a[1] = IINCHIP_READ(Sn_PORT_address + 0);
a[0] = IINCHIP_READ(Sn_PORT_address + 1);
return ((a[1]<<8)+(a[0]<<0));
}

u8 getVERSION (void)
{
	u8 a[1];
	a[0] = IINCHIP_READ(0x001f);

	return ((a[0]<<0));	
}

void setRTR(uint16 timeout)
{
	IINCHIP_WRITE(RTR,(uint8)((timeout & 0xff00) >> 8));
	IINCHIP_WRITE((RTR + 1),(uint8)(timeout & 0x00ff));
}

void setRCR(uint8 retry)
{
	IINCHIP_WRITE(RCR,retry);
}

void setRXMEM_SIZE (u16 a)
{
IINCHIP_WRITE((Sn_RXMEM_SIZE_address + 0),a);	
}

void setTXMEM_SIZE (u16 a)
{
IINCHIP_WRITE((Sn_TXMEM_SIZE_address + 0),a);	
}

void setSn_PORT (u16 a)
{
IINCHIP_WRITE((Sn_PORT_address + 0),a>>8);
IINCHIP_WRITE((Sn_PORT_address + 1),a);	
}
//------------------------------
void Set_network(reg_w5200 *eth)
{
uint64 tmp;       
uint8 i;

setMR( MR_RST );//w5200 INIT

Delay(10);//ms
        
// MAC ADDRESS
eth1->SHAR=((MAC[5]<<40)+
		    (MAC[4]<<32)+
		    (MAC[3]<<24)+
		    (MAC[2]<<16)+
		    (MAC[1]<< 8)+
		    (MAC[0]<< 0))
// Local IP ADDRESS
eth1->SIPR=((IP[3]<<24)+
		    (IP[2]<<16)+
		    (IP[1]<<8)+
		    (IP[0]<<0))
// GateWay ADDRESS
eth1->GAR=((GateWay[3]<<24)+
  		   (GateWay[2]<<16)+
		   (GateWay[1]<<8)+
		   (GateWay[0]<<0))
// Subnet Mask ADDRESS
eth1->SUBR=((SubNet[3]<<24)+
  		    (SubNet[2]<<16)+
		    (SubNet[1]<<8)+
		    (SubNet[0]<<0))      

//Set PTR and RCR register	
 eth1->RTR=6000;
 eth1->RCR=3;

//Init. TX & RX Memory size
 eth1->S0_RXMEM_SIZE=0x08;
 eth1->S0_TXMEM_SIZE=0x08;

//transfer register init
setSHAR(eth1->SHAR);
setSIPR(eth1->SIPR);
setSUBR(eth1->SUBR);
setGAR (eth1->GAR);

setRTR(eth1->RTR);
setRCR(eth1->RCR);

setRXMEM_SIZE(eth1->S0_RXMEM_SIZE);
setTXMEM_SIZE(eth1->S0_TXMEM_SIZE);

//---------------------------------------------------------        
Transf("\r\n----------------------------------------- \r\n");         		
Transf("W5200E01-M3                       \r\n");        
Transf("Network Configuration Information \r\n");        
Transf("----------------------------------------- \r");  

Transf("\r\nMAC : ");
tmp=getSIPR ();
Transf("\r\nIP : ");
xn_out("" ,(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
xn_out(".",(tmp>> 0)&0xff);	  
	    	          
tmp=getSUBR();
Transf("\r\nSN : ");
xn_out("" ,(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
xn_out(".",(tmp>> 0)&0xff);  
        
tmp=getGAR();
Transf("\r\nGW :");
xn_out("" ,(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
xn_out(".",(tmp>> 0)&0xff);
 
tmp=getSHAR();
Transf("\r\nMAC :");
xn_out("" ,(tmp>>40)&0xff);
xn_out(".",(tmp>>32)&0xff);
xn_out(".",(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
xn_out(".",(tmp>> 0)&0xff);

Transf("\r"); 
tmp=getSn_PORT();
Transf("\r\nPORT :");
x_out("" ,(tmp>0)&0xffff);

tmp=getVERSION();
x_out("version chip:",tmp);
	   
}

void ETH_info (void)
{
u64 tmp;
	
tmp=getMR();
x_out("MR:",tmp&0xff);

tmp=getGAR();
Transf("\r\nGW :");
xn_out("" ,(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
 x_out(".",(tmp>> 0)&0xff);

Transf("\r\nSN : ");
xn_out("" ,(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
 x_out(".",(tmp>> 0)&0xff); 

tmp=getSHAR();
Transf("\r\nMAC :");
xn_out("" ,(tmp>>40)&0xff);
xn_out(".",(tmp>>32)&0xff);
xn_out(".",(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
 x_out(".",(tmp>> 0)&0xff);

Transf("\r\nMAC : ");
tmp=getSIPR ();
Transf("\r\nIP : ");
xn_out("" ,(tmp>>24)&0xff);
xn_out(".",(tmp>>16)&0xff);
xn_out(".",(tmp>> 8)&0xff);
 x_out(".",(tmp>> 0)&0xff);	 

tmp=getIR();
x_out("IR:",tmp&0xff);

tmp=getIMR();
x_out("IMR:",tmp&0xff);

tmp=getRTR();
u_out("RTR:",tmp&0xff);

tmp=getRCR();
x_out("RCR:",tmp&0xff);

tmp=getVERSION();
x_out("version chip:",tmp);
}