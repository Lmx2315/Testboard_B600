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
	
	output RX_485_MG,
	input  TX_485_MG

    );

wire clk5mhz;
wire clk20mhz;
wire clk64mhz;
wire clk1us;
wire dcm_locked;
wire reset_dcm;
wire f16MHz;
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

//модуль формирования 1 мкс и проверки наличия основных частот
control_F5_F64 MF1US_controlCLK(
.f5(clk5mhz),
.f64(clk64mhz),
.clk(clk20mhz),
.ERROR_5(ERROR5Mhz),
.ERROR_64(ERROR64Mhz),
.t1us(clk1us),
.f16(f16MHz)
);

//модуль dcm формирует 64 Мгц, 5Мгц , 1 мкс
dcm_clk dcm1(
.CLKIN_IN(clk), 
.RST_IN(reset_dcm), 
.CLKDV_OUT(clk5mhz), 
.CLKFX_OUT(clk64mhz), 
.CLKIN_IBUFG_OUT(clk20mhz), 
.CLK0_OUT(), 
.LOCKED_OUT(dcm_locked)
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
wire xMISO_W5100;

rst reset2
(
.clk(clk20mhz),
.reset(xreset_SPI)
);

assign xCS_FPGA_MK=CS_FPGA_MK;
assign xSCLK_MK= SCLK_MK;
assign xMOSI_MK= MOSI_MK;
assign  MISO_MK=
		    //xMISO_MK1&
	//			xMISO_MK2&
	//			xMISO_MK3&
	//			xMISO_MK4&
	//			xMISO_MK5&
	//			xMISO_MK6&
				xMISO_MK7;
	//			xMISO_W5100;

//-----------------------------контроль входных и выходных сигналов через SPI --------------------------------------------------


	 Block_control_spi 
 #(8,1) spi_control1( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK2),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport
		 ({IN_VKL_COM_FT_3V3,
			IN_REZERV_1_UPR_3V3,
			IN_FT50OM_3V3,
			IN_REZERV_2_UPR_3V3,
			IN_TEST1_3V3,
			IN_TEST2_3V3,
			IN_SYNC1_3V3,  // 
			IN_SYNC2_3V3}  // 
			) ); 


 Block_upr_spi1 
 #(16,2) spi_upr1( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out
		 ({OUT_AVARIA_PIT_1_FT_3V3,
			OUT_NORM_PIT_2FT_3V3,
			OUT_NORM_PIT_1FT_3V3,
			OUT_AVARIA_PIT_2_FT_3V3,
			OUT_RAB_KAN_1FT_3V3,
			OUT_RAB_KAN_2FT_3V3,  //индикация лицевой панели 2
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
			}  //индикация лицевой панели 1
			) );

//----------------------------------------------------
wire [31:0] wTNO;
wire [31:0] wTNC;
wire [31:0] wTOBM;
wire [31:0] wTNI;
wire [31:0] wTKI;
wire [31:0] wTNP;
wire [31:0] wTKP;
wire [31:0] wCMND;
wire        wRCV;

wire [7:0]  wRESTART;
wire 	      wINT2;
wire 	      wTOBM_plis;
wire [15:0] wflg_control;//слово с битами событий в блоке формирования
wire [31:0] wtst32;//проверка внутренних регистров

assign wRCV=DATA_PD8;//сигнал записи регистров блока формирования импульсов "1" , сброс "0"

//модуль формирования импульсов
read_and_work MFI(
.clk5mhz(clk5mhz),   
.sync_in(wsync_t5min),
.RCV  (wRCV), //сигнал записи регистров блока формирования импульсов "1" , сброс "0"
.TKP_f(),
.TNP_f(),
.TKI_f(),
.TNI_f(),
.TNC_f (OUT_TNC_3V3_XP2),
.TOBM_f(OUT_TOBM_3V3_XP2),
.TNO_f (OUT_TNO_3V3_XP2),
.TKP_o (OUT_TKP_3V3_XP2),
.TNP_o (OUT_TNP_3V3_XP2),
.TKI_o (OUT_TKI_3V3_XP2),
.TNI_o (OUT_TNI_3V3_XP2),
.TNO (wTNO),
.TNC (wTNC),
.TOBM(wTOBM),
.TNI (wTNI),
.TKI (wTKI),
.TNP (wTNP),
.TKP (wTKP),
.CMND(wCMND),
.TOBM_plis(wTOBM_plis),//прерывание для мк, говорит что произошло какое-то событие в блоке формирования
.T1us(clk1us),
.clk(f16MHz),
.time_rst(wINT2), //сброс шкалы времени - прерывание на мк
.flg_control(wflg_control),
.event_rst(0),
.PPI_fail(0),
.tst_32(wtst32),
.reset_contol_TNO(),
.I_izl(),
.I_get(),
.error()
);

//модуль контроля длительности интервалов ТНЦ и ТНО

wire [31:0] wTime_TNC;
wire [31:0] wTime_TNO;

control_TNO_TNC MCI_TNC_TNO(
.clk(f16MHz),
.clk1us(clk1us),
.reset_TNO(OUT_TNO_3V3_XP2),
.reset_TNC(OUT_TNC_3V3_XP2),
.Time_TNC(wTime_TNC),
.Time_TNO(wTime_TNO),
.rst(0)
);

