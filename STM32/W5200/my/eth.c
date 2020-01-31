//#include "var_and_structur.h"
#include "eth.h"


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

//----------------------------------------

void init_ETH (reg_w5200 *eth)
{

}

void IINCHIP_CS(u8 a)
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

IINCHIP_CS(0);                             // CS=0, SPI start
	
IINCHIP_SpiSendData((addr & 0xFF00) >> 8);   // Address byte 1
IINCHIP_SpiSendData(addr & 0x00FF);          // Address byte 2
IINCHIP_SpiSendData(0x00);                   // Data read command and Read data length 1
IINCHIP_SpiSendData(0x01);                   // Read data length 2   	
data = IINCHIP_SpiSendData(0x00);            // Data read (read 1byte data)
	
IINCHIP_CS(1);                              // CS=1,  SPI end
	
return data;
}

//-----------------------------
void setMR(uint8 val)
{
	IINCHIP_WRITE(dMR,val);
}

u8 getMR(void)
{
u8 a[4];
a[0] = IINCHIP_READ(dMR);
return ((a[0]<<0));	
}

void iinchip_init(void)
{	
	setMR(MR_RST);	
}

uint8 getIR( void )
{
   return IINCHIP_READ(dIR);
}


uint8 getRCR( void )
{
   return IINCHIP_READ(dRCR);
}

u16 getRTR (void)
{
u8 a[2];
a[1] = IINCHIP_READ(dRTR + 0);
a[0] = IINCHIP_READ(dRTR + 1);
return ((a[1]<<8)+(a[0]<<0));	
}

void setRTR(uint16 timeout)
{
	IINCHIP_WRITE(dRTR,(uint8)((timeout & 0xff00) >> 8));
	IINCHIP_WRITE((dRTR + 1),(uint8)(timeout & 0x00ff));
}

void setRCR(uint8 retry)
{
	IINCHIP_WRITE(dRCR,retry);
}

void setIMR(uint8 mask)
{
	IINCHIP_WRITE(dIMR,mask); // must be setted 0x10.
}

u8 getIMR(void)
{
return IINCHIP_READ(dIMR);	
}


void setSHAR (u8 *a)
{u8 i;
Transf("setSHAR:");
for (i=0;i<6;i++) xn_out(" ",a[i]);
Transf("\r\n");
IINCHIP_WRITE((dSHAR0 + 0),a[0]);
IINCHIP_WRITE((dSHAR0 + 1),a[1]);
IINCHIP_WRITE((dSHAR0 + 2),a[2]);
IINCHIP_WRITE((dSHAR0 + 3),a[3]);
IINCHIP_WRITE((dSHAR0 + 4),a[4]);
IINCHIP_WRITE((dSHAR0 + 5),a[5]);
}

void setSIPR (u8 *a)
{u8 i;
Transf("setSIPR:");
for (i=0;i<4;i++) un_out(" ",a[i]);
Transf("\r\n");
IINCHIP_WRITE((dSIPR0 + 0),a[0]);
IINCHIP_WRITE((dSIPR0 + 1),a[1]);
IINCHIP_WRITE((dSIPR0 + 2),a[2]);
IINCHIP_WRITE((dSIPR0 + 3),a[3]);
}

void setSUBR(u8 *a)
{u8 i; 
Transf("setSUBR:"); 
for (i=0;i<4;i++) un_out(" ",a[i]);
Transf("\r\n");
IINCHIP_WRITE((dSUBR0 + 0),a[0]);
IINCHIP_WRITE((dSUBR0 + 1),a[1]);
IINCHIP_WRITE((dSUBR0 + 2),a[2]);
IINCHIP_WRITE((dSUBR0 + 3),a[3]);
}

void setGAR(u8 *a)
{u8 i;
Transf("setGAR :"); 
for (i=0;i<4;i++) un_out(" ",a[i]);
Transf("\r\n");
IINCHIP_WRITE((dGAR0 + 0),a[0]);
IINCHIP_WRITE((dGAR0 + 1),a[1]);
IINCHIP_WRITE((dGAR0 + 2),a[2]);
IINCHIP_WRITE((dGAR0 + 3),a[3]);
}

void getGAR(u8 *a)
{
	a[0] = IINCHIP_READ(dGAR0);
	a[1] = IINCHIP_READ(dGAR0+1);
	a[2] = IINCHIP_READ(dGAR0+2);
	a[3] = IINCHIP_READ(dGAR0+3);
}

void getSUBR(u8 *a)
{
	a[0] = IINCHIP_READ(dSUBR0);
	a[1] = IINCHIP_READ(dSUBR0+1);
	a[2] = IINCHIP_READ(dSUBR0+2);
	a[3] = IINCHIP_READ(dSUBR0+3);
}

