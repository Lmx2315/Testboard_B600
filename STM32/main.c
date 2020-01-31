#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_tim.h"
#include "onewire.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_spi.h"
#include "system_stm32f10x.h"
#include "stm32f10x_i2c.h"
#include "stm32f10x_dma.h"
//#include "systick.h"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "var_and_structur.h"
#include "eth.h"

#define adress_clock 0x68
#define adress_led   0x25

      GPIO_InitTypeDef  GPIO_InitStructure;  //объявляем структуры ножек GPIO

      USART_InitTypeDef USART1_InitStructure; //объявляем структуры UART1
      USART_InitTypeDef USART2_InitStructure; //объявляем структуры UART2
      EXTI_InitTypeDef EXTI_InitStructure;  //объявляем структуру для внешних прерываний   
      ADC_InitTypeDef ADC_init_struct;        //объявляем структуру ADC

  //  TIM_TimeBaseInitTypeDef Timer1;         //объявляем структуру Timer
     



static volatile uint32_t __counter;
static volatile uint32_t led_counter;

unsigned char flag_uart1=0;
unsigned char flag_uart2=0;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// This flag is set on USART1 Receiver buffer overflow
char  rx_buffer_overflow1;

// This flag is set on USART2 Receiver buffer overflow
char  rx_buffer_overflow2;

// USART1 Receiver buffer
#define RX_BUFFER_SIZE1 256
char          rx_buffer1[RX_BUFFER_SIZE1];
unsigned char rx_wr_index1,rx_rd_index1,rx_counter1;

// USART2 Receiver buffer
#define RX_BUFFER_SIZE2 256
char          rx_buffer2[RX_BUFFER_SIZE1];
unsigned char rx_wr_index2,rx_rd_index2,rx_counter2;

//*********************************************************

unsigned int led_tick;

//----------------------- IO ()  --------------------------------------   
#define buf_IO   32u 
#define buf_Word 32u 
#define buf_DATA_Word 200u 
#define BUFFER_SR 200u

    char    srt[BUFFER_SR+1];
    char  strng[buf_IO];

unsigned int lenght=0;

       char      InOut[BUFFER_SR+1];
       char      Word [buf_Word+1];    //массив командного слова
       char DATA_Word [buf_DATA_Word+1];    //массив слова - данных
       char DATA_Word2[buf_DATA_Word+1];    //массив слова - данных
 
#define MAX_PL 157u

  char Adress=0x30;      // адрес  
  char Master_flag=0x00; // флаг обозначающий мастер кассету 0, 1- вспомогательный синхронизатор.
  
unsigned     int index1=0u;
unsigned     char crc_ok=0u;
unsigned     char packet_ok=0u;
unsigned     char packet_flag=0u;

unsigned     int index_z=0u; 

unsigned     int index_word=0u;
unsigned     int index_data_word=0u;
unsigned     int index_data_word2=0u;
unsigned     int lenght_data=0u;//длинна данных
unsigned     char data_flag=0u;
unsigned     char data_flag2=0u;
unsigned     char FLAG_lenght=0u;//флаг служебного байта - длинный данных
unsigned     int sch_lenght_data=0u;
unsigned     char FLAG_DATA=0u;
				u16 SCH_LENGHT_PACKET=0u;
 
unsigned char FLAG_CW=0u;
unsigned     int crc_input=0u; 
unsigned     int crc_comp=0u;
 
 u32 SCH_7E_PAKET=0;
 u32 SCH_7E_PAKET_MAX=0;
 
 u32 SCH_7k_PAKET=0;
 u32 SCH_7k_PAKET_MAX=0;
 
 u32 SCH_7ok_PAKET=0;
 u32 SCH_7ok_PAKET_MAX=0;


 float time_uart; //
 unsigned char flag_pcf=0;

   char status_foch=0;

   
   float Lvl_3V3;   //
   float Lvl_2v5;
   float Lvl_1v8;
   float Lvl_1v5;
   float Lvl_1v0;
   float Lvl_1v0_MGTVCC;
   float Lvl_1v2_MGTVCC;
   float Lvl_VTTREF;
   float Lvl_VTTDDR;
   
float RF_5MHz;

float Temp_stm32;
float U_stm32;

unsigned short Sys_control_health=0;


   char event1,event1_1;
   char event2,event2_1;

   int time1=0;
   int time2=0;

   int time_led1=0;
   int time_led2=0;

   unsigned int time=0;
   unsigned long time_UPr = 0;
   unsigned long time_Temp_DMA = 0;
   char time_wdg=0;
   char SYS_terminal=1;

   float DBm[330];

   u8 flag_life_block=1;

   u8 flag_step    =0;
   u32 TIMER_SCR=0;
  
unsigned char devices;
unsigned int timer_INIT_FAPCH1=0;

int SysTickDelay;  
int tick_wait_LED_Zahvat=0;

unsigned char flag_ADC=0;
unsigned int  DataConv=0;


u8 FLAG_FPGA_DONE;
u8 FLAG_FPGA_INIT;
u8 FLAG_A_LOCK_DETECT;
u8 FLAG_B_LOCK_DETECT;

u8 RUN_FLAG=0;    //флаг означающий включение кассеты
u8 RUN_FLAG_ON=0; //флаг означающий что включение исполненно

float Lvl_f5MHz_in=0;
float Lvl_3v3=0;


u16 timer_start_init=0; //счётчик времени инициализации системы
u16 timer_Temp=0;      //счётчик интервалов между измерениями температуры
u8  flag_lcd_init=0;     // флаг инициализации LCD
u16 timer_clock_watcher=0;

//---------------------------------------------------------------------------------
 typedef struct                //
{
   u32   TNI; 
   u32   TKI;

   u32   TNP; 
   u32   TKP;
 
   u32   TNO;
   u32   TNC;
   u32  TOBM;

 } Sintez_struct;

 
   typedef struct                //flags
{
 
 u32 DDS_delay;
 u32 T_kalibrovka;
 u32 T_pomeha;
 u32 Pni1;
 u32 Pii1;
 u32 Pnp1;
 u32 Pip1;
 u16 QIT1;

 u32 Pni2;
 u32 Pii2;
 u32 Pnp2;
 u32 Pip2;
 u16 QIT2;

 u32 Pni3;
 u32 Pii3;
 u32 Pnp3;
 u32 Pip3;
 u16 QIT3;
 
 u32 TNO; //длительность интервала ТНО 
 u32 CMND;//командное слово, разпрешает или запрещает формирование временной сетки
 
 u8 N_temp;
 
 //------------------
 u8 vAvariya;
 u8 vTNI;
 u8 vTKI;
 u8 vTNP;
 u8 vTKP;
 u8  GBR;
 u8 temp1;//контрольный сигнал для проверки линии температурного датчика б610
 u8 temp2;//контрольный сигнал для проверки линии температурного датчика б610
 
 u8 vAVARIA_PIT_1_FT;
 u8 vAVARIA_PIT_2_FT;
 u8 vNORM_PIT_2FT;
 u8 vNORM_PIT_1FT;
 u8 vRAB_KAN_1FT;
 u8 vRAB_KAN_2FT;
 u8 vRAB_KAN_3FT;
 u8 vRAB_KAN_4FT;
 u8 AVARIA_KAN_4_FT;
 u8 AVARIA_KAN_3_FT;
 u8 AVARIA_KAN_2_FT;
 u8 AVARIA_KAN_1_FT;
 u8 NORMA_TEMP_1U07FI;
 u8 PA_1U07_FI;
 u8 MFI_regim; //режим работы формирователя

} code_packet;

 typedef struct                //
{
	
u8 	VKL_COM_FT; //сигнал управления коммутатором ФТ
u8  IN_FT50OM;	
	
u16 TNI;
u16 TNI_min;
u16 TNI_max;

u16 TNI1;
u16 TNI1_min;
u16 TNI1_max;

u16 TKI;
u16 TKI_min;
u16 TKI_max;

u16 T1_4;
u16 T1_4_min;
u16 T1_4_max;

u16 TKI1;
u16 TKI1_min;
u16 TKI1_max;

u16 TNP;
u16 TNP_min;
u16 TNP_max;

u16 TKP;
u16 TKP_min;
u16 TKP_max;

u16 TKP1;
u16 TKP1_min;
u16 TKP1_max;

u16 TOBM; 
u16 TOBM_min;
u16 TOBM_max;

u16 TNC;
u16 TNC_min;
u16 TNC_max;

u16 TNO;
u16 TNO_min;
u16 TNO_max;

u32 Rezerv4;
u32 Rezerv4_min;
u32 Rezerv4_max;

u32 Rezerv;
u32 Rezerv_min;
u32 Rezerv_max;

u32 Rezerv1;
u32 Rezerv1_min;
u32 Rezerv1_max;

u32 Rezerv2;
u32 Rezerv2_min;
u32 Rezerv2_max;

u32 Rezerv3;
u32 Rezerv3_min;
u32 Rezerv3_max;

u32 int_I;
u32 int_I_min;
u32 int_I_max;

u32 int_P;
u32 int_P_min;
u32 int_P_max;

u32 int_TNC;
u32 int_TNC_min;
u32 int_TNC_max;

u32 int_TNO;
u32 int_TNO_min;
u32 int_TNO_max;

u32 TNC24;
u32 TNC24_min;
u32 TNC24_max;

u32 TNO24;
u32 TNO24_min;
u32 TNO24_max;

u16 ADC_I;
u16 ADC_P;

u32 control;   

} inf_B660_struct;
 
//--------------------------
Sintez_struct    Struk0;

code_packet      upr;
code_packet temp_upr;

inf_B660_struct  B660;
  
u32 Alfa;//переменная времени внутри обзора

reg_w5200 eth1;

 
//-----------прототипы---------------------------

u32 FPGA_rSPI (u8,u8 );
u32 FPGA_wSPI (u8,u8,u32);
u8 IINCHIP_READ(uint16 );

//-----------------------------------------------

void init_RCC (void)
{

    // Cогласно документации необходимо разрешить тактирование 
    // AFIO (альтернативные функции линий ввода-вывода), так как регистры 
    // управления мультиплексорами находится в данном модуле:

 /* Initialize Enable the Clock*/
  RCC_APB2PeriphClockCmd(
             RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB
            |RCC_APB2Periph_GPIOC |RCC_APB2Periph_GPIOD |RCC_APB2Periph_GPIOE
            |RCC_APB2Periph_USART1|RCC_APB2Periph_TIM1  |RCC_APB2ENR_AFIOEN  , ENABLE);//|RCC_APB2Periph_AFIO
 // RCC_APB1PeriphClockCmd(
       //      RCC_APB1Periph_USART2             
    //        |RCC_APB1Periph_USART3, ENABLE);

   SysTick_Config(SystemCoreClock /1000);//1ms 

  //  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  //  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  //  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
  //  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

}

//------------------------------------------------------------------------  
void Delay( unsigned int Val)  
{  
   SysTickDelay = Val;  
   while (SysTickDelay != 0) {};  
}  
  
//------------------------------------------------------------------------  
u8 flag_Temp_convert;
u8 time_Temp_convert;
u16 timer_test=0;

void SysTick_Handler(void)  
{  
   if (SysTickDelay != 0)  
   {  
      SysTickDelay--;  
   }  
  	++__counter;
    ++time;
    ++time_wdg;      //таймер вочдога
    ++time_Temp_DMA; //таймер функций термометра
	if (timer_test!=0)  --timer_test;
    if (time_led1<1000) ++time_led1;
    
    if (flag_Temp_convert==1) ++time_Temp_convert; //считаем время измерения температуры
}  


void init_EXT(void)

{
  

GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource7); //прерывание с порта D ножки 7
EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising ;  // EXTI_Trigger_Rising
EXTI_InitStructure.EXTI_Line    = EXTI_Line7;
EXTI_InitStructure.EXTI_LineCmd = ENABLE;
EXTI_Init(&EXTI_InitStructure);

GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource6); //прерывание с порта D ножки 6
EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising ;  // EXTI_Trigger_Rising
EXTI_InitStructure.EXTI_Line    = EXTI_Line6;
//EXTI_InitStructure.EXTI_LineCmd = ENABLE;
EXTI_Init(&EXTI_InitStructure);
 
GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource5); //прерывание с порта D ножки 5
EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising ;  // EXTI_Trigger_Rising
EXTI_InitStructure.EXTI_Line    = EXTI_Line5;
//EXTI_InitStructure.EXTI_LineCmd = ENABLE;
EXTI_Init(&EXTI_InitStructure);

