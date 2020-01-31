`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:24:57 02/22/2018 
// Design Name: 
// Module Name:    top_modul 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module top_modul(
    input clk,
	input clk_50MHZ,
	
	input IN_TNI_3V3_XP1,
	input IN_TNI_1_3V3_XP1,
	input IN_TKI_3V3_XP1,
	input IN_T1_4_3V3_XP1,
	input IN_TKI_1_3V3_XP1,
	input IN_TNP_3V3_XP1,
	input IN_TKP_3V3_XP1,
	input IN_TKP1_3V3_XP1,
	
	output OUT_REZERV1_3V3_XP2,
	output OUT_REZERV2_3V3_XP2,
	output OUT_REZERV3_3V3_XP2,
	output OUT_F_5MHZ_ETALON_3V3,
	output OUT_T5MIN_60SEC_3V3,
	output OUT_TEST1_3V3,
	output OUT_TEST2_3V3,
	output OUT_TEST3_3V3,
	
	input IN_TOBM_3V3_XP1,
	input IN_TNC_3V3_XP1,
	input IN_TNO_3V3_XP1,
	input IN_REZERV4_3V3_XP1,
	input IN_REZERV_3V3_XP1,
	input IN_REZERV1_3V3_XP1,
	input IN_REZERV2_3V3_XP1,
	input IN_REZERV3_3V3_XP1,
	
	output INT8,
	output INT9,
	output INTa,
	output OUT_TKI_1_3V3_XP2,
	output OUT_TNP_3V3_XP2,
	output OUT_TKP_3V3_XP2,
	output OUT_TKP1_3V3_XP2,
	output OUT_TOBM_3V3_XP2,
	output OUT_TNC_3V3_XP2,
	output OUT_TNO_3V3_XP2,
	output OUT_REZERV4_3V3_XP2,
	output OUT_REZERV_3V3_XP2,
	output OUT_TX_3V3_XP1,
	output OUT_REZERV5_3V3_XP1,
	output OUT_TNI_3V3_XP2,
	output OUT_TKI_3V3_XP2,
	output OUT_T1_4_3V3_XP2,
	output OUT_TKI1_3V3_XP2,
	
	input  MOSI_MK,
	output MISO_MK,
	input  CS_FPGA_MK,
	input  SCLK_MK,
	
	output USART2_RX,
	input  USART2_TX,
	
	input  USART3_TX,
	output USART3_RX,
	
	output PWDWN_ETHERNET_PLIS,
	output RESET_WIZ,
	input  INT_W5100,
	output MOSI_W5100,
	input  MISO_W5100,
	output SCLK_W5100,
	output CS_W5100,
	
	output INT1,
	output INT2,
	output INT3,
	output INT4,
	output INT5,
	output INT6,
	output INT7,
	
	output RTS_485,
	
	input  IN_VKL_COM_FT_3V3,
	input  IN_REZERV_1_UPR_3V3,
	input  IN_TEST1_3V3,
	input  IN_TEST2_3V3,
	input  IN_FT50OM_3V3,
	input  IN_TNC24V_3V3,
	input  CS_WIZ,
	input  IN_SYNC1_3V3,
	input  IN_SYNC2_3V3,
	input  IN_TNO24V_3V3,
	input  IN_REZERV_2_UPR_3V3,
	
	output OUT_AVARIA_PIT_1_FT_3V3,
	output OUT_NORM_PIT_2FT_3V3,
	output OUT_NORM_PIT_1FT_3V3,
	output OUT_AVARIA_PIT_2_FT_3V3,
	output OUT_RAB_KAN_1FT_3V3,
	output OUT_RAB_KAN_2FT_3V3,
	output OUT_RAB_KAN_3FT_3V3,
	output OUT_RAB_KAN_4FT_3V3,
	output OUT_AVARIA_KAN_4_FT_3V3,
	
	input  TX_FTDI_1,
	output RX_FTDI_1,
	input  RESET_MK_FTDI,
	input  BOOT0_FTDI,
	output BOOT0_FPGA,
	output RESET_MK,
	input  BOOT_TX_MK,
	output BOOT_RX_MK,
	
	output OUT_AVARIA_KAN_3_FT_3V3,
	output OUT_AVARIA_KAN_2_FT_3V3,
	output OUT_AVARIA_KAN_1_FT_3V3,
	output OUT_REZERV_KONTR_2_3V3,
	output OUT_REZERV_KONTR_1_3V3,
	output OUT_NORMA_TEMP_1U07FI_3V3,
	output OUT_PA_1U07_FI_3V3,
	output OUT_REZERV_KONTR_4_3V3,
	output OUT_REZERV_KONTR_3_3V3,
	output OUT_TNI_1_3V3_XP2,
	
	output DEBAG_PWM1,
	output DEBAG_PWM2,
	output SRAM_A17,
	
	output MK_DATA0,
	output MK_DATA1,
	output MK_DATA2,
	output MK_DATA3,
	output MK_DATA4,
	output MK_DATA5,
	output MK_DATA6,
	output MK_DATA7,
	output MK_DATA8,
	
	input DATA_PD8,
	input DATA_PD9,
	input DATA_PD10,
	input DATA_PD11,
	input DATA_PD12,
	input DATA_PD13,
	input DATA_PD14,
	input DATA_PD15,
	
	output OUT_CONTROL_K2_3V3,
	output OUT_CONTROL_K1_3V3,
	output RE_485,
	output RXD_FTDI_2,
	input  TXD_FTDI_2,
	
	output RESET_RS485,
	input  RX_485_MG,
	output TX_485_MG

    );
	 


wire clk5mhz;
wire clk20mhz;
wire clk32mhz;
wire clk1us;
wire dcm_locked;
wire reset_dcm;
wire f64MHz_1;
wire wsync_t5min;

reg [31:0] accum=0;



test_led tst_led1(clk20mhz,DEBAG_PWM1,DEBAG_PWM2,SRAM_A17); //светодиоды

modul_t5min sync_t5min(   //модуль формирует прерывание каждые 20 секунд для синхронизации часов
.clk(clk20mhz) ,
.t1us(clk1us) ,
.t5min(wsync_t5min)
 );

wire ERROR5Mhz;
wire ERROR64Mhz;

//модуль формирования 1/8 мкс и проверки наличия основных частот
control_F5_F64 MF1US_controlCLK(
.f5(clk5mhz),
.f64(clk32mhz),
.clk(clk20mhz),
.ERROR_5(ERROR5Mhz),
.ERROR_64(ERROR64Mhz),
.t1us(clk1us),
.f16()
);

//модуль dcm формирует 64 Мгц, 5Мгц , 20 Мгц
dcm_clk dcm1(
.CLKIN_IN(clk), 
.RST_IN(reset_dcm), 
.CLKDV_OUT(clk5mhz), 
.CLKFX_OUT(f64MHz_1),// clk32mhz  , f64MHz_1 - this 64 Mhz 
.CLKIN_IBUFG_OUT(clk20mhz), 
.CLK0_OUT(), 
.LOCKED_OUT(dcm_locked)
);

//модуль формирует 32МГц
dcm2
dcm_32(
.CLKIN_IN(clk20mhz), 
.RST_IN(reset_dcm), 
.CLKFX_OUT(clk32mhz), 
.CLK0_OUT(), 
.LOCKED_OUT()
);

rst reset1
(
.clk(clk20mhz),
.reset(reset_dcm)
);

wire xreset_SPI;
wire xCS_FPGA_MK;
wire xSCLK_MK;
wire xMOSI_MK;
wire xMISO_MK;
wire xMISO_MK1;
wire xMISO_MK2;
wire xMISO_MK3;
wire xMISO_MK4;
wire xMISO_MK5;
wire xMISO_MK6;
wire xMISO_MK7;
wire xMISO_MK8;

wire xMISO_MK10;
wire xMISO_MK11;
wire xMISO_MK12;
wire xMISO_MK13;
wire xMISO_MK14;
wire xMISO_MK15;
wire xMISO_MK16;
wire xMISO_MK17;
wire xMISO_MK18;
wire xMISO_MK19;
wire xMISO_MK20;
wire xMISO_MK21;
wire xMISO_MK22;
wire xMISO_MK23;
wire xMISO_MK24;
wire xMISO_MK25;
wire xMISO_MK26;
wire xMISO_MK27;
wire xMISO_MK28;
wire xMISO_MK29;
wire xMISO_MK30;
wire xMISO_MK31;
wire xMISO_MK32;

wire xMISO_W5100;

reg reg_MISO;

wire wOFF_Avariya;
wire wTNI;
wire wTKI;
wire wTNP;
wire wTKP;
wire wGBR;
wire wControl1;
wire wControl2;
wire [7:0] wUPR_m1;

rst reset2
(
.clk(clk32mhz),
.reset(xreset_SPI)
);

BUFG U0 (.I(SCLK_MK),.O(xSCLK_MK));//пропускаем сигнал через глобальный буфер
BUFG U1 (.I(MOSI_MK),.O(xMOSI_MK));//пропускаем сигнал через глобальный буфер
BUFG U2 (.I(CS_FPGA_MK),.O(xCS_FPGA_MK));//пропускаем сигнал через глобальный буфер

//assign xCS_FPGA_MK=CS_FPGA_MK;
//assign xSCLK_MK= SCLK_MK;
//assign xMOSI_MK= MOSI_MK;
assign  MISO_MK= (CS_WIZ==0)?MISO_W5100:
     			xMISO_MK2&
				xMISO_MK3&
				xMISO_MK4&
				xMISO_MK5&
				xMISO_MK6&
				xMISO_MK7&
				xMISO_MK8&
				xMISO_MK10&
				xMISO_MK11&
				xMISO_MK12&
				xMISO_MK13&
				xMISO_MK14&
				xMISO_MK15&
				xMISO_MK16&
				xMISO_MK17&
				xMISO_MK18&
				xMISO_MK19&
				xMISO_MK20&
				xMISO_MK21&
				xMISO_MK22&
				xMISO_MK23&
				xMISO_MK24&
				xMISO_MK25&
				xMISO_MK26&
				xMISO_MK27&
				xMISO_MK28&
				xMISO_MK29&
				xMISO_MK30&
				xMISO_MK31&
				xMISO_MK32;
			
/*		
always @(posedge f64MHz_1)
reg_MISO<=//xMISO_MK1&
				xMISO_MK2&
				xMISO_MK3&
				xMISO_MK4&
				xMISO_MK5&
				xMISO_MK6&
				xMISO_MK7&
				xMISO_MK8&
				xMISO_MK10&
				xMISO_MK11&
				xMISO_MK12&
				xMISO_MK13&
				xMISO_MK14&
				xMISO_MK15&
				xMISO_MK16&
				xMISO_MK17&
				xMISO_MK18&
				xMISO_MK19&
				xMISO_MK20&
				xMISO_MK21&
				xMISO_MK22&
				xMISO_MK23&
				xMISO_MK24&
				xMISO_MK25&
				xMISO_MK26&
				xMISO_MK27&
				xMISO_MK28&
				xMISO_MK29&
				xMISO_MK30&
				xMISO_MK31&
				xMISO_MK32&MISO_W5100;
*/

//-----------------------------контроль входных и выходных сигналов через SPI --------------------------------------------------

//проверка выходных сигналов блока 660 ..
	 Block_read_spi 
 #(8,1) spi_control1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK2),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport
		 ({IN_VKL_COM_FT_3V3, //сигнал управления коммутатором ФТ
			IN_REZERV_1_UPR_3V3,
			IN_FT50OM_3V3,
			IN_REZERV_2_UPR_3V3,
			IN_TEST1_3V3,
			IN_TEST2_3V3,
			IN_SYNC1_3V3,  // 
			IN_SYNC2_3V3}  // 
			) ); 


 Block_upr_spi1 
 #(16,2) spi_upr1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out
		 ({OUT_AVARIA_PIT_1_FT_3V3,
			OUT_NORM_PIT_2FT_3V3,
			OUT_NORM_PIT_1FT_3V3,
			OUT_AVARIA_PIT_2_FT_3V3,
			OUT_RAB_KAN_1FT_3V3,
			OUT_RAB_KAN_2FT_3V3, 
			OUT_RAB_KAN_3FT_3V3,
			OUT_RAB_KAN_4FT_3V3,
			OUT_AVARIA_KAN_4_FT_3V3,
			OUT_AVARIA_KAN_3_FT_3V3,
			OUT_AVARIA_KAN_2_FT_3V3,
			OUT_AVARIA_KAN_1_FT_3V3,
			OUT_REZERV_KONTR_2_3V3,
			OUT_REZERV_KONTR_1_3V3,
			OUT_NORMA_TEMP_1U07FI_3V3,
			OUT_PA_1U07_FI_3V3
			}  
			) );
			
 Block_upr_spi1 
 #(8,3) spi_upr2( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out
		 ({wOFF_Avariya,//включить - выключить сигнал Авария на 610 блок
			wTNI,
			wTKI,
			wTNP,
			wTKP,
			wGBR,
			wControl1,
			wControl2
			}  
			) );
			
 Block_upr_spi1 
 #(8,4) spi_upr3( 
 .clk(f64MHz_1),
 .sclk(xSCLK_MK),
 .mosi(xMOSI_MK),
 .miso(),
 .cs(xCS_FPGA_MK) ,
 .rst(xreset_SPI) ,
 
 .out (wUPR_m1) //управление выводом контрольных сигналов на тестовый разъём
 );

//----------------------------------------------------
wire [15:0] wDDS_delay;
wire [31:0] wdT_kalibrovka;
wire [31:0] wdT_pomeha;
wire [31:0] wPni1;
wire [31:0] wPii1;
wire [31:0] wPnp1;
wire [31:0] wPip1;
wire [15:0] wQIT1;

wire [31:0] wPni2;
wire [31:0] wPii2;
wire [31:0] wPnp2;
wire [31:0] wPip2;
wire [15:0] wQIT2;

wire [31:0] wPni3;
wire [31:0] wPii3;
wire [31:0] wPnp3;
wire [31:0] wPip3;
wire [15:0] wQIT3;
wire [ 7:0] wN_temp;
wire [31:0] wTNO;

wire [31:0] wCMND;
wire        wRCV;

wire [31:0] wTESTwr;
wire [7:0]  wRESTART;
wire 	      wINT2;
wire 	      wTOBM_plis;
wire [15:0] wflg_control;//слово с битами событий в блоке формирования
wire [31:0] wtst32;//проверка внутренних регистров


wire wint_I;
wire wint_P;
wire wError;
wire wTST1;
wire wTST2;
wire wRZV2;


wire wOUT_TNI_3V3_XP2;
wire wOUT_TKI_3V3_XP2;
wire wOUT_TNP_3V3_XP2;
wire wOUT_TKP_3V3_XP2;

assign OUT_TNI_3V3_XP2=wOUT_TNI_3V3_XP2|wTNI; //сигнал ТНИ.. с блокировкой или принудительным выводом. 
assign OUT_TKI_3V3_XP2=wOUT_TKI_3V3_XP2|wTKI;
assign OUT_TNP_3V3_XP2=wOUT_TNP_3V3_XP2|wTNP;
assign OUT_TKP_3V3_XP2=wOUT_TKP_3V3_XP2|wTKP;

assign wRCV=DATA_PD8;//сигнал записи регистров блока формирования импульсов "1" , сброс "0"

//модуль формирования импульсов
form_imp_master MFI(
.clk5mhz(clk5mhz),   
.sync_in(0),//60 секунд сброс
.RCV  (wRCV), //сигнал записи регистров блока формирования импульсов "1" , сброс "0"
.TKP_f(),
.TNP_f(),
.TKI_f(),
.TNI_f(),
.TNC_f (OUT_TNC_3V3_XP2),
.TOBM_f(OUT_TOBM_3V3_XP2),
.TNO_f (OUT_TNO_3V3_XP2),
.TKP_o (wOUT_TKP_3V3_XP2),
.TNP_o (wOUT_TNP_3V3_XP2),
.TKI_o (wOUT_TKI_3V3_XP2),
.TNI_o (wOUT_TNI_3V3_XP2),
.CMND(wCMND),
.TOBM_plis(wTOBM_plis),//прерывание для мк, говорит что произошло какое-то событие в блоке формирования
.T1us(clk1us),
.clk(f64MHz_1),
.time_rst(wINT2), //сброс шкалы времени - прерывание на мк
.flg_control(wflg_control),
.event_rst(0),
.tst_32(wtst32),
.reset_contol_TNO(),
.I_izl(wint_I),
.I_get(wint_P),
.error(wError),
.DDS_delay(wDDS_delay),
.dT_kalibrovka(wdT_kalibrovka),
.dT_pomeha(wdT_pomeha),
.Pni1(wPni1),
.Pii1(wPii1),
.Pnp1(wPnp1),
.Pip1(wPip1),
.QIT1(wQIT1),
.Pni2(wPni2),
.Pii2(wPii2),
.Pnp2(wPnp2),
.Pip2(wPip2),
.QIT2(wQIT2),
.Pni3(wPni3),
.Pii3(wPii3),
.Pnp3(wPnp3),
.Pip3(wPip3),
.QIT3(wQIT3),
.N_temp(wN_temp),
.TNO(wTNO)
);


//модуль выбора сигналов для контрольных выходов (F5Mhz out и TMIN_out) и модуль выдачи интервалов приёма и синхросмеси сигналов для 610 блока
tst_sg1 
m1(
	 .clk(f64MHz_1),
	 .t5min(wsync_t5min),
	 .clk5mhz(clk5mhz),
    .upr(wUPR_m1),
	 .TNO (OUT_TNO_3V3_XP2),
    .TNC (OUT_TNC_3V3_XP2),
    .TNI (OUT_TNI_3V3_XP2),
    .TKI (OUT_TKI_3V3_XP2),
    .TNP (OUT_TNP_3V3_XP2),
    .TKP (OUT_TKP_3V3_XP2),
    .TOBM(OUT_TOBM_3V3_XP2),
	 .IntI(wint_I),
	 .IntP(wint_P),
	 .Error(wError),
    .sig1(wTST1),
    .sig2(wTST2),
	 .contrl(wRZV2)
    );

//модуль контроля длительности интервалов ТНЦ и ТНО с разъёма XW2 и XW1 (24-Вольтовые сигналы с 615 кассеты 660 блока) 

wire [31:0] wTime_TNC_24V;
wire [31:0] wTime_TNO_24V;

control_TNO_TNC MCI_TNC_TNO(
.clk(f64MHz_1),
.clk1us(clk1us),
.reset_TNO(IN_TNO24V_3V3),
.reset_TNC(IN_TNC24V_3V3),
.Time_TNC(wTime_TNC_24V),
.Time_TNO(wTime_TNO_24V),
.rst(0)
);


//модуль контроля длительности интервалов ТНЦ и ТНО с разъёма XT7 (сигналы идут на 610 блок) 

wire [31:0] wTime_TNC;
wire [31:0] wTime_TNO;

control_TNO_TNC MCI_TNC24_TNO24(
.clk(f64MHz_1),
.clk1us(clk1us),
.reset_TNO(OUT_TNO_3V3_XP2),
.reset_TNC(OUT_TNC_3V3_XP2),
.Time_TNC(wTime_TNC),
.Time_TNO(wTime_TNO),
.rst(0)
);

assign INT2=wINT2;//сброс шкалы времени - прерывание на мк
assign INT3=OUT_TNC_3V3_XP2;//прерывание для мк, по сигналу ТНЦ

//---------------------------------------------------------------------------------------------------
wire [15:0] wtni;
wire [15:0] wtni1;
wire [15:0] wtki;
wire [15:0] wt1_4;
wire [15:0] wtki1;
wire [15:0] wtnp;
wire [15:0] wtkp;
wire [15:0] wtkp1;
wire [15:0] wtobm;
wire [15:0] wtnc;
wire [15:0] wtno;
wire [15:0] wrezerv4;
wire [15:0] wrezerv;
wire [15:0] wrezerv1;
wire [15:0] wrezerv2;
wire [15:0] wrezerv3;
wire [31:0] wtst_int_I;
wire [31:0] wtst_int_P;
wire [31:0] wint_TNC;
wire [31:0] wint_TNO;
wire [23:0] wcontrol;
wire w_int_event;
wire w_rst_imp_tester;

wire wINT5;
wire wINT6;

//---------модули смещают и удлинняют импульсы для измерения мощности сигналов излучения и гетеродина---------
IMP_delayer 
#(100*8)  IMPD_TNI
(
	.o_imp(wINT5),
	.clk(f64MHz_1),
	.imp(wtni),
	.tus(clk1us)
);

IMP_delayer 
#(100*8)  IMPD_TNP
(
	.o_imp(wINT6),
	.clk(f64MHz_1),
	.imp(wtnp),
	.tus(clk1us)
);  

assign w_rst_imp_tester = DATA_PD9;    // сигнал сброса с мк на модуль контроля сигналов блока 660
assign INT4 = w_int_event; //прерывание от модуля контроля сигналов блока 660
assign INT5 =wINT5;//прерывание для контроля сигнала излучения
assign INT6 =wINT6;//прерывание для контроля сигнала приёма

//модуль проверки импульсных сигналов поступающих с блока 660
tester_imp
tester1(
	.tni(wtni),
	.tni1(wtni1),
	.tki(wtki),
	.t1_4(wt1_4),
	.tki1(wtki1),
	.tnp(wtnp),
	.tkp(wtkp),
	.tkp1(wtkp1),
	.tobm(wtobm),
	.tnc(wtnc),
	.tno(wtno),
	.rezerv4(wrezerv4),
	.rezerv (wrezerv),
	.rezerv1(wrezerv1),
	.rezerv2(wrezerv2),
	.rezerv3(wrezerv3),
	.int_I(wtst_int_I),
	.int_P(wtst_int_P),
	.int_TNC(wint_TNC),
	.int_TNO(wint_TNO),
	.control(wcontrol),
	.int_event(w_int_event),
	.clk(f64MHz_1),
	.tus(clk1us),
	.i({
	IN_TNI_3V3_XP1,
	IN_TNI_1_3V3_XP1,
	IN_TKI_3V3_XP1,
	IN_T1_4_3V3_XP1,
	IN_TKI_1_3V3_XP1,
	IN_TNP_3V3_XP1,
	IN_TKP_3V3_XP1,
	IN_TKP1_3V3_XP1,
	IN_TOBM_3V3_XP1,
	IN_TNC_3V3_XP1,
	IN_TNO_3V3_XP1,
	IN_REZERV4_3V3_XP1,
	IN_REZERV_3V3_XP1,
	IN_REZERV1_3V3_XP1,
	IN_REZERV2_3V3_XP1,
	IN_REZERV3_3V3_XP1
	}),
	.rst(w_rst_imp_tester)
);


wire w_tx_485;
wire w_rts_485;
wire w_usb_upr;
//модуль вывода в шину 485 тестового сигнала имитируюещего наличие мастера в цепи резервирования!!
usb_test 
usb1(
	.upr   (w_usb_upr),
	.clk   (f64MHz_1),
	.tx_485(w_tx_485),
	.rts_485(w_rts_485)
);



Block_read_spi 
 #(16,50) spi_rd_imp0       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK10),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtni));//чтение
	
Block_read_spi 
 #(16,51) spi_rd_imp1       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK11),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtni1));//чтение	

Block_read_spi 
 #(16,52) spi_rd_imp2       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK12),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtki));//чтение		

Block_read_spi 
 #(16,53) spi_rd_imp3       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK13),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wt1_4));//чтение	

Block_read_spi 
 #(16,54) spi_rd_imp4       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK14),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtki1));//чтение
	
Block_read_spi 
 #(16,55) spi_rd_imp5       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK15),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtnp));//чтение

Block_read_spi 
 #(16,56) spi_rd_imp6       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK16),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtkp));//чтение

Block_read_spi 
 #(16,57) spi_rd_imp7       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK17),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtkp1));//чтение
	
Block_read_spi 
 #(16,58) spi_rd_imp8       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK18),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtobm));//чтение
	
Block_read_spi 
 #(16,59) spi_rd_imp9       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK19),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtnc));//чтение
	
Block_read_spi 
 #(16,60) spi_rd_imp10       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK20),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtno));//чтение

Block_read_spi 
 #(32,61) spi_rd_imp11       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK21),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wrezerv4));//чтение
	
Block_read_spi 
 #(32,62) spi_rd_imp12       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK22),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wrezerv));//чтение

Block_read_spi 
 #(32,63) spi_rd_imp13       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK23),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wrezerv1));//чтение
	
Block_read_spi 
 #(32,64) spi_rd_imp14       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK24),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wrezerv2));//чтение

Block_read_spi 
 #(32,65) spi_rd_imp15       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK25),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wrezerv3));//чтение

Block_read_spi 
 #(32,66) spi_rd_imp16       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK26),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtst_int_I));//чтение
	
Block_read_spi 
 #(32,67) spi_rd_imp17       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK27),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtst_int_P));//чтение
	
Block_read_spi 
 #(32,68) spi_rd_imp18       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK28),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wint_TNC));//чтение
	
Block_read_spi 
 #(32,69) spi_rd_imp19       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK29),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wint_TNO));//чтение
	
Block_read_spi 
 #(24,70) spi_rd_imp20       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK30),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wcontrol));//чтение
	
//---------------------------------------------------------------------------------------------------


Block_read_spi 
 #(32,30) spi_test       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK8),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(32'hdeedbeef));//чтение test

Block_read_spi 
 #(32,31) spi_Time_TNO   (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK7),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTime_TNO));//чтение длительности интервала ТНO 

Block_read_spi 
 #(32,32) spi_Time_TNC   (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK6),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTime_TNC));//чтение длительности интервала ТНЦ 

Block_read_spi 
 #(32,33) spi_tst32      (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK5),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wtst32));//чтение тестового регистра wtst32

Block_read_spi 
 #(16,34) spi_flg_control(.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK4),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wflg_control));//чтение контрольного регистра на предмет произошедших событий
	
Block_read_spi 
 #(32,37) spi_rd_TNO24       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK31),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTime_TNO_24V));//чтение контрольного регистра длительности сигнала ТНО 24Вольта
	
Block_read_spi 
 #(32,38) spi_rd_TNC24       (.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK32),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTime_TNC_24V));//чтение контрольного регистра длительности сигнала ТНЦ 24Вольта	

Block_read_spi 
 #(32,35)     spi_TEST_rd(.clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK3),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTESTwr));//чтение контрольного регистра - проверка шины SPI	

Block_upr_spi1 
 #(32,36) spi_TEST_wr( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTESTwr));//запись контрольного регистра - проверка шины SPI


//--------------------------------------------------------------------------------------------------	
	


Block_upr_spi1 
 #(32,10) spi_Pni1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPni1));
	
Block_upr_spi1 
 #(32,11) spi_Pii1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPii1));

Block_upr_spi1 
 #(32,12) spi_Pnp1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPnp1));

Block_upr_spi1 
 #(32,13) spi_Pip1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPip1));
	
Block_upr_spi1 
 #(16,14) spi_QIT1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wQIT1));
	

Block_upr_spi1 
 #(32,15) spi_Pni2( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPni2));
	
Block_upr_spi1 
 #(32,16) spi_Pii2( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPii2));

Block_upr_spi1 
 #(32,17) spi_Pnp2( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPnp2));

Block_upr_spi1 
 #(32,18) spi_Pip2( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPip2));
	
Block_upr_spi1 
 #(16,19) spi_QIT2( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wQIT2));
	

Block_upr_spi1 
 #(32,20) spi_Pni3( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPni3));
	
Block_upr_spi1 
 #(32,21) spi_Pii3( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPii3));

Block_upr_spi1 
 #(32,22) spi_Pnp3( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPnp3));

Block_upr_spi1 
 #(32,23) spi_Pip3( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wPip3));
	
Block_upr_spi1 
 #(16,24) spi_QIT3( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wQIT3));

Block_upr_spi1 
 #(8,25) spi_N_temp( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wN_temp));
	
Block_upr_spi1 
 #(16,26) spi_DDS_delay( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wDDS_delay));
	
Block_upr_spi1 
 #(32,27) spi_dT_kalibrovka( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wdT_kalibrovka));
	
Block_upr_spi1 
 #(32,28) spi_dT_pomeha( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wdT_pomeha));

Block_upr_spi1 
 #(32,29) spi_TNO( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTNO));


Block_upr_spi1 
 #(32,30) spi_CMND( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wCMND));
	

Block_upr_spi1 
 #(8,99) spi_USB1( .clk(f64MHz_1),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(w_usb_upr));
	
//----------------------------------------------------
	 
reg reg_Avariya=0;

always @(posedge clk20mhz)
begin
 accum      <=accum+1;
 reg_Avariya<=accum[2];
end

wire wBOOT_MK;
wire wRESET_MK;
wire wBOOT_TX_MK;
wire wBOOT_RX_MK;


reset_long
#(200000) rst_mk (.clk(clk20mhz),.en(RESET_MK_FTDI), .rst(wRESET_MK));  //модуль ресета для мк

assign wBOOT_RX_MK = TX_FTDI_1; //принимаем данные от FTDI
assign wBOOT_TX_MK = BOOT_TX_MK;//принимаем данные от MK
assign wBOOT_MK    = BOOT0_FTDI;
assign RX_FTDI_1   = wBOOT_TX_MK;//выдаём данные в FTDI
assign BOOT0_FPGA  =~wBOOT_MK;  //инвертируем сигнал BOOT c FTDI
assign RESET_MK    = wRESET_MK;//сигнал ресет от FTDI и долгий ресет после старта ПЛИС
assign BOOT_RX_MK  = wBOOT_RX_MK;//выдаём данные в МК


assign INTa =  accum[31];



assign OUT_F_5MHZ_ETALON_3V3=IN_TNC_3V3_XP1; //он же -  тестовый выход сигнала wTST2
assign OUT_T5MIN_60SEC_3V3  =wTST1;

assign OUT_TEST1_3V3=1;
assign OUT_TEST2_3V3=1;
assign OUT_TEST3_3V3=1;

assign INT9=0;
assign INT8=0;
assign INT7=0;


//assign OUT_TNP_3V3_XP2=1;
//assign OUT_TKP_3V3_XP2=1;

//assign OUT_TOBM_3V3_XP2=1;
//assign OUT_TNC_3V3_XP2=1;
//assign OUT_TNO_3V3_XP2=1;


assign OUT_TX_3V3_XP1=USART2_TX;
assign OUT_REZERV5_3V3_XP1=0;

//assign OUT_TNI_3V3_XP2=1;
//assign OUT_TKI_3V3_XP2=1;
assign OUT_T1_4_3V3_XP2 =OUT_TNC_3V3_XP2;
assign OUT_TKI1_3V3_XP2 =OUT_TKI_3V3_XP2;
assign OUT_TNI_1_3V3_XP2=OUT_TNI_3V3_XP2;
assign OUT_TKP1_3V3_XP2 =OUT_TKP_3V3_XP2;
assign OUT_TKI_1_3V3_XP2=OUT_TKI_3V3_XP2;

assign OUT_REZERV_3V3_XP2 =reg_Avariya&wOFF_Avariya;//сигнал Аварии на 610 блок , пока идёт всё хорошо если не идёт - то отключаются ключи в 610 блоке.
assign OUT_REZERV1_3V3_XP2=wGBR;//задаёт режим БР или ГБР для 610 блока
assign OUT_REZERV2_3V3_XP2=wRZV2;//выводит синхросмесь для 610 блока
assign OUT_REZERV3_3V3_XP2=wint_P;//выдаём интервал приёма на блок б610
assign OUT_REZERV4_3V3_XP2=TX_FTDI_1;//вывод уарта с ftdi на 610 блок , надо сделать одинаковые скорость для стендовой платы и 610 блока , адреса разные сделать.


assign USART2_RX=1;
assign USART3_RX=1;
assign RTS_485  =w_rts_485;

//--------------ethernet wiz------------------
wire wRESET_WIZ;
wire wDELAY_WIZ;
wire wPWRDN;
reset_long
#(120000) PWRD_WIZ (.clk(clk20mhz),.en(DATA_PD10), .rst(wPWRDN));  //модуль ресета для ETHERNET
reset_long
#(23000000) rst_WIZ (.clk(clk20mhz),.en(wPWRDN), .rst(wRESET_WIZ));  //модуль ресета для ETHERNET
reset_long
#(8000000) delay_WIZ (.clk(clk20mhz),.en(1), .rst(wDELAY_WIZ));  //модуль ресета для ETHERNET

//assign RESET_WIZ=DATA_PD10;
//assign PWDWN_ETHERNET_PLIS=DATA_PD11;
assign PWDWN_ETHERNET_PLIS=~wPWRDN;
assign RESET_WIZ =wRESET_WIZ;
assign MOSI_W5100=xMOSI_MK&(wDELAY_WIZ);
assign SCLK_W5100=xSCLK_MK&(wDELAY_WIZ);
assign CS_W5100  =CS_WIZ  |(~wDELAY_WIZ);
assign INT1=INT_W5100; //прерывание от WIZ820
//--------------------------------------------

//assign OUT_AVARIA_PIT_1_FT_3V3=1;
//assign OUT_NORM_PIT_2FT_3V3=1;
//assign OUT_NORM_PIT_1FT_3V3=1;
//assign OUT_AVARIA_PIT_2_FT_3V3=1;
//assign OUT_RAB_KAN_1FT_3V3=1;
//assign OUT_RAB_KAN_2FT_3V3=1;
//assign OUT_RAB_KAN_3FT_3V3=1;
//assign OUT_RAB_KAN_4FT_3V3=1;
//assign OUT_AVARIA_KAN_4_FT_3V3=1;


//assign OUT_AVARIA_KAN_3_FT_3V3=1;
//assign OUT_AVARIA_KAN_2_FT_3V3=1;
//assign OUT_AVARIA_KAN_1_FT_3V3=1;
//assign OUT_REZERV_KONTR_2_3V3=1;
//assign OUT_REZERV_KONTR_1_3V3=1;
//assign OUT_NORMA_TEMP_1U07FI_3V3=1;
//assign OUT_PA_1U07_FI_3V3=1;
assign OUT_REZERV_KONTR_4_3V3=1;
assign OUT_REZERV_KONTR_3_3V3=clk20mhz;

assign MK_DATA0=1;
assign MK_DATA1=1;
assign MK_DATA2=1;
assign MK_DATA3=1;
assign MK_DATA4=1;
assign MK_DATA5=1;
assign MK_DATA6=1;
assign MK_DATA7=1;
assign MK_DATA8=1;

assign OUT_CONTROL_K2_3V3=wControl2; //проверка сигналов тепловых датчиков для 610 блока
assign OUT_CONTROL_K1_3V3=wControl1; //проверка сигналов тепловых датчиков для 610 блока


assign RE_485=1;
assign RXD_FTDI_2=1;
assign TX_485_MG=w_tx_485;
assign RESET_RS485=1; 

endmodule