assign INT2=wINT2;//сброс шкалы времени - прерывание на мк
assign INT3=wTOBM_plis;//прерывание для мк, говорит что произошло какое-то событие в блоке формирования
//assign INT2=accum[25];//сброс шкалы времени - прерывание на мк
//assign INT3=accum[26];//прерывание для мк, говорит что произошло какое-то событие в блоке формирования



Block_control_spi 
 #(32,23) spi_test       (.clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK7),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(32'hdeedbeef));//чтение test

Block_control_spi 
 #(32,22) spi_Time_TNO   (.clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK6),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTime_TNO));//чтение длительности интервала ТНO 

Block_control_spi 
 #(32,21) spi_Time_TNC   (.clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK5),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTime_TNC));//чтение длительности интервала ТНЦ 

Block_control_spi 
 #(32,20) spi_tst32      (.clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK4),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wTOBM));//чтение тестового регистра wtst32

Block_control_spi 
 #(16,19) spi_flg_control(.clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(xMISO_MK3),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.inport(wflg_control));//чтение контрольного регистра на предмет произошедших событий
	


Block_upr_spi1 
 #(32,10) spi_TNO( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTNO));
	
Block_upr_spi1 
 #(32,11) spi_TNC( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTNC));

Block_upr_spi1 
 #(32,12) spi_TOBM( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTOBM));

Block_upr_spi1 
 #(32,13) spi_TNI( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTNI));
	
Block_upr_spi1 
 #(32,14) spi_TKI( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTKI));

Block_upr_spi1 
 #(32,15) spi_TNP( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTNP));

Block_upr_spi1 
 #(32,16) spi_TKP( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wTKP));

Block_upr_spi1 
 #(32,17) spi_CMND( .clk(clk20mhz),.sclk(xSCLK_MK),.mosi(xMOSI_MK),.miso(),.cs(xCS_FPGA_MK) ,.rst(xreset_SPI) ,
	.out(wCMND));
//----------------------------------------------------
	 


always @(posedge clk20mhz)
begin
 accum<=accum+1;
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

assign OUT_REZERV1_3V3_XP2=1;
assign OUT_REZERV2_3V3_XP2=1;
assign OUT_REZERV3_3V3_XP2=1;

assign OUT_F_5MHZ_ETALON_3V3=f16MHz;
assign OUT_T5MIN_60SEC_3V3=clk1us;
assign OUT_TEST1_3V3=1;
assign OUT_TEST2_3V3=1;
assign OUT_TEST3_3V3=1;

assign INT9=1;
assign INT8=1;
assign INT7=1;
assign INT6=1;
assign INT5=1;
assign INT4=1;


assign OUT_TKI_1_3V3_XP2=1;
//assign OUT_TNP_3V3_XP2=1;
//assign OUT_TKP_3V3_XP2=1;
assign OUT_TKP1_3V3_XP2=1;
//assign OUT_TOBM_3V3_XP2=1;
//assign OUT_TNC_3V3_XP2=1;
//assign OUT_TNO_3V3_XP2=1;
assign OUT_REZERV4_3V3_XP2=1;
assign OUT_REZERV_3V3_XP2=1;
assign OUT_TX_3V3_XP1=1;
assign OUT_REZERV5_3V3_XP1=1;
//assign OUT_TNI_3V3_XP2=1;
//assign OUT_TKI_3V3_XP2=1;
assign OUT_T1_4_3V3_XP2=1;
assign OUT_TKI1_3V3_XP2=1;


assign USART2_RX=1;
assign USART3_RX=1;
assign RTS_485=1;

//--------------ethernet wiz------------------
wire wRESET_WIZ;
wire wDELAY_WIZ;
reset_long
#(20000) rst_WIZ (.clk(clk20mhz),.en(1), .rst(wRESET_WIZ));  //модуль ресета для ETHERNET
reset_long
#(4000000) delay_WIZ (.clk(clk20mhz),.en(1), .rst(wDELAY_WIZ));  //модуль ресета для ETHERNET

assign PWDWN_ETHERNET_PLIS=0;
assign RESET_WIZ =wRESET_WIZ;
assign MOSI_W5100=xMOSI_MK|(~wDELAY_WIZ);
assign SCLK_W5100=xSCLK_MK|(~wDELAY_WIZ);
assign CS_W5100  =CS_WIZ  |(~wDELAY_WIZ);
assign xMISO_W5100 = MISO_W5100|(~CS_WIZ);
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
assign OUT_TNI_1_3V3_XP2=1;
assign MK_DATA0=1;
assign MK_DATA1=1;
assign MK_DATA2=1;
assign MK_DATA3=1;
assign MK_DATA4=1;
assign MK_DATA5=1;
assign MK_DATA6=1;
assign MK_DATA7=1;
assign MK_DATA8=1;

assign OUT_CONTROL_K2_3V3=1;
assign OUT_CONTROL_K1_3V3=1;
assign RE_485=1;
assign RXD_FTDI_2=1;
assign RX_485_MG=1; 

endmodule