NVIC_SetPriority(EXTI9_5_IRQn, 1);
NVIC_EnableIRQ(EXTI9_5_IRQn); 

GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource4); //прерывание с порта D ножки 4
EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising ;  // EXTI_Trigger_Rising
EXTI_InitStructure.EXTI_Line    = EXTI_Line4;
EXTI_InitStructure.EXTI_LineCmd = ENABLE;
EXTI_Init(&EXTI_InitStructure);

NVIC_SetPriority(EXTI4_IRQn, 5);
NVIC_EnableIRQ(EXTI4_IRQn);

GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource3); //прерывание с порта D ножки 3
EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;
EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising ;  // EXTI_Trigger_Rising
EXTI_InitStructure.EXTI_Line    = EXTI_Line3;
EXTI_InitStructure.EXTI_LineCmd = ENABLE;
EXTI_Init(&EXTI_InitStructure);

NVIC_SetPriority(EXTI3_IRQn, 4);
NVIC_EnableIRQ(EXTI3_IRQn);


 
}


void EXTI4_IRQHandler (void)
{ 
 if (EXTI_GetITStatus(EXTI_Line4)!=RESET)
 {
	 EXTI_ClearFlag(EXTI_Line4);
     EXTI_ClearITPendingBit(EXTI_Line4);
//	 Transf("INT3\r\n");
	 
	 FLAG_TOBM=1;//произошло событие в синхронизаторе
 }
}

void EXTI3_IRQHandler (void)
{ 
if (EXTI_GetITStatus(EXTI_Line3)!=RESET)
 {
	 EXTI_ClearFlag(EXTI_Line3);
     EXTI_ClearITPendingBit(EXTI_Line3);
//	 Transf("INT2\r\n");
	 
	 FLAG_START=1;//сброшена шкала времени - начат первый цикл
 }
}


void EXTI9_5_IRQHandler (void)
{ 
  if (EXTI_GetITStatus(EXTI_Line5)!=RESET)
     { 
		EXTI_ClearFlag(EXTI_Line5);
        EXTI_ClearITPendingBit(EXTI_Line5);
  //    sendT("принято прерывание! INT5\r\n");          
        state_INT5=1;
      }

  if (EXTI_GetITStatus(EXTI_Line6)!=RESET)
     { 
		EXTI_ClearFlag(EXTI_Line6);
        EXTI_ClearITPendingBit(EXTI_Line6);
  //    sendT("принято прерывание! INT6\r\n");          
        state_INT6=1;
      }
 
    if (EXTI_GetITStatus(EXTI_Line7)!=RESET)
     { 
		EXTI_ClearFlag(EXTI_Line7);
        EXTI_ClearITPendingBit(EXTI_Line7);
  //    sendT("принято прерывание! INT7\r\n");          
        state_INT7=1;
      }

     if (EXTI_GetITStatus(EXTI_Line8)!=RESET)
     { 
	   EXTI_ClearFlag(EXTI_Line8);
	   EXTI_ClearITPendingBit(EXTI_Line8);
  //    sendT("принято прерывание! INT8\r\n");          
        state_INT8=1;
      }

   if (EXTI_GetITStatus(EXTI_Line9)!=RESET)
     { 
        EXTI_ClearFlag(EXTI_Line9);
        EXTI_ClearITPendingBit(EXTI_Line9);
  //    sendT("принято прерывание! INT9\r\n");          
        state_INT9=1;
      }

}




void EXTI15_10_IRQHandler (void)
{ 
  
  if (EXTI_GetITStatus(EXTI_Line11))
  { 
   //  EXTI_ClearFlag(EXTI_Line11);
     EXTI_ClearITPendingBit(EXTI_Line11);
  //   sendT("принято прерывание! INT11\r\n");
     
   state_INT11=1;

  }

    if (EXTI_GetITStatus(EXTI_Line10))
  { 
   //  EXTI_ClearFlag(EXTI_Line10);
     EXTI_ClearITPendingBit(EXTI_Line10);
   //  sendT("принято прерывание! INT10\r\n");
     
   state_INT10=1;

  }

    if (EXTI_GetITStatus(EXTI_Line12))
  { 
   //  EXTI_ClearFlag(EXTI_Line12);
     EXTI_ClearITPendingBit(EXTI_Line12);
   //  sendT("принято прерывание! INT12\r\n");
     
   state_INT12=1;

  }

    if (EXTI_GetITStatus(EXTI_Line13))
  { 
    // EXTI_ClearFlag(EXTI_Line13);
     EXTI_ClearITPendingBit(EXTI_Line13);
   //  sendT("принято прерывание! INT11\r\n");
     
   state_INT13=1;

  }

    if (EXTI_GetITStatus(EXTI_Line14))
  { 
     //EXTI_ClearFlag(EXTI_Line14);
     EXTI_ClearITPendingBit(EXTI_Line14);
   //  sendT("принято прерывание! INT11\r\n");
     
   state_INT14=1;

  }

    if (EXTI_GetITStatus(EXTI_Line15))
  { 
     //EXTI_ClearFlag(EXTI_Line15);
     EXTI_ClearITPendingBit(EXTI_Line15);
   //  sendT("принято прерывание! INT15\r\n");
     
   state_INT15=1;

  }



}




void init_GPIO (void)
{
  
    GPIO_PinRemapConfig( GPIO_Remap_SWJ_Disable, ENABLE );
    AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE; 

    /* Configure the GPIOA  pin выходы*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

     /* Configure the GPIOA  pin входы*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_11|GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


     /* Configure the GPIOB  pin выходы*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

     /* Configure the GPIOB  pin входы*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_8|GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	     /* Configure the GPIOC  pin выходы*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	     /* Configure the GPIOC  pin входы*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
		
        /* Configure выходы GPIOD pin */
    GPIO_InitStructure.GPIO_Pin = 	GPIO_Pin_0|
    								GPIO_Pin_1|
    								GPIO_Pin_8|
									GPIO_Pin_9|
									GPIO_Pin_10|
									GPIO_Pin_11|
									GPIO_Pin_12|
									GPIO_Pin_13|
									GPIO_Pin_14|
									GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	   /* Configure входы GPIOD pin */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|
    							  GPIO_Pin_3|
    							  GPIO_Pin_4|
    							  GPIO_Pin_5|
    							  GPIO_Pin_6|
    							  GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
	

        /* Configure выходы GPIOE pin */
    GPIO_InitStructure.GPIO_Pin = 	GPIO_Pin_2|
									GPIO_Pin_3|
									GPIO_Pin_4|
									GPIO_Pin_5|
									GPIO_Pin_6|
									GPIO_Pin_5|
									GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	      /* Configure входы GPIOE pin */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|
								  GPIO_Pin_1|
								  GPIO_Pin_7|
								  GPIO_Pin_8|
								  GPIO_Pin_9|
								  GPIO_Pin_10|
								  GPIO_Pin_11|
								  GPIO_Pin_12|
							      GPIO_Pin_13|
								  GPIO_Pin_14|
								  GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

  
     
 }

/*

void init_TIM (void)
{
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

    TIM_TimeBaseStructInit(&Timer1);
    Timer1.TIM_Prescaler = 720;
    Timer1.TIM_Period = 250;

    TIM_TimeBaseInit(TIM4, &Timer1); 
    TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM4, ENABLE);
    NVIC_EnableIRQ(TIM4_IRQn);


}

*/

/*

void TIM4_IRQHandler()
{   
    uint16_t button = 0;
      
    TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
    
}

*/



void init_ADC (void)
{
	//подаём тактовую частоту
    RCC_ADCCLKConfig(RCC_PCLK2_Div4); 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  //конфигурируем ноги АЦП порт С 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
    // ADC1 configuration 
    ADC_init_struct.ADC_Mode = ADC_Mode_Independent;//Работаем не в Dual режиме.
    ADC_init_struct.ADC_ScanConvMode = DISABLE;//Выключаем сканирование.
    ADC_init_struct.ADC_ContinuousConvMode = DISABLE;//Выключаем повторное преобразование по окончании преобразования.
    ADC_init_struct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//Выключаем тригеры.
    ADC_init_struct.ADC_DataAlign = ADC_DataAlign_Right;//выравнивание полученных данных по правому краю.
    ADC_init_struct.ADC_NbrOfChannel = 1;//Число каналов для сканирования.
    ADC_Init(ADC1, &ADC_init_struct);//Инициализация.

    ADC_TempSensorVrefintCmd(ENABLE);//внутренний температурный сенсор  

    // Включаем прерывания по окончании преобразования (EoC - End of Conversion)

    ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);

    // Включаем общие прерывания от АЦП

    NVIC_EnableIRQ(ADC1_2_IRQn);

    // Включаем АЦП
    ADC_Cmd(ADC1, ENABLE);

    //Делаем калибровку.

    // Enable ADC1 reset calibration register 
    ADC_ResetCalibration(ADC1);
    // Check the end of ADC1 reset calibration register 
    while(ADC_GetResetCalibrationStatus(ADC1));

    // Start ADC1 calibration 
    ADC_StartCalibration(ADC1);
    // Check the end of ADC1 calibration 
    while(ADC_GetCalibrationStatus(ADC1));

    //Для запуска АЦП используем команду 
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}



void ADC1_2_IRQHandler(void)//ADC interrupt
{
//Для чтения пишем следующее:
ADC1->SR&=~ADC_SR_EOC;//Сбрасываем бит окончания преобразования
DataConv = ADC1->DR;
flag_ADC=1;
}

unsigned long ADC (unsigned long ch) {
   ADC1->SQR3 = ch;
   flag_ADC=0;
   ADC_SoftwareStartConvCmd(ADC1, ENABLE);
   while (flag_ADC!=1);
   return (DataConv);
}


void init_USART1 (void)
{

//Настраиваем UART

  //Настраиваем порт на выход Push/Pull
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
GPIO_Init(GPIOA, &GPIO_InitStructure);

//Настраиваем порт на вход  
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
GPIO_Init(GPIOA, &GPIO_InitStructure);

// Включение тактирования UART делается аналогично:

RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

//APB2PeriphClockCmd - Список устройств, которые включаются этой функцией можно найти в файле stm32f10x_rcc.h.

//Собственно сама инициализация:
//Для инициализации с помощью библиотеки StdPeriph как обычно надо..

// конфигурируем USART1
USART1_InitStructure.USART_BaudRate = 115200;
USART1_InitStructure.USART_WordLength = USART_WordLength_8b;
USART1_InitStructure.USART_StopBits = USART_StopBits_1;
USART1_InitStructure.USART_Parity = USART_Parity_No;
USART1_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
USART1_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

 NVIC_SetPriority (USART1_IRQn, 15);
 NVIC_EnableIRQ(USART1_IRQn);

// разрешаем прерывания по приёму 
 USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

 USART_Cmd(USART1, ENABLE);
        
//USART_OverSampling8Cmd(ENABLE); //можно уменьшить частоту семплирования  
//USART_OneBitMethodCmd(ENABLE); //можно уменьшить количество стробирований
//USART_HalfDuplexCmd (ENABLE); // можно выбрать полудуплексный режим.
        
  USART_Init(USART1, &USART1_InitStructure); //инизиализируем

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); //инициализируем DMA

}


#define Bufer_size  4096u     //16384

 volatile  unsigned  int  text_lengh;
					 char text_buffer[Bufer_size];
 volatile  unsigned  char flag_pachka_TXT=0; //флаг показывающий что идёт передача пачки данных


// внутренняя процедура. Записывает указанное число бит
void DMA_UART_Send(uint8_t* DMA_buf,uint16_t num_bytes) 
{
DMA_InitTypeDef DMA_InitStructure;
				
			// DMA на запись
			DMA_DeInit(DMA1_Channel4);
			DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) &(USART1->DR);
			DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t) DMA_buf;
			DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
			DMA_InitStructure.DMA_BufferSize = num_bytes;
			DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
			DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
			DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
			DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
			DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
			DMA_InitStructure.DMA_Priority = DMA_Priority_Low;
			DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
			DMA_Init(DMA1_Channel4, &DMA_InitStructure);
			
			NVIC_SetPriority (DMA1_Channel4_IRQn, 14);
			NVIC_EnableIRQ (DMA1_Channel4_IRQn); //Включаем общие прерывания в NVIC.
			
			DMA_ITConfig(DMA1_Channel4, DMA_IT_TC, ENABLE); 
			// старт цикла отправки
			USART_ClearFlag(USART1,USART_FLAG_TC | USART_FLAG_TXE);
			USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
			
			// включаем DMA
			DMA_Cmd(DMA1_Channel4, ENABLE);
	
}