void getSIPR(u8 *a)
{
	a[0] = IINCHIP_READ(dSIPR0);
	a[1] = IINCHIP_READ(dSIPR0+1);
	a[2] = IINCHIP_READ(dSIPR0+2);
	a[3] = IINCHIP_READ(dSIPR0+3);
}

void getSHAR(u8 *a)
{
	a[0] = IINCHIP_READ(dSHAR0);
	a[1] = IINCHIP_READ(dSHAR0+1);
	a[2] = IINCHIP_READ(dSHAR0+2);
	a[3] = IINCHIP_READ(dSHAR0+3);
	a[4] = IINCHIP_READ(dSHAR0+4);
	a[5] = IINCHIP_READ(dSHAR0+5);
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
u64 tmp;       
uint8 i;
u8 a[6];

setMR( MR_RST );//w5200 INIT

Delay(100);//ms
        
// MAC ADDRESS
for (i=0;i<6;i++) eth->SHAR[i]=MAC[i];

// Local IP ADDRESS
for (i=0;i<4;i++) eth->SIPR[i]=IP[i];

// GateWay ADDRESS
for (i=0;i<4;i++) eth->GAR[i]=GateWay[i];

// Subnet Mask ADDRESS
for (i=0;i<4;i++) eth->SUBR[i]=SubNet[i];

//Set PTR and RCR register	
 eth->RTR=6000;
 eth->RCR=3;

//Init. TX & RX Memory size
 eth->S0_RXMEM_SIZE=0x08;
 eth->S0_TXMEM_SIZE=0x08;

//transfer register init
setSHAR(eth->SHAR);
setSIPR(eth->SIPR);
setSUBR(eth->SUBR);
setGAR (eth->GAR);

setRTR(eth->RTR);
setRCR(eth->RCR);

setRXMEM_SIZE(eth->S0_RXMEM_SIZE);
setTXMEM_SIZE(eth->S0_TXMEM_SIZE);

//---------------------------------------------------------        
Transf("\r\n----------------------------------------- \r\n");         		
Transf("W5200E01-M3                       \r\n");        
Transf("Network Configuration Information \r\n");        
Transf("----------------------------------------- \r");  

getSIPR (a);
Transf("\r\nIP  :");
un_out ("",a[0]);
Transf(".");
un_out ("",a[1]);
Transf(".");
un_out ("",a[2]);
Transf(".");
un_out ("",a[3]);	
Transf("\r\n");  

	    	          
getSUBR(a);
Transf("\r\nSN  :");
un_out ("",a[0]);
Transf(".");
un_out ("",a[1]);
Transf(".");
un_out ("",a[2]);
Transf(".");
un_out ("",a[3]);	
Transf("\r\n");   
        
getGAR(a);
Transf("\r\nGW  :");
un_out ("",a[0]);
Transf(".");
un_out ("",a[1]);
Transf(".");
un_out ("",a[2]);
Transf(".");
un_out ("",a[3]);	
Transf("\r\n"); 
 
getSHAR(a);
Transf("\r\nMAC :");
xn_out ("",a[0]);
Transf(".");
xn_out ("",a[1]);
Transf(".");
xn_out ("",a[2]);
Transf(".");
xn_out ("",a[3]);
Transf(".");
xn_out ("",a[4]);
Transf(".");
xn_out ("",a[5]);	
Transf("\r\n"); 

tmp=getSn_PORT();
Transf("\r\nPORT:");
x_out("" ,(tmp>0)&0xffff);

tmp=getVERSION();
x_out("version chip:",tmp);
	   
}

void ETH_info (void)
{
u64 tmp;
char a[6];
	
Transf("---------\r\n");
/*
tmp=getMR();
x_out("MR :",tmp&0xff);

getSIPR (a);
Transf("\r\nIP  :");
x_out("",a);	
Transf("\r\n");  

	    	          
getSUBR(a);
Transf("\r\nSN  :");
x_out("",a);	
Transf("\r\n");   
        
getGAR(a);
Transf("\r\nGW  :");
x_out("",a);	
Transf("\r\n"); 
 
getSHAR(a);
Transf("\r\nMAC :");
x_out("",a);	
Transf("\r\n");  
*/
tmp=getIR();
x_out("IR :",tmp&0xff);

tmp=getIMR();
x_out("IMR:",tmp&0xff);

tmp=getRTR();
u_out("RTR:",tmp&0xff);

tmp=getRCR();
x_out("RCR:",tmp&0xff);

tmp=getVERSION();
x_out("version chip:",tmp);
}