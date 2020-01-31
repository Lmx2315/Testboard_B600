#include "global_var.h"

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

    



	
 
} reg_ADC42jb49;

 reg_ADC42jb49 adc1;