void DMA1_Channel4_IRQHandler(void)
{
   if (DMA_GetFlagStatus(DMA1_FLAG_TC4))
    {       
             DMA_Cmd(DMA1_Channel5, DISABLE);
     		 DMA_ClearFlag(DMA1_FLAG_TC4);
      		 DMA_ClearITPendingBit(DMA1_IT_TC4);
     
         // отключаем DMA
			DMA_Cmd(DMA1_Channel4, DISABLE);
			USART_DMACmd(USART1, USART_DMAReq_Tx | USART_DMAReq_Rx, DISABLE);
    }
     flag_pachka_TXT = 0;
	 
	 //sendT ("IRQ_DMA!\r");
}


void init_USART2 (void)
{

//Настраиваем UART

  //Настраиваем порт на выход Push/Pull
GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
GPIO_Init(GPIOA, &GPIO_InitStructure);

//Настраиваем порт на вход 
GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
GPIO_Init(GPIOA, &GPIO_InitStructure);

// Включение тактирования UART делается аналогично:

RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

//APB2PeriphClockCmd - Список устройств, которые включаются этой функцией можно найти в файле stm32f10x_rcc.h.

//Собственно сама инициализация:
//Для инициализации с помощью библиотеки StdPeriph как обычно надо..

// конфигурируем USART1
USART2_InitStructure.USART_BaudRate = 625000;
USART2_InitStructure.USART_WordLength = USART_WordLength_8b;
USART2_InitStructure.USART_StopBits = USART_StopBits_1;
USART2_InitStructure.USART_Parity = USART_Parity_No;
USART2_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
USART2_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;


 NVIC_EnableIRQ(USART2_IRQn);

// разрешаем прерывания по приёму 
 USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

 USART_Cmd(USART2, ENABLE);
        
//USART_OverSampling8Cmd(ENABLE); //можно уменьшить частоту семплирования  
//USART_OneBitMethodCmd(ENABLE); //можно уменьшить количество стробирований
//USART_HalfDuplexCmd (ENABLE); // можно выбрать полудуплексный режим.
        
  USART_Init(USART2, &USART2_InitStructure); //инизиализируем


}


void delay_us( u16 time_us )
{
	int i=0;
	while(i<time_us) {i++;}
}


void UART_DMA_TX (void)
{
 unsigned  int l=0;
 unsigned  int i;
 unsigned  int k;
 unsigned char w=0;

if ((flag_pachka_TXT==0)&&(text_lengh>1u))
{ 
    k = text_lengh;
  	DMA_UART_Send(text_buffer,k);
    text_lengh=0u;  //обнуление счётчика буфера
    flag_pachka_TXT=1; //устанавливаем флаг передачи
  }
}
	
 void Transf(const char* s)  // процедура отправки строки символов в порт 
   {
       unsigned  short l=0;
       unsigned  short i=0;
         
         if ((flag_pachka_TXT==0) )
      {
        
      	l=strlen(s);

        if ((text_lengh+l)>Bufer_size-5) text_lengh=0u;
      		
        for (i=text_lengh;i<(text_lengh+l);i++) text_buffer[i]=s[i-text_lengh];
               
      	text_lengh=text_lengh+l;
      	

        }	
	
  }
 
 void Buf_send(const char* s,int l)  // процедура отправки буфера в порт 
   {
       int i=0;
	   
         if ((flag_pachka_TXT==0) )
      {
     		
        for (i=0;i<l;i++) text_buffer[i]=s[i];

        }	
		
		text_lengh=l;
	
  } 

 void ZTransf(const char* s,unsigned char a)  // процедура отправки строки символов в порт 
   {
     unsigned  short l;
     unsigned  short i;
            
           if ((flag_pachka_TXT==0))
          {      
            
	          l=a;

	           if ((text_lengh+l)>Bufer_size-5) text_lengh=0;
	            
	           for (i=text_lengh;i<(text_lengh+l);i++) text_buffer[i]=s[i-text_lengh];
	           
	          text_lengh=text_lengh+l;

          } 
      
  }


void init_SPI2(void)

{
    GPIO_InitTypeDef gpio_port;
    SPI_InitTypeDef SPIConf;

       // Включаем тактирование нужных модулей
  
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);


      // Configure PB.13(SPI2_SCK) and PB.15(SPI2_MOSI)
  gpio_port.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
  gpio_port.GPIO_Mode = GPIO_Mode_AF_PP;  //Internal pull down
  gpio_port.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gpio_port);
  // Configure  PB.14(SPI2_MISO)
  gpio_port.GPIO_Pin = GPIO_Pin_14;
  gpio_port.GPIO_Mode = GPIO_Mode_AF_OD;//GPIO_Mode_AF_PP;
  gpio_port.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &gpio_port);

    // указываем, что используем мы только передачу данных
    SPIConf.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    // указываем, что наше устройство - Master
    SPIConf.SPI_Mode = SPI_Mode_Master;
    // передавать будем по 8 бит (=1 байт)
    SPIConf.SPI_DataSize = SPI_DataSize_8b;
    // режим 00
    SPIConf.SPI_CPOL = SPI_CPOL_Low;//SPI_CPOL_Low;////SPI_CPOL_High
    SPIConf.SPI_CPHA = SPI_CPHA_1Edge;
    SPIConf.SPI_NSS = SPI_NSS_Soft;
    // установим скорость передачи (опытным путём выяснили, что разницы от изменения этого параметра нет)
    SPIConf.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;//SPI_BaudRatePrescaler_256;
    // передаём данные старшим битом вперёд (т.е. слева направо)
    SPIConf.SPI_FirstBit = SPI_FirstBit_MSB;//SPI_FirstBit_MSB SPI_FirstBit_LSB
    // внесём настройки в SPI
    SPI_Init(SPI2, &SPIConf);
    // включим  SPI2
    SPI_Cmd(SPI2, ENABLE);
    // SS = 1
    SPI_NSSInternalSoftwareConfig(SPI2, SPI_NSSInternalSoft_Set);

}

void init_SPI1(void)

{
    GPIO_InitTypeDef gpio_port;
    SPI_InitTypeDef SPIConf;

       // Включаем тактирование нужных модулей
  
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
   RCC_APB1PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

 //  GPIO_PinRemapConfig( GPIO_Remap_SPI1, ENABLE );

      // Configure PA.5(SPI1_SCK) and PA.7(SPI1_MOSI)
  gpio_port.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
  gpio_port.GPIO_Mode = GPIO_Mode_AF_PP;  //Internal pull down
  gpio_port.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &gpio_port);
  // Configure  PA.6(SPI1_MISO)
  gpio_port.GPIO_Pin = GPIO_Pin_6;
  gpio_port.GPIO_Mode = GPIO_Mode_AF_OD;//GPIO_Mode_AF_PP;
  gpio_port.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &gpio_port);

    // указываем, что используем мы только передачу данных
    SPIConf.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    // указываем, что наше устройство - Master
    SPIConf.SPI_Mode = SPI_Mode_Slave;
    // передавать будем по 8 бит (=1 байт)
    SPIConf.SPI_DataSize = SPI_DataSize_8b;
    // режим 00
    SPIConf.SPI_CPOL = SPI_CPOL_High;//SPI_CPOL_Low;////
    SPIConf.SPI_CPHA = SPI_CPHA_2Edge;
    SPIConf.SPI_NSS = SPI_NSS_Hard;
    // установим скорость передачи (опытным путём выяснили, что разницы от изменения этого параметра нет)
    SPIConf.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
    // передаём данные старшим битом вперёд (т.е. слева направо)
    SPIConf.SPI_FirstBit = SPI_FirstBit_MSB;
    // внесём настройки в SPI
    SPI_Init(SPI1, &SPIConf);
    SPI_I2S_ITConfig(SPI1,SPI_I2S_IT_RXNE,ENABLE); //Включаем прерывание по приему байта
    // включим  SPI1
    SPI_Cmd(SPI1, ENABLE);
    NVIC_EnableIRQ(SPI1_IRQn); //Разрешаем прерывания от SPI1
    // SS = 1
   // SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);

}

//Обработчик прерываний от SPI1
void SPI1_IRQHandler (void) 
{
if (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)==SET) 
	{
		// Прерывание вызвано приемом байта ?
		uint8_t data = SPI1->DR; //Читаем то что пришло
		 //Инвертируем состояние светодиодов
		//SPI1->DR = data; //И отправляем обратно то что приняли
	}
}

u8 SPI2_Send(u8 data) 
{
    SPI_I2S_SendData(SPI2, data);  // отправили данные

    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET); // ждём, пока данные не отправятся
     
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);  // ждём пока данные появтся

    u8 received = SPI_I2S_ReceiveData(SPI2);
    
    return received;
}

u8 SPI2_Resiv(void) 
{
    while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);  // ждём пока данные появтся
    u8 received = SPI_I2S_ReceiveData(SPI2);
    return received;
}


//****************************************************************************
//function функция обмена по  spi                                            //
//argument байт для передачи                                                //
//result   принятый байт                                                    //
//****************************************************************************
u8 spi2_rw (u8 outb) 
{
  while (!(SPI2->SR & 0x01));
  SPI2->DR = outb;           //передать байт
  while (!(SPI2->SR & 0x02));
  return (SPI2->DR);       //вернуть принятый байт
}

u8 cs_spi (u8 a) //функция програмного чипселекта
{
  int z=0;

  if (a==0) 
    {
     // LED3_on;
      while (z<60) z=z+1;
    }

  if (a==1) 
    { 
      while (z<60) z=z+1;
      //LED3_off;
    } 
}
/*
void itoa(u32 val, int base,  char *bufstr) //
{
    u8 buf[32] = {0};
    int i = 30;
    int j;
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789abcdef"[val % base];
    i++; j=0;
    while (buf[i]!=0){ bufstr[j]=buf[i]; i++; j++;}
}
*/


void zputc (unsigned long c) 
{
	while (!USART_GetFlagStatus(USART1, USART_SR_TXE)) {} //Проверка завершения передачи предыдущих данных
	USART1->DR = c; //Передача данных
}

void zputc2 (unsigned long c) 
{
  while (!USART_GetFlagStatus(USART2, USART_SR_TXE)) {} //Проверка завершения передачи предыдущих данных
  USART2->DR = c; //Передача данных
}

void USART1_IRQHandler (void) 
{
   unsigned char temp;
   char status,data;

   if ( USART_GetITStatus(USART1, USART_IT_RXNE) ) 
    {
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    };

  //while(!(USART1->SR & USART_SR_RXNE)); //Ждем поступления данных от компьютера    
   data = USART1->DR; //считываем данные

   rx_buffer1[rx_wr_index1++]=data;

     if (rx_wr_index1 == RX_BUFFER_SIZE1) rx_wr_index1=0;
     if (++rx_counter1 == RX_BUFFER_SIZE1)
        {
        rx_counter1=0;
        rx_buffer_overflow1=1;
        }

// NVIC_ICPR1 = (1 << 5);

   temp = USART1->SR;
   temp = USART1->DR;

}

void USART2_IRQHandler (void) 
{
   unsigned char temp;
   char status,data;

   if ( USART_GetITStatus(USART2, USART_IT_RXNE) ) 
    {
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);
    };

  //while(!(USART1->SR & USART_SR_RXNE)); //Ждем поступления данных от компьютера    
   data = USART2->DR; //считываем данные

   rx_buffer2[rx_wr_index2++]=data;

     if (rx_wr_index2 == RX_BUFFER_SIZE2) rx_wr_index2=0;
     if (++rx_counter2 == RX_BUFFER_SIZE2)
        {
        rx_counter2=0;
        rx_buffer_overflow2=1;
        }
  // NVIC_ICPR1 = (1 << 5);

   temp = USART2->SR;
   temp = USART2->DR;

}




 void zputs(unsigned char *s, unsigned l)
{
  unsigned i;
  for (i=0;i<l;i++)
	  {
        zputc ((s[i]));
      }
}


 void zputs2(unsigned char *s, unsigned l)
{
 unsigned i;
 for (i=0;i<l;i++)
	 {
      zputc2 ((s[i]));
     }
}



unsigned int leng (unsigned char *s)
{
  unsigned  char i=0;
   while ((s[i]!='\0')&&(i<120)) { i++;}
  return i;

}

void sendT (unsigned char * s)
 {
  zputs(s,leng(s));
 }

void sendT2 (unsigned char * s)
 {
  zputs2(s,leng(s));
 }

char getchar1(void)
{
    char data;
    while (rx_counter1==0);
    data=rx_buffer1[rx_rd_index1++];
    if (rx_rd_index1 == RX_BUFFER_SIZE1) rx_rd_index1=0;
    --rx_counter1;
    return data;
}

char getchar2(void)
{
    char data;
    while (rx_counter2==0);
    data=rx_buffer2[rx_rd_index2++];
    if (rx_rd_index2 == RX_BUFFER_SIZE2) rx_rd_index2=0;
    --rx_counter2;
    return data;
}


void sprnt_tof(char* buf,float a)
 {

 }


  // reverse:  переворачиваем строку s на месте 
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

 /* itoa:  конвертируем n в символы в s */
 void itoa(int n,char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

void u_out (char s[],u32 a)
{
   Transf (s);
   itoa (a,strng);
   Transf(strng);
   Transf ("\r\n");
}

void un_out (char s[],u32 a)
{
   Transf (s);
   itoa (a,strng);
   Transf(strng);
  // Transf ("\r\n");
}

void x_out (char s[],u32 a)
{
   Transf (s);
   sprintf (strng,"%X",a);
   Transf(strng);
   Transf ("\r\n");
}

void xn_out (char s[],u32 a)
{
   Transf (s);
   sprintf (strng,"%X",a);
   Transf(strng);
   //Transf ("\r\n");
}

void f_out (char s[],float a)
{
   Transf (s);
   sprintf (strng,"%f",a);
   Transf(strng);
   Transf ("\r\n");
}

void DATA_send (u8 a)
{
	GPIO_Write(GPIOD,a<<8);
}

void MK_DATA_send (u8 a)
{
	GPIO_Write(GPIOE,a<<8);
}

void init_b660 (void)
{
B660.TNI_max =0;
B660.TNI_min =0xffffffff;
B660.TNI1_max=0;
B660.TNI1_min=0xffffffff;
B660.TKI_max =0;
B660.TKI_min =0xffffffff;
B660.T1_4_max=0;
B660.T1_4_min=0xffffffff;
B660.TKI1_max=0;
B660.TKI1_min=0xffffffff;
B660.TNP_max =0;
B660.TNP_min =0xffffffff;
B660.TKP_max =0;
B660.TKP_min =0xffffffff;
B660.TKP1_max=0;
B660.TKP1_min=0xffffffff;
B660.TOBM_max=0;
B660.TOBM_min=0xffffffff;
B660.TNC_max =0;
B660.TNC_min =0xffffffff;
B660.TNO_max =0;
B660.TNO_min =0xffffffff;
B660.Rezerv4_max=0;
B660.Rezerv4_min=0xffffffff;
B660.Rezerv_max=0;
B660.Rezerv_min=0xffffffff;
B660.Rezerv1_max=0;
B660.Rezerv1_min=0xffffffff;
B660.Rezerv2_max=0;
B660.Rezerv2_min=0xffffffff;
B660.Rezerv3_max=0;
B660.Rezerv3_min=0xffffffff;
B660.int_I_max=0;
B660.int_I_min=0xffffffff;
B660.int_P_max=0;
B660.int_P_min=0xffffffff;
B660.int_TNC_max=0;
B660.int_TNC_min=0xffffffff;
B660.int_TNO_max=0;
B660.int_TNO_min=0xffffffff;
}

void Massiv_dbm(char y)
{
u16 i;
float e;
 DBm[  9]=-25;
 DBm[ 10]=-24;
 DBm[ 11]=-23;
 DBm[ 12]=-22;
 DBm[ 13]=-21;
 DBm[ 15]=-20;
 DBm[ 24]=-15;
 DBm[ 41]=-10;
 DBm[ 70]=-5;
 DBm[130]= 0;
 DBm[230]= 5;
 DBm[330]= 8;

for (i=  0;i<  9;i++) { e=-600+(i- 9)*6  ;   DBm[i]= e;}
for (i=  9;i< 16;i++) { e=-250+(i- 9)*8.3;   DBm[i]= e;}
for (i= 15;i< 25;i++) { e=-200+(i-15)* 5;    DBm[i]= e;}
for (i= 24;i< 42;i++) { e=-150+(i-24)*2.7;   DBm[i]= e;}
for (i= 41;i< 71;i++) { e=-100+(i-41)*1.7;   DBm[i]= e;}
for (i= 70;i<131;i++) { e=-50 +(i- 70)*0.83; DBm[i]= e;}
for (i=130;i<231;i++) { e=-0 +(i-130)*0.5;   DBm[i]= e;}
for (i=230;i<334;i++) { e= 50 +(i-230)*0.29; DBm[i]= e;}

 if (y)     //
    {
      for (i=0;i<334;i++)    { DBm[i]= DBm[i]/10;}
    }
}


unsigned int convert_to_volt(int a)
{
u16 i=0;
int a_min=10;
int a_max=0;

 for (i=0;i<330;i++) 
 {
    if (a>DBm[i]) a_min=i;
    if (a<DBm[i]) a_max=i;
 }

 if (a_max==0) {a_max=330*(a/8);a_min=a_max;}
 return ((a_min+a_max)/2);
}

 
//Итерационный вариант
float pwr(float num, int pow) {
    int i;
    float tmp = 1;
    for (i = 1; i <= pow; i++) {
        tmp *= num;
    }
    return tmp;
}

float fsqrtf(float n)
{
  float f;
  unsigned long *i;
  f = n;
  i = ((unsigned long*)&f);
  *i = (0xbe6f0000 - *i) >> 1;
  n *= f;
  return (n * (1.5 - 0.5 * f * n));
}

float DBm_to_volt(float a)
{
float x1,x2,y;
y = (a/10);
y =  powf (10,y);
//y =  pwr (10,y);
x1 = (y/1000)*50;
x2 = sqrtf (x1);
//x2 = fsqrtf (x1);
return x2; 
}


float DBm_to_watt(float a)
{
float x1,y;
y = (a/10);
y =  powf (10,y);
x1 = y/1000;
u_out("DBm в Ватты:%4.2f",x1);
return x1; 
}

float watt_to_v(float a)
{
float x1,x2;
x1 = a*50;
x2 = sqrtf (x1);
u_out("Вт в Вольты:%4.2f",x2);
return x2; 
}


void IO ( char* str)      // функция обработки протокола обмена
{
      u16 y;  
 unsigned int i=0;
 unsigned int j=0;
 unsigned int l=0;
 unsigned int k=0;
 char sym1=0;

  i = lenght;//длинна принятой пачки
  if (lenght==0) i = leng(str);
  lenght = 0;
  j=i;
 
  index_z = 0;
  
  if ((time_uart>50u)||(SCH_LENGHT_PACKET>MAX_PL))
  {
	//-------------------
		packet_flag=0; 
	//-------------------
		time_uart=0u;  //обнуление счётчика тайм аута
		index1=0u; 
		crc_ok=0; 
		packet_ok=0; 
		index_word=0u; 
		index_data_word =1u;
		index_data_word2=1u;
		data_flag =0;
		data_flag2=0;
		FLAG_lenght=0u;
		lenght_data=0u;
		sch_lenght_data=0u;
		DATA_Word [0]=' ';
		DATA_Word2[0]=' ';
		FLAG_CW = 0u; //флаг управляющего байта, снимается сразу после исполнения
		FLAG_DATA = 0u;
		SCH_LENGHT_PACKET=0;
  }
  
  while (i>0u)   //перегрузка принятого пакета в массив обработки 
  {
	if ((str[index_z]==0x7e)&&(packet_flag==0))// обнаружено начало пакета
	  {  
		//-------------------
		packet_flag=1; 
		//-------------------
		time_uart=0u;  //обнуление счётчика тайм аута
		index1=0u; 
		crc_ok=0; 
		packet_ok=0; 
		index_word=0u; 
		index_data_word =1u;
		index_data_word2=1u;
		data_flag =0;
		data_flag2=0;
		FLAG_lenght=0u;
		lenght_data=0u;
		sch_lenght_data=0u;
		DATA_Word [0]=' ';
		DATA_Word2[0]=' ';
		FLAG_CW = 0u; //флаг управляющего байта, снимается сразу после исполнения
		FLAG_DATA = 0u;
		SCH_LENGHT_PACKET=0;		
	  }

	 InOut[index1]=str[index_z];
	 SCH_LENGHT_PACKET++;//подсчитываем длинну пакета
		 
	if (( InOut[index1]==';')&&(FLAG_DATA==0u)&&(packet_flag==1))  {packet_flag=0;packet_ok=1u;FLAG_CW=1u;}
    
	if (((InOut[index1]=='=')||(InOut[index1]==':'))&&(data_flag==0)) {data_flag=1u;FLAG_CW=1u;}

	if (( InOut[index1]=='.')&&(data_flag2==0)&&(FLAG_DATA==0))   {data_flag2=1u; FLAG_CW=1u;}
	
	if (( InOut[index1]=='$')&&(FLAG_lenght==0u)) {FLAG_lenght=2u;FLAG_CW=1u;}
    
	if ((index1>2u)&&(InOut[2]==' ')&&(FLAG_CW==0u)&&(FLAG_lenght<2u))  
            {
                             if   (data_flag!=1u) {Word[index_word]=InOut[index1];} // заполняем командное слово
                      
                             if  ((data_flag==1u)&&(data_flag2==0u))     DATA_Word[index_data_word]=InOut[index1];// заполняем  слово данных1
                             if  ((data_flag==1u)&&(data_flag2==1u))     DATA_Word2[index_data_word2]=InOut[index1]; // заполняем  слово данных2
                    
                             if  (data_flag!=1u)
                                     {if (index_word<buf_Word) index_word++;} 
                                   else 
                                            {
                                             if ((data_flag==1u)&&(data_flag2==0u)) if (index_data_word<buf_DATA_Word)  {index_data_word++;sch_lenght_data++;}
                                            
                                             if ((data_flag==1u)&&(data_flag2==1u)) if (index_data_word2<buf_DATA_Word) index_data_word2++;
                                            }
			}
	
		if ((FLAG_lenght==2u)&&(FLAG_CW==0u)) {lenght_data = (u8)(InOut[index1]);FLAG_lenght=1u;} //запоминаем длинну пакета данных после ":"
	
		if ((sch_lenght_data<lenght_data)&&(FLAG_lenght==1u)) FLAG_DATA = 1u; else {FLAG_DATA = 0u;}
	 
		if (index1 <BUFFER_SR)  index1++;
		if (index_z<BUFFER_SR)  index_z ++;
		i--;
		FLAG_CW=0u;
		// Transf(".");
  }
 

if (packet_ok==1u) 
  {

   SCH_7ok_PAKET++;
   //Transf("ок\r\n");
     
      if (InOut[0]==0x7e)   crc_ok=crc_ok|0x1;   // проверка первого условия пакета - начало пакета
      if (InOut[1]==Adress) crc_ok=crc_ok|0x2;   // проверка второго условия пакета - адресат назначения
 
 
if (crc_ok==0x3)  //обработка команд адресатом которых является хозяин 
{


if (strcmp(Word,"b610_event")==0)                     
   {     
     crc_comp =atoi(DATA_Word);  
     u_out ("принял b610_event:",crc_comp   );
     zputc2(crc_comp);
   } else 
	   
if (strcmp(Word,"PWRD_WIZ")==0)                     
   {     
     crc_comp =atoi(DATA_Word);  
     u_out ("принял PWRD_WIZ:",crc_comp   );
     if (crc_comp==0) PWRD_WIZ_0;
     if (crc_comp==1) PWRD_WIZ_1;
   } else 

if (strcmp(Word,"rst_wiz")==0)                     
   {
     Transf ("принял rst_wiz\r"    );
     Transf("\r");  
     RST_WIZ_0;
     Delay(1);
     RST_WIZ_1;
   } else 
if (strcmp(Word,"eth_ichread")==0)                     
   {
     Transf ("принял eth_ichread\r"    );
     Transf("\r"); 
     crc_comp =atoi(DATA_Word);  
     x_out(":",IINCHIP_READ(crc_comp));
   } else 
if (strcmp(Word,"eth")==0)                     
   {
     Transf ("принял eth\r"    );
     Transf("\r");  
      Set_network();
      //UDP_test();
   } else 
if (strcmp(Word,"eth_test")==0)                     
   {
     Transf ("принял eth\r"    );
     crc_comp =atoi(DATA_Word);     
     x_out("data:",IINCHIP_READ(crc_comp));
   } else

if (strcmp(Word,"btn")==0)                     
   {
     Transf ("принял btn\r"    );
     Transf("\r");  
     x_out("BTN:",BTN_var);
   } else	
if (strcmp(Word,"help")==0)                     
   {
     Transf ("принял help\r"    );
     Transf("\r");  
     Menu1(0);
   } else
if (strcmp(Word,"help2")==0)                     
   {
     Transf ("принял help\r"    );
     Transf("\r");  
   } else
if (strcmp(Word,"info")==0)                     
   {
     Transf ("принял info\r"    );
     Transf("\r");  
     info();
   } else
	   
   if (strcmp(Word,"info_614")==0)                     
   {
     Transf ("принял info_614\r"    );
     Transf("\r");  
     Tester_info ();
   } else
	   
   if (strcmp(Word,"info_615")==0)                     
   {
     Transf ("принял info_k615\r"    );
     Transf("\r");  
     info_k615 ();
   } else	
						 
if (strcmp(Word,"menu")==0)                     
   {
     Transf ("принял menu\r"    );
     Transf("\r");  
     Menu1();
   } else							 
					 
if (strcmp(Word,"fpga_r")==0) //
   {
	crc_comp =atoi(DATA_Word);
	crc_input=atoi(DATA_Word2);
	un_out ("принял fpga_r:",crc_comp);
	u_out (".",crc_input);
	x_out ("data:",FPGA_rSPI (crc_comp,crc_input));
   } else
if (strcmp(Word,"fpga_w")==0) //
   {
	crc_comp =atoi(DATA_Word);
	crc_input=atoi(DATA_Word2);
			
	u_out ("принял fpga_w:",crc_comp);
	u_out ("",crc_input);
	FPGA_wSPI (crc_comp,crc_input,0xaabbccdd);
                       
    } else 
             
if (strcmp(Word,"test_spi_read")==0) //
   {
	crc_comp =atoi(DATA_Word);
	crc_input=atoi(DATA_Word2);
				
	u_out ("принял test_spi_read:",crc_comp);
	test_spi_read(crc_comp);
                       
   } else
				
if (strcmp(Word,"test_spi_write")==0) //
   {
	crc_comp =atoi(DATA_Word);
	crc_input=atoi(DATA_Word2);
				
	u_out ("принял test_spi_write:",crc_comp);
	test_spi_write(crc_comp);
                       
   } else
//----------------------------------------------------------------------------------------------				
if (strcmp(Word,"start")==0)                     
   {
     Transf ("принял start\r"    );
     Transf("\r");
     upr.MFI_regim=1;	 
     START_packet=0;
   } else
	   
if (strcmp(Word,"GBR")==0)                     
   {
	 crc_comp =atoi(DATA_Word);
	 u_out ("принял GBR:",crc_comp);
     upr.GBR=crc_comp;	 
     START_packet=0;
   } else
	   
if (strcmp(Word,"Pni1")==0) //
     {
		crc_comp =atoi(DATA_Word);		
		u_out ("принял Pni1:",crc_comp);
		upr.Pni1=crc_comp;                       
      } else
if (strcmp(Word,"Pii1")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pii1:",crc_comp);
		upr.Pii1=crc_comp;                       
      } else
if (strcmp(Word,"Pnp1")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pnp1:",crc_comp);
		upr.Pnp1=crc_comp;                       
      } else
if (strcmp(Word,"Pip1")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pip1:",crc_comp);
		upr.Pip1=crc_comp;                       
      } else
if (strcmp(Word,"QIT1")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял QIT1:",crc_comp);
		upr.QIT1=crc_comp;                       
      } else
		  
if (strcmp(Word,"Pni2")==0) //
     {
		crc_comp =atoi(DATA_Word);		
		u_out ("принял Pni2:",crc_comp);
		upr.Pni2=crc_comp;                       
      } else
if (strcmp(Word,"Pii2")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pii2:",crc_comp);
		upr.Pii2=crc_comp;                       
      } else
if (strcmp(Word,"Pnp2")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pnp2:",crc_comp);
		upr.Pnp2=crc_comp;                       
      } else
if (strcmp(Word,"Pip2")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pip2:",crc_comp);
		upr.Pip2=crc_comp;                       
      } else
if (strcmp(Word,"QIT2")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял QIT2:",crc_comp);
		upr.QIT2=crc_comp;                       
      } else
		  
if (strcmp(Word,"Pni3")==0) //
     {
		crc_comp =atoi(DATA_Word);		
		u_out ("принял Pni3:",crc_comp);
		upr.Pni3=crc_comp;                       
      } else
if (strcmp(Word,"Pii3")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pii3:",crc_comp);
		upr.Pii3=crc_comp;                       
      } else
if (strcmp(Word,"Pnp3")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pnp3:",crc_comp);
		upr.Pnp3=crc_comp;                       
      } else
if (strcmp(Word,"Pip3")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Pip3:",crc_comp);
		upr.Pip1=crc_comp;                       
      } else
if (strcmp(Word,"QIT3")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял QIT3:",crc_comp);
		upr.QIT3=crc_comp;                       
      } else
if (strcmp(Word,"N_temp")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял N_temp:",crc_comp);
		upr.N_temp=crc_comp;                       
      } else
if (strcmp(Word,"DDS_delay")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял DDS_delay:",crc_comp);
		upr.DDS_delay=crc_comp;                       
      } else
		  
if (strcmp(Word,"T_kalibrovka")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял T_kalibrovka:",crc_comp);
		upr.T_kalibrovka=crc_comp;                       
      } else
if (strcmp(Word,"T_pomeha")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял T_pomeha:",crc_comp);
		upr.T_pomeha=crc_comp;                       
      } else
if (strcmp(Word,"TNO")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял TNO:",crc_comp);
		upr.TNO=crc_comp;                       
      } else
if (strcmp(Word,"Avariya")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял Avariya:",crc_comp);
		upr.vAvariya=crc_comp; 
		INIT_MFI (upr.MFI_regim);
      } else
if (strcmp(Word,"TNI")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял TNI:",crc_comp);
		upr.vTNI=crc_comp;
		upr.MFI_regim=0;
	    INIT_MFI (upr.MFI_regim);  
      } else
if (strcmp(Word,"TKI")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял TKI:",crc_comp);
		upr.vTKI=crc_comp;
		upr.MFI_regim=0;
	    INIT_MFI (upr.MFI_regim); 
      } else
if (strcmp(Word,"TNP")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял TNP:",crc_comp);
		upr.vTNP=crc_comp;
		upr.MFI_regim=0;
	    INIT_MFI (upr.MFI_regim);
      } else
if (strcmp(Word,"TKP")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял TKP:",crc_comp);
		upr.vTKP=crc_comp;
		upr.MFI_regim=0;
	    INIT_MFI (upr.MFI_regim); 
      } else
		  
if (strcmp(Word,"615_test")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял K615_test:",crc_comp);
	
	    OUT_sig615_B660 (crc_comp); 
      } else
		  
if (strcmp(Word,"614_test")==0) //
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял 614_test:",crc_comp);
	
	    Tester_control (); 
      } else
		
if (strcmp(Word,"test_out")==0) //команда управляет тестовыми выходами , выводит туда требуемые пары сигналов
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял test_out:",crc_comp);
	
	    FPGA_wSPI(8,4,crc_comp); 
      } else
		  
if (strcmp(Word,"adc")==0) //команда управляет тестовыми выходами , выводит туда требуемые пары сигналов
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял adc:",crc_comp);
	    u_out("adc:",ADC (crc_comp)); 
      } else

		  
		  
//--------------------------------------------------
if (strcmp(Word,"eth_info")==0) //команда управляет тестовыми выходами , выводит туда требуемые пары сигналов
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял eth_info:",crc_comp);
	    ETH_info();
      } else
if (strcmp(Word,"eth_init")==0) //команда управляет тестовыми выходами , выводит туда требуемые пары сигналов
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял eth_init:",crc_comp);
	    Set_network(&eth1);
      } else	
if (strcmp(Word,"usb_rezerv")==0) //команда управляет тестовыми выходами , выводит туда требуемые пары сигналов
     {
		crc_comp =atoi(DATA_Word);
		u_out ("принял usb_rezerv:",crc_comp);
	    FPGA_wSPI(8,99,crc_comp);
      } else		  
//-----------------------------------------------------------------------------------------------
if (strcmp(Word,"ERROR_B610")==0)//принимаем подтверждение на ранее отосланную команду состояния
     {
       Transf("принял состояние Б610:");
       crc_comp =atoi(DATA_Word);
       if (crc_comp==0) {Transf("АВАРИЯ!\r\n");}
       if (crc_comp==1) {Transf("OK\r\n");}
      }  
 } 

 for (i=0u;i<buf_Word;i++)             Word[i]      =0x0;
 for (i=0u;i<(buf_DATA_Word+1);  i++)  DATA_Word [i]=0x0;
 for (i=0u;i<(buf_DATA_Word+1);  i++)  DATA_Word2[i]=0x0;  
 for (i=0u;i<BUFFER_SR;i++)  
      {
        InOut[i]     =0x0;
      }  
      
	  time_uart=0;  //обнуление счётчика тайм аута
      packet_flag=0; 
      index1=0u; 
      crc_ok=0; 
      i=0;
      packet_ok=0; 
      index_word=0u; 
      index_data_word=0u;
      data_flag=0;
      index_data_word2=0u;
      data_flag2=0;
      index_z =0u;
      FLAG_lenght=0u;
      lenght_data=0u;
      sch_lenght_data=0u;
      FLAG_CW = 0u; //флаг управляющего байта, снимается сразу после исполнения
      FLAG_DATA = 0u;	  
      	  
      DATA_Word [0]=' ';
      DATA_Word2[0]=' ';
	  SCH_LENGHT_PACKET=0;
  }

  if ((packet_ok==1)&&(crc_ok==0x1))     //обработка команд адресатом которых является слейв

  {
    
    if (Master_flag==0)

      {            
      
         // TX_485;
        
          Transf("\r\n");
          ZTransf (InOut,index1);
		  Transf("\r\n");

           rx_wr_index1=0u;
           rx_rd_index1=0u;
           rx_counter1 =0u;
      }
  }
         
 } 


 void WDG_func(void)
 {
  if (time_wdg<50) WDG_off;
  if (time_wdg>50) {WDG_on;   } 
  if (time_wdg>100) {time_wdg=0;} 
 }

 void UART_conrol (void)
{
  u16 i=0u;
  u16 j=0u;
  u8 FLAG_IO=0u;

 if (rx_counter1!=0u)
  {   
    if (rx_counter1<BUFFER_SR) j = rx_counter1; else j=BUFFER_SR;
	
	//Transf(".");

    for (i=0u;i<j; i++) 
     {
      srt[i]=getchar1();
      lenght=i+1;  
      if (srt[i]==';') {FLAG_IO=1;i=j;break;}
     }
	srt[lenght]=0x00;
	IO (srt);	
  };

}


 void LED_control (void)
 {
 	static u8 l;

  if (time_led1 == 100)
  {
	
/*	
	LED1_0;
	LED2_0;
	LED3_0;
	LED4_0;
	LED5_0;
	*/
  }
		 
  if (time_led1 == 50)
  {
/*	 	
	LED1_1;
	LED2_1;
	LED3_1;
	LED4_1;
	LED5_1;
	*/
	time_led1=0;
	  l=l<<1;
	
  }		 
		 
		 

   if (l&0x01) LED1_1; else LED1_0;
   if (l&0x02) LED2_1; else LED2_0; 
   if (l&0x04) LED3_1; else LED3_0;
   if (l&0x08) LED4_1; else LED4_0;
   if (l&0x10) LED5_1; else LED5_0;
   if (l&0x20) LED6_1; else LED6_0;
   if (l&0x40) LED7_1; else LED7_0;
   if (l&0x80) LED8_1; else LED8_0;
   
   if (l==0) l=1;

      WDG_func(); //функция контроля внешнего вочдога
 }

void spisend (unsigned int d) //32 бита
{
   SPI2_Send((d >> 24)&0xff);
   SPI2_Send((d >> 16)&0xff);
   SPI2_Send((d >>  8)&0xff);
   SPI2_Send((d)      &0xff);
}



void Menu1(char a)
 
 {
//***************************************************************************

    int i;
  
 
  for (i=0;i<20;i++) Transf("\r");    // очистка терминала
  for (i=0; i<20; i++) Transf ("-");  // вывод приветствия
  Transf("\r");
  Transf("..........Terminal Тестовой платы.........\r\n");
  Transf("\r");
  Transf("MENU :\r");
  Transf("-------\r");
  Transf("Расшифровка структуры команды:\r");
  Transf("~ - стартовый байт\r");
  Transf("1 - адрес абонента\r");
  Transf(";- конец пачки \r");
  Transf(".............. \r");
  Transf("---------------------------------------------\r\n");
  Transf("IP  :192.168.1.163 - IP адрес    блока\r");
  Transf("PORT:2054          - номер порта блока\r");
  Transf("~0 help; - текущее меню\r");
  Transf("~0 info; - информация о режиме работы имитатора\r");
  Transf("~0 start; запуск формирования сетки импульсов\r");
  Transf("~0 Pni1:100; интервал перед излучением для темпа 1 (мкс)\r");
  Transf("~0 Pii1:100; интервал излучения для темпа 1 (мкс)\r");
  Transf("~0 Pnp1:100; интервал перед приёмом для темпа 1 (мкс)\r");
  Transf("~0 Pip1:100; интервал приёма для темпа 1 (мкс)\r");
  Transf("~0 QIT1:1;   число импульсов в темпе 1\r");
  Transf("~0 Pni2:100; интервал перед излучением для темпа 2 (мкс)\r");
  Transf("~0 Pii2:100; интервал излучения для темпа 2 (мкс)\r");
  Transf("~0 Pnp2:100; интервал перед приёмом для темпа 2 (мкс)\r");
  Transf("~0 Pip2:100; интервал приёма для темпа 2 (мкс)\r");
  Transf("~0 QIT2:1;   число импульсов в темпе 2\r");
  Transf("~0 Pni3:100; интервал перед излучением для темпа 3 (мкс)\r");
  Transf("~0 Pii3:100; интервал излучения для темпа 3 (мкс)\r");
  Transf("~0 Pnp3:100; интервал перед приёмом для темпа 3 (мкс)\r");
  Transf("~0 Pip3:100; интервал приёма для темпа 3 (мкс)\r");
  Transf("~0 QIT3:1;   число импульсов в темпе 3\r");
  Transf("~0 N_temp:3; число темпов < или = 3\r");
  Transf("~0 DDS_delay:56; длительность интервала для подготовки DDS (мкс)\r");
  Transf("~0 T_kalibrovka:504; длительность интервала калибровки (мкс)\r");
  Transf("~0 T_pomeha:302; длительность интервала приёма помехи (мкс)\r");
  Transf("~0 TNO:4000000; длительность интервала ТНО (мкс)\r");
  Transf("~0 Avariya:1; импульсный сигнала <авария> подаётся на блок Б610 \r");
  Transf("~0 GBR:1;  сигнала <ГБР> или <БР> подаётся на блок Б610 \r");
 
  Transf("~0 TNI:1; постоянная еденица на сигнал ТНИ\r");
  Transf("~0 TKI:1; постоянная еденица на сигнал ТКИ\r");
  Transf("~0 TNP:1; постоянная еденица на сигнал ТНП\r");
  Transf("~0 TKP:1; постоянная еденица на сигнал ТКП\r");
  Transf("~0 b610_event:255; имитация состояний блока 610 для блока 660\r");
  
  Transf("~0 usb_rezerv:1; имитация состояния цепи резервирования (usb) 1-есть мастер , 0 - нет мастера \r");
  Transf("~0 615_test:65535; 65283(ок) 0xFFFF для проверки к615, имитация сигналов ФТ и т.д.\r");
  Transf("~0 614_test;для проверки к614,контроль выходных сигналов\r");
  Transf("~0 info_615; - информация о сигналах контроля для К615\r"); 
  Transf("~0 info_614; - информация о сигналах контроля для К614\r");
  Transf("~0 test_out:0; -тестовый вывод сигналов на разъёмы f5Mhz и T5min\r");
  Transf("1:ТНЦ|IntI 2:ТНЦ|IntP 3:IntI|IntP  4:TNO|ТНЦ   5:ТНЦ|TNP 6:ТНЦ|TKP \r");
  Transf("7:ТНЦ|TNI  8:ТНЦ|TKI  9:ТНЦ|Error 10:ТНЦ|TOBM 11:ТНЦ|(IntP|IntI)   \r");
  Transf("-------------------------------------------\r");
  Transf("\r");
  Transf("\r");
  Transf("++++++++++++++++++++\r");
  Transf("\r");
  Transf("\r");
  //for (i=0; i<64; i++) zputs ("*",1);  // вывод приветствия
  //for (i=0;i<10;i++) puts("\r",1);  // очистка терминала
  Transf("\r");
  //*******************************************************************************
}

u32 FPGA_wSPI (u8 size,u8 adr,u32 data)
{
   u8 d[4];
   u8 i,k;
   
   k=size/8;
    
   if (k==1)  d[3]=data;
   
   if (k==2) {d[2]=data;
			  d[3]=data>>8;
			  }
			  
   if (k==3) {d[1]=data;
			  d[2]=data>>8;
			  d[3]=data>>16;
			  }
   if (k==4) {d[0]=data;
			  d[1]=data>>8;
			  d[2]=data>>16;
			  d[3]=data>>24;
			  }
 	
   FPGA_CS_0;
 //  Delay(1);
 
   SPI2_Send (adr|0x80); //передаём адресс
   for (i=0;i<(size/8);i++)  SPI2_Send (d[3-i]);  //считываем данные
   
 //  Delay(1);  
   FPGA_CS_1;

   return 0;
}  
  
u32 FPGA_rSPI (u8 size,u8 adr)
{
   u8 d[4];
   u8 i,k;
   u8 adr_a=0;
   u32 value;
   
   k=size/8;
   adr_a=adr;
 	
   FPGA_CS_0;
//   Delay(1);
 
   SPI2_Send (adr_a); //
   for (i=0;i<(size/8);i++) d[i] = SPI2_Send (0);  //считываем данные
//   Delay(1);  
   FPGA_CS_1;
   
   if (k==1) value =   d[0];
   if (k==2) value =  (d[0]<< 8)+ d[1];
   if (k==3) value =  (d[0]<<16)+(d[1]<< 8)+ d[2];
   if (k==4) value =  (d[0]<<24)+(d[1]<<16)+(d[2]<<8)+d[3];
   

   return value;
}

void test_spi_read(u32 k)
{
	u32 i;
	u32 var;
	u32 error=0;
	
	UART_DMA_TX (); //отправка по DMA сообщений 
	
	for (i=0;i<k;i++)	
	{ var=FPGA_rSPI(32,30);
	  if (var!=0xdeedbeef) error++;
	}
	
	u_out("проведено:",k);
	Transf(" попыток\r\n");
	u_out("Число ошибок:",error);
}

void test_spi_write(u32 k)
{
	u32 i;
	u32 var;
	u32 error=0;
	
	UART_DMA_TX (); //отправка по DMA сообщений 
	
	for (i=0;i<k;i++)	
	{
		FPGA_wSPI(32,36,0xdeedbeef);//запись
		var=FPGA_rSPI(32,35);//чтение
	  if (var!=0xdeedbeef) error++;//проверка
	}
	u_out("проведено:",k);
	Transf(" попыток\r\n");
	u_out("Число ошибок:",error);
}

void  Tester_control ()
{
	u8 var=0;

	B660.TNI =(FPGA_rSPI(16,50)*1000)/64;//переводим в нС , так как подсчёт идёт на частоте 64 МГц
	B660.TNI1=(FPGA_rSPI(16,51)*1000)/64;
	B660.TKI =(FPGA_rSPI(16,52)*1000)/64;
	B660.T1_4=(FPGA_rSPI(16,53)*1000)/64;
	B660.TKI1=(FPGA_rSPI(16,54)*1000)/64;
	B660.TNP =(FPGA_rSPI(16,55)*1000)/64;
	B660.TKP =(FPGA_rSPI(16,56)*1000)/64;
	B660.TKP1=(FPGA_rSPI(16,57)*1000)/64;
	B660.TOBM=(FPGA_rSPI(16,58)*1000)/64;
	B660.TNC =(FPGA_rSPI(16,59)*1000)/64;
	B660.TNO =(FPGA_rSPI(16,60)*1000)/64;
	
	B660.Rezerv4 =FPGA_rSPI(32,61);
	B660.Rezerv  =FPGA_rSPI(32,62);
	B660.Rezerv1 =FPGA_rSPI(32,63);
	B660.Rezerv2 =FPGA_rSPI(32,64);
	B660.Rezerv3 =FPGA_rSPI(32,65);
	
	B660.int_I   =FPGA_rSPI(32,66)/4;// 1/4 так как считаем 4 мгц частотой
	B660.int_P   =FPGA_rSPI(32,67)/4;
	B660.int_TNC =FPGA_rSPI(32,68)/4;
	B660.int_TNO =FPGA_rSPI(32,69)/4;
	B660.control =FPGA_rSPI(24,70);

	var=FPGA_rSPI(8,1);

	B660.VKL_COM_FT = (var>>7)&0x01;
	B660.IN_FT50OM  = (var>>5)&0x01;
	
	
	if (B660.TNI>B660.TNI_max) B660.TNI_max=B660.TNI;
	if (B660.TNI<B660.TNI_min) B660.TNI_min=B660.TNI;
	
	if (B660.TNI1>B660.TNI1_max) B660.TNI1_max=B660.TNI1;
	if (B660.TNI1<B660.TNI1_min) B660.TNI1_min=B660.TNI1;
	
	if (B660.TKI>B660.TKI_max) B660.TKI_max=B660.TKI;
	if (B660.TKI<B660.TKI_min) B660.TKI_min=B660.TKI;
	
	if (B660.T1_4>B660.T1_4_max) B660.T1_4_max=B660.T1_4;
	if (B660.T1_4<B660.T1_4_min) B660.T1_4_min=B660.T1_4;
	
	if (B660.TKI1>B660.TKI1_max) B660.TKI1_max=B660.TKI1;
	if (B660.TKI1<B660.TKI1_min) B660.TKI1_min=B660.TKI1;
	
	if (B660.TNP>B660.TNP_max) B660.TNP_max=B660.TNP;
	if (B660.TNP<B660.TNP_min) B660.TNP_min=B660.TNP;
	
	if (B660.TKP>B660.TKP_max) B660.TKP_max=B660.TKP;
	if (B660.TKP<B660.TKP_min) B660.TKP_min=B660.TKP;
	
	if (B660.TKP1>B660.TKP1_max) B660.TKP1_max=B660.TKP1;
	if (B660.TKP1<B660.TKP1_min) B660.TKP1_min=B660.TKP1;
	
	if (B660.TOBM>B660.TOBM_max) B660.TOBM_max=B660.TOBM;
	if (B660.TOBM<B660.TOBM_min) B660.TOBM_min=B660.TOBM;
	
	if (B660.TNC>B660.TNC_max) B660.TNC_max=B660.TNC;
	if (B660.TNC<B660.TNC_min) B660.TNC_min=B660.TNC;
	
	if (B660.TNO>B660.TNO_max) B660.TNO_max=B660.TNO;
	if (B660.TNO<B660.TNO_min) B660.TNO_min=B660.TNO;
	
	if (B660.Rezerv4>B660.Rezerv4_max) B660.Rezerv4_max=B660.Rezerv4;
	if (B660.Rezerv4<B660.Rezerv4_min) B660.Rezerv4_min=B660.Rezerv4;
	
	if (B660.Rezerv>B660.Rezerv_max) B660.Rezerv_max=B660.Rezerv;
	if (B660.Rezerv<B660.Rezerv_min) B660.Rezerv_min=B660.Rezerv;
	
	if (B660.Rezerv1>B660.Rezerv1_max) B660.Rezerv1_max=B660.Rezerv1;
	if (B660.Rezerv1<B660.Rezerv1_min) B660.Rezerv1_min=B660.Rezerv1;
	
	if (B660.Rezerv2>B660.Rezerv2_max) B660.Rezerv2_max=B660.Rezerv2;
	if (B660.Rezerv2<B660.Rezerv2_min) B660.Rezerv2_min=B660.Rezerv2;
	
	if (B660.Rezerv3>B660.Rezerv3_max) B660.Rezerv3_max=B660.Rezerv3;
	if (B660.Rezerv3<B660.Rezerv3_min) B660.Rezerv3_min=B660.Rezerv3;
	
if (B660.int_I!=0) //костыль против 0 длительности интервала Излучения
 {
	if (B660.int_I>B660.int_I_max) B660.int_I_max=B660.int_I;
	if (B660.int_I<B660.int_I_min) B660.int_I_min=B660.int_I;
 }
	
	if (B660.int_P>B660.int_P_max) B660.int_P_max=B660.int_P;
	if (B660.int_P<B660.int_P_min) B660.int_P_min=B660.int_P;
	
	if (B660.int_TNC>B660.int_TNC_max) B660.int_TNC_max=B660.int_TNC;
	if (B660.int_TNC<B660.int_TNC_min) B660.int_TNC_min=B660.int_TNC;
	
	if (B660.int_TNO>B660.int_TNO_max) B660.int_TNO_max=B660.int_TNO;
	if (B660.int_TNO<B660.int_TNO_min) B660.int_TNO_min=B660.int_TNO;
	
		
}

void Tester_info ()
{
	
	Transf("Контроль выходных сигналов блока Б660\r\n");
	
	rst_imp_tester_1; //обнуляем ряд считанных данных
	
//	x_out("control:",B660.control);
	
	if (B660.control&0x000001) Transf("Есть Rezerv3\r\n"); else Transf("нет Rezerv3\r\n");
	if (B660.control&0x000002) Transf("Есть Rezerv2\r\n"); else Transf("нет Rezerv2\r\n");
	if (B660.control&0x000004) Transf("Есть Rezerv1\r\n"); else Transf("нет Rezerv1\r\n");
	if (B660.control&0x000008) Transf("Есть Rezerv \r\n"); else Transf("нет Rezerv \r\n");
	if (B660.control&0x000010) Transf("Есть Rezerv4\r\n"); else Transf("нет Rezerv4\r\n");
	if (B660.control&0x000020) Transf("Есть ТНО\r\n");  else Transf("нет ТНО\r\n");
	if (B660.control&0x000040) Transf("Есть ТНЦ\r\n");  else Transf("нет ТНЦ\r\n");
	if (B660.control&0x000080) Transf("Есть ТОБМ\r\n"); else Transf("нет ТОБМ\r\n");
	if (B660.control&0x000100) Transf("Есть ТКП1\r\n"); else Transf("нет ТКП1\r\n");
	if (B660.control&0x000200) Transf("Есть ТКП\r\n");  else Transf("нет ТКП\r\n");
	if (B660.control&0x000400) Transf("Есть ТНП\r\n");  else Transf("нет ТНП\r\n");
	if (B660.control&0x000800) Transf("Есть ТКИ1\r\n"); else Transf("нет ТКИ1\r\n");
	if (B660.control&0x001000) Transf("Есть Т1_4\r\n"); else Transf("нет Т1_4\r\n");
	if (B660.control&0x002000) Transf("Есть ТКИ\r\n");  else Transf("нет ТКИ\r\n");
	if (B660.control&0x004000) Transf("Есть ТНИ1\r\n"); else Transf("нет ТНИ1\r\n");
	if (B660.control&0x008000) Transf("Есть ТНИ\r\n");  else Transf("нет ТНИ\r\n");
	if (B660.control&0x010000) Transf("Ошибка интервала И/П !\r\n");
	if (B660.control&0x020000) Transf("Ошибка формирования импульса ТНП !\r\n");
	if (B660.control&0x040000) Transf("Ошибка формирования импульса ТНИ !\r\n");
	if (B660.control&0x080000) Transf("Интервал ТНЦ короче     256 мкс  !\r\n");
	if (B660.control&0x100000) Transf("Интервал ОБЗОР короче 1 секунды  !\r\n");
	
	Transf("--------------------------------\r\n");
	Transf("в нС\r\n");	
	un_out("TNI_max  :",B660.TNI_max);
	u_out("\tTNI_min  :",B660.TNI_min);
	un_out("TNI1_max :",B660.TNI1_max);
    u_out("\tTNI1_min :",B660.TNI1_min);	
	un_out("TKI_max  :",B660.TKI_max);
	u_out("\tTKI_min  :",B660.TKI_min);
	un_out("T1_4_max :",B660.T1_4_max);
	u_out("\tT1_4_min :",B660.T1_4_min);
	Transf("\r\n");
	un_out("TKI1_max :",B660.TKI1_max);
	u_out("\tTKI1_min :",B660.TKI1_min);
	un_out("TNP_max  :",B660.TNP_max);
	u_out("\tTNP_min  :",B660.TNP_min);
	un_out("TKP_max  :",B660.TKP_max);
	u_out("\tTKP_min  :",B660.TKP_min);
	Transf("\r\n");
	un_out("TKP1_max :",B660.TKP1_max);
	u_out("\tTKP1_min :",B660.TKP1_min);
	un_out("TOBM_max :",B660.TOBM_max);
	u_out("\tTOBM_min :",B660.TOBM_min);
	Transf("\r\n");
	un_out("TNC_max  :",B660.TNC_max);
	u_out("\tTNC_min  :",B660.TNC_min);
	un_out("TNO_max  :",B660.TNO_max);
	u_out("\tTNO_min  :",B660.TNO_min);
	
	Transf("------------------------------\r\n");
	
	un_out("Rezerv4_max :",B660.Rezerv4_max);
	u_out("\tRezerv4_min :",B660.Rezerv4_min);
	
	un_out("Rezerv_max  :",B660.Rezerv_max);
	u_out("\tRezerv_min  :",B660.Rezerv_min);
	
	un_out("Rezerv1_max :",B660.Rezerv1_max);
	u_out("\tRezerv1_min :",B660.Rezerv1_min);
	
	un_out("Rezerv2_max :",B660.Rezerv2_max);
	u_out("\tRezerv2_min :",B660.Rezerv2_min);
	
	un_out("Rezerv3_max :",B660.Rezerv3_max);
	u_out("\tRezerv3_min :",B660.Rezerv3_min);
	
	Transf("------------------------------\r\n");
	Transf("в мкС\r\n");	
	un_out("int_I_max   :",B660.int_I_max);
	u_out("\tint_I_min   :",B660.int_I_min);
	
	un_out("int_P_max   :",B660.int_P_max);
	u_out("\tint_P_min   :",B660.int_P_min);
	
	un_out("int_TNC_max :",B660.int_TNC_max);
	u_out("\tint_TNC_min :",B660.int_TNC_min);
	
	un_out("int_TNO_max :",B660.int_TNO_max);
	u_out("\tint_TNO_min :",B660.int_TNO_min);
	
	Transf("------------------\r\n");
	
	un_out("TNC24_max :",B660.TNC24_max);
	u_out("\tTNC24_min :",B660.TNC24_min);
	
	un_out("TNO24_max :",B660.TNO24_max);
	u_out("\tTNO24_min :",B660.TNO24_min);
    Transf("\r\n");
	un_out("VKL_COM_FT:",B660.VKL_COM_FT);
	u_out("\tIN_FT50OM :",B660.IN_FT50OM);
	Transf("\r\n");
	u_out("ADC_I :",B660.ADC_I);
	u_out("ADC_P :",B660.ADC_P);
	
	init_b660();//сброс мах и мин критериев
	rst_imp_tester_0; //обнуляем ряд считанных данных
}


void INIT_MFI (char l)
{
//-------------------------------------------
//инициализация транспортныых индексов и флага состояния пакета импульсов
   TNC_actual  =0; //текущий ТНЦ	
// TNO_actual  =0; //текущий ТНО
// CEV_actual  =0; //текущий СЕВ
 
  START_packet=1;
  Alfa=0;
  
  char z=0;
  
  z=z|((upr.vAvariya &0x01)<<7)
	 |((    upr.vTNI &0x01)<<6)
	 |((    upr.vTKI &0x01)<<5)
	 |((    upr.vTNP &0x01)<<4)
	 |((    upr.vTKP &0x01)<<3)
	 |((    upr.GBR  &0x01)<<2)
	 |((    upr.temp1&0x01)<<1)
	 |((    upr.temp2&0x01)<<0);

  FPGA_wSPI(8,3,z); 
  x_out("z:",z);

if (l==1)
{
	
  upr.CMND=0x0001ffff;//разрешает формирование импульсной сетки
 
  RCV_0;
  
  FPGA_wSPI(32,10,8*upr.Pni1);
  FPGA_wSPI(32,11,8*upr.Pii1);
  FPGA_wSPI(32,12,8*upr.Pnp1);
  FPGA_wSPI(32,13,8*upr.Pip1);
  FPGA_wSPI(16,14,  upr.QIT1);
  
  FPGA_wSPI(32,15,8*upr.Pni2);
  FPGA_wSPI(32,16,8*upr.Pii2);
  FPGA_wSPI(32,17,8*upr.Pnp2);
  FPGA_wSPI(32,18,8*upr.Pip2);
  FPGA_wSPI(16,19,  upr.QIT2);
  
  FPGA_wSPI(32,20,8*upr.Pni3);
  FPGA_wSPI(32,21,8*upr.Pii3);
  FPGA_wSPI(32,22,8*upr.Pnp3);
  FPGA_wSPI(32,23,8*upr.Pip3);
  FPGA_wSPI(16,24,  upr.QIT3);
  
  FPGA_wSPI(16,26,8*upr.DDS_delay);
  FPGA_wSPI(32,27,8*upr.T_kalibrovka);
  FPGA_wSPI(32,28,8*upr.T_pomeha);
  FPGA_wSPI( 8,25,  upr.N_temp);
  
  FPGA_wSPI(32,29,8*upr.TNO);
  FPGA_wSPI(32,30,  upr.CMND);//отправляем командное слово
  
  RCV_1;
  
  Transf("импульсный режим\r\n");
} else
	if (l==0)
		{	
		  upr.CMND=0x0000ffff;//запрещает формирование импульсной сетки
		  
		  RCV_0;
		  FPGA_wSPI(32,30,  upr.CMND);//отправляем командное слово
		  RCV_1;
		  Transf("режим постоянных сигналов\r\n");
		}
}

void info_k615 ()
{
	Transf("\r\nСигналы для К615\r\n");
	Transf("----------------\r\n");
	u_out("AVARIA_PIT_1_FT  :",upr.vAVARIA_PIT_1_FT);
	u_out("AVARIA_PIT_2_FT  :",upr.vAVARIA_PIT_2_FT);
	u_out("   NORM_PIT_2FT  :",upr.vNORM_PIT_2FT);
	u_out("   NORM_PIT_1FT  :",upr.vNORM_PIT_2FT);
	u_out("    RAB_KAN_1FT  :",upr.vRAB_KAN_1FT);
	u_out("    RAB_KAN_2FT  :",upr.vRAB_KAN_2FT);
	u_out("    RAB_KAN_3FT  :",upr.vRAB_KAN_3FT);
	u_out("    RAB_KAN_4FT  :",upr.vRAB_KAN_4FT);
	u_out("AVARIA_KAN_4_FT  :",upr.AVARIA_KAN_4_FT);
	u_out("AVARIA_KAN_3_FT  :",upr.AVARIA_KAN_3_FT);
	u_out("AVARIA_KAN_2_FT  :",upr.AVARIA_KAN_2_FT);
	u_out("AVARIA_KAN_1_FT  :",upr.AVARIA_KAN_1_FT);
	u_out("NORMA_TEMP_1U07FI:",upr.NORMA_TEMP_1U07FI);
	u_out("       PA_1U07_FI:",upr.PA_1U07_FI);
}


void info ()
{

if (upr.CMND==0x0000ffff) 
{
	Transf("Режим постоянных сигналов\r\n");
	u_out("Avariya:",upr.vAvariya);
	u_out("   TNI:",upr.vTNI);
	u_out("   TKI:",upr.vTKI);
	u_out("   TNP:",upr.vTNP);
	u_out("   TKP:",upr.vTKP);
	u_out("   GBR:",upr.GBR);
	u_out(" temp1:",upr.temp1);
	u_out(" temp2:",upr.temp2);
	
} else
	
if (upr.CMND!=0x0000ffff) 
 {
	 
	Transf("Режим формирования импульсов\r\n");
	
	u_out("Pni1:",upr.Pni1);
	u_out("Pii1:",upr.Pii1);
	u_out("Pnp1:",upr.Pnp1);
	u_out("Pip1:",upr.Pip1);
	
	if (upr.N_temp>1)
	{
		Transf("\r\n");
		u_out("Pni2:",upr.Pni2);
		u_out("Pii2:",upr.Pii2);
		u_out("Pnp2:",upr.Pnp2);
		u_out("Pip2:",upr.Pip2);
	}

	if (upr.N_temp>2)
	{
		Transf("\r\n");
		u_out("Pni3:",upr.Pni3);
		u_out("Pii3:",upr.Pii3);
		u_out("Pnp3:",upr.Pnp3);
		u_out("Pip3:",upr.Pip3);
	}

	Transf("\r\n");
	u_out("T_kalibrovka:",upr.T_kalibrovka);
	u_out("T_pomeha    :",upr.T_pomeha);
	u_out("DDS_delay   :",upr.DDS_delay);
	
	u_out("TNO:",upr.TNO);
    Transf("-----------\r\n");	
	u_out("time TNC:",(FPGA_rSPI (32,32))/8);
	u_out("time TNO:",(FPGA_rSPI (32,31))/8);
//	u_out("TNC_actual:",TNC_actual);
//	u_out("TNO_actual:",TNO_actual);
 }
}

void Cntr_TNC_TNO_24V ()
{
	B660.TNC24 =FPGA_rSPI(32,38);
	B660.TNO24 =FPGA_rSPI(32,37);

	if (B660.TNC24>B660.TNC24_max) B660.TNC24_max=B660.TNC24;
	if (B660.TNC24<B660.TNC24_min) B660.TNC24_min=B660.TNC24;
	
	if (B660.TNO24>B660.TNO24_max) B660.TNO24_max=B660.TNO24;
	if (B660.TNO24<B660.TNO24_min) B660.TNO24_min=B660.TNO24;
}

void OUT_sig615_B660 (u16 a)
{

//~0 615_test:65283;всё ок

u16 z=0;

upr.vAVARIA_PIT_1_FT =(a>>15)&0x01;
upr.vNORM_PIT_2FT    =(a>>14)&0x01;
upr.vNORM_PIT_1FT    =(a>>13)&0x01;
upr.vAVARIA_PIT_2_FT =(a>>12)&0x01;
upr.vRAB_KAN_1FT     =(a>>11)&0x01;
upr.vRAB_KAN_2FT     =(a>>10)&0x01;
upr.vRAB_KAN_3FT     =(a>> 9)&0x01;
upr.vRAB_KAN_4FT     =(a>> 8)&0x01;
upr.AVARIA_KAN_4_FT  =(a>> 7)&0x01;
upr.AVARIA_KAN_3_FT  =(a>> 6)&0x01;
upr.AVARIA_KAN_2_FT  =(a>> 5)&0x01;
upr.AVARIA_KAN_1_FT  =(a>> 4)&0x01;
upr.NORMA_TEMP_1U07FI=(a>> 1)&0x01;
upr.PA_1U07_FI       =(a>> 0)&0x01;

z=z
	|upr.vAVARIA_PIT_1_FT<<15
	|upr.vAVARIA_PIT_2_FT<<12
	|upr.vNORM_PIT_2FT<<14
	|upr.vNORM_PIT_1FT<<13
	|upr.vRAB_KAN_1FT<<11
	|upr.vRAB_KAN_2FT<<10
	|upr.vRAB_KAN_3FT<<9
	|upr.vRAB_KAN_4FT<<8
	|upr.AVARIA_KAN_4_FT<<7
	|upr.AVARIA_KAN_3_FT<<6
	|upr.AVARIA_KAN_2_FT<<5
	|upr.AVARIA_KAN_1_FT<<4
	|upr.NORMA_TEMP_1U07FI<<1
	|upr.PA_1U07_FI;

	 FPGA_wSPI(16,2,a);
	 
	  info_k615 ();
}

u8 BTN_control ()
{
 u8 v[7];
	
	v[0]=0x1&GPIO_ReadInputDataBit (GPIOC,GPIO_Pin_7 ); //проверка положения переключателя SA8
	v[1]=0x1&GPIO_ReadInputDataBit (GPIOC,GPIO_Pin_8 ); //проверка положения переключателя SA7
	v[2]=0x1&GPIO_ReadInputDataBit (GPIOC,GPIO_Pin_9 ); //проверка положения переключателя SA6
	v[3]=0x1&GPIO_ReadInputDataBit (GPIOA,GPIO_Pin_8 ); //проверка положения переключателя SA5
	v[4]=0x1&GPIO_ReadInputDataBit (GPIOA,GPIO_Pin_11); //проверка положения переключателя SA4
	v[5]=0x1&GPIO_ReadInputDataBit (GPIOA,GPIO_Pin_12); //проверка положения переключателя SA3
	v[6]=0x1&GPIO_ReadInputDataBit (GPIOB,GPIO_Pin_5 ); //проверка положения переключателя SA2
	v[7]=0x1&GPIO_ReadInputDataBit (GPIOC,GPIO_Pin_6 ); //проверка положения переключателя SA1
	
	return ((v[7]<<7)+(v[6]<<6)+(v[5]<<5)+(v[4]<<4)+(v[3]<<3)+(v[2]<<2)+(v[1]<<1)+v[0]); 
}

int UDP_test(void)
{  
 
    //loopback_tcps(1, 5000);
   //   loopback_udp (0, 3001,1);
    //loopback_udp (7, 3002); 
    
    //loopback_tcps(1, 5001);
    //loopback_tcps(2, 5002);
    //loopback_tcps(1, 5003);   
    //loopback_tcpc(4, 5004);              
    //loopback_udp (5, 3000);
 //     TELNETS(1, 23);
       return 1;  
}

void Ethernet_MU (void)

{
   UDP_test();
   /*
 if (flag_RX_UDP==1)  
      {
      if (RX_resive_MAX<lsr_razmer)  RX_resive_MAX=lsr_razmer;
      if (lsr_razmer < 10u) Time_SEV_INF (RX_BUF,lsr_razmer); //если пришла маленькая пачка - там СЕВ
        else KUK_IO(RX_BUF,lsr_razmer); //  если большая - там рабочий пакет
         
       TIMER_UDP_LS_DOWN=0;//обнуляем счётчик таймаута UDP линии связи
         flag_RX_UDP=0;
       }
       */
}

#define buf_n (2048+3)  //(стартовый байт и финальный 0)

void test_packet (char l)
{
	char     a[buf_n];
	short  cos[buf_n];
	int i=0;
	float f=0.1f;//2.4 Mhz for 240 Fs
	float x,y;
    char odd=0;	
	short z;
	short k=0;
	char hb,lb;
	float noise;
	
	float var_pi=3.14159265359f;
//-----------------------------	
	for  (i=0;i<buf_n;i++) a[i]=0x00;//очищаем фильтр
//--------преамбула------------	
	a[0]=0x23; //код #
	a[1]=0x0A; //код 0x0A '\n'
	a[2]=0x3A; //код 0x0A ':'
	
	k=3;

	if (l=='s') //синус
	{
		for (i=0;i<(buf_n-3)/2;i++) 
		{
			noise=rand() % 1000;
			x=2*var_pi*f*i;
			y=sin(x)*32000+noise;
			z=(short)y;
			//z=i;
			hb=z>>8;
			lb=z&0xff;
			
			a[k++]=hb;
			a[k++]=lb;
			
			//a[k++]=k;
			//a[k++]=k;
		}
	}
	

		
	if (l=='r') //числа
	{
		for (i=0;i<(buf_n-3)/2;i++) 
		{
			
			hb=i>>8;
			lb=i&0xff;
			
			a[k++]=hb;
			a[k++]=lb;

		}

	}
	
	a[buf_n-1]=0x00;
	Buf_send(a,buf_n);
	
//	Transf("\r\n");
//	u_out("i=",i);
	
}

int main(void)
{
    int i;
  
    init_RCC   ();
    init_GPIO  ();
    init_USART1();
    init_USART2();
    init_ADC   ();
//  init_TIM   ();
    init_EXT   ();
    init_SPI2   ();

 // _enable_irq ();

    CS_WIZ_1;
    RST_WIZ_0;

 	  Transf("\r\n");
    Transf("------");
    Transf("\r\n");
    Transf("работаем!\r\n");
    Transf("------");
    Transf("\r\n");

    Menu1(0);
	
//-----------ИНИЦИАЛИЗАЦИЯ-------------
init_b660();

START_packet=0;	
FLAG_START=0;
	 
upr.Pni1=120;
upr.Pii1=19419;
upr.Pnp1=112;
upr.Pip1=19420;
upr.QIT1=1;//число импульсов первого типа в одном темпе

upr.Pni2=120;
upr.Pii2=2000;
upr.Pnp2=112;
upr.Pip2=2000;
upr.QIT2=0;

upr.Pni3=120;
upr.Pii3=3000;
upr.Pnp3=112;
upr.Pip3=3000;
upr.QIT3=0;

upr.DDS_delay=56;
upr.T_kalibrovka=304;
upr.T_pomeha=512;
upr.N_temp=1;
upr.TNO = 4000000; //4 сек
upr.CMND=0x0001ffff;//разрешает формирование и сбрасывает счётчик часов в ноль, для немедленного старта формирования сетки
//----------------------------------------
//для проверки к615

upr.vAVARIA_PIT_1_FT=1;
upr.vAVARIA_PIT_2_FT=1;
upr.vNORM_PIT_2FT=1;
upr.vNORM_PIT_1FT=1;
upr.vRAB_KAN_1FT=1;
upr.vRAB_KAN_2FT=1;
upr.vRAB_KAN_3FT=1;
upr.vRAB_KAN_4FT=1;
upr.AVARIA_KAN_4_FT=1;
upr.AVARIA_KAN_3_FT=1;
upr.AVARIA_KAN_2_FT=1;
upr.AVARIA_KAN_1_FT=1;
upr.NORMA_TEMP_1U07FI=1;
upr.PA_1U07_FI=1;
upr.MFI_regim=1;

//--------------------------
PB15_1;
PB13_1;

state_INT5=0;
state_INT6=0;

 Massiv_dbm(1); //расчёт массива ДБ для детектора


 RST_WIZ_1;
/*
 for (i=0;i<1000;i++) 
  {
    delay_us(1000);
    Delay(20);
  }
*/
IO("SPI2_Send"); //проверка SPI , зачемто это надо для ETHernet-a

//Set_network();
//UDP_test();

int FLAG_TX_TEST=0;

while(1)
 {
  
    if (START_packet==0) INIT_MFI(upr.MFI_regim);
//--------------------------------------

	if (state_INT5==1) {state_INT5=0; Tester_control ();Cntr_TNC_TNO_24V ();}
	if (state_INT6==1) {state_INT6=0; B660.ADC_I=ADC(14);}
	if (state_INT7==1) {state_INT7=0; B660.ADC_P=ADC(15);}
    
	BTN_var=BTN_control ();
	   
	if (BTN_temp!=BTN_var) 
	{
		/*IO("~0 btn;");*/
		BTN_temp=BTN_var;
		if (BTN_temp==0x40) {if (FLAG_TX_TEST==1) FLAG_TX_TEST=0; else  FLAG_TX_TEST=1;}
		if (BTN_temp==0x80) {if (FLAG_TX_TEST==2) FLAG_TX_TEST=0; else  FLAG_TX_TEST=2;}
	}
   
	if ((timer_test==0)&&(FLAG_TX_TEST==1)) {test_packet ('s');timer_test=5;}
	if ((timer_test==0)&&(FLAG_TX_TEST==2)) {test_packet ('r');timer_test=5;}
	 
//----------------UART------------------
      UART_conrol ();
      UART_DMA_TX (); //отправка по DMA сообщений 
//---------------------------------------------        
      LED_control (); // управление индикаторными светодиодами
      WDG_func(); //функция контроля внешнего вочдога
//-----------------------------------------------------------------------
//      Ethernet_MU ();
//---------------------      
 
  }
}

