														//-----------------------------------------------------------------------------
//
// Title       : read_and_work
// Design      : sinh1_v1
// Author      : Microsoft
// Company     : Microsoft
//
//-----------------------------------------------------------------------------
//
// File        : read_and_work.v
// Generated   : Fri Nov  1 16:21:11 2013
// From        : interface description file
// By          : Itf2Vhdl ver. 1.22
//
//-----------------------------------------------------------------------------
//
// Description : 
//
//-----------------------------------------------------------------------------
`timescale 1 ns / 1 ps

//{{ Section below this comment is automatically maintained
//   and may be overwritten
//{module {read_and_work}}
module read_and_work (clk5mhz,sync_in,RCV,TKP_f,TNP_f ,TKI_f ,TNI_f ,TNC_f ,TOBM_f ,
								TNO_f,TKP_o,TNP_o,TKI_o,TNI_o,TNO,TNC,TOBM,TNI,TKI,TNP,TKP,
								CMND,TOBM_plis,T1us,clk,time_rst,flg_control,event_rst,
								PPI_fail,tst_32,reset_contol_TNO,I_izl,I_get,error);

output I_izl ;
wire I_izl ;
output I_get ;
wire I_get ;

output TKP_f ;
wire TKP_f ;
output TNP_f ;
wire TNP_f ;
output TKI_f ;
wire TKI_f ;
output TNI_f ;
wire TNI_f ;
output TNC_f ;
wire TNC_f ;
output TOBM_f ;
wire TOBM_f ;
output TNO_f ;
wire TNO_f ;


output error ;
wire error ;

output reset_contol_TNO ;
wire reset_contol_TNO ;

output TKP_o ;
wire TKP_o ;
output TNP_o ;
wire TNP_o ;
output TKI_o ;
wire TKI_o ;
output TNI_o ;
wire TNI_o ;

output TOBM_plis ;
wire TOBM_plis ;

output time_rst ;
wire time_rst ;

output [31:0] tst_32 ;
wire [31:0] tst_32 ;

output [15:0] flg_control ;
wire [15:0] flg_control ;

input [31:0] TKP ;
wire [31:0] TKP ;

input [31:0] TNP ;
wire [31:0] TNP ;

input [31:0] TKI ;
wire [31:0] TKI ;

input [31:0] TNI ;
wire [31:0] TNI ;

input [31:0] TNC ;
wire [31:0] TNC ;

input [31:0] TOBM ;
wire [31:0] TOBM ;

input [31:0] TNO ;
wire [31:0] TNO ;

input [31:0] CMND ;
wire [31:0] CMND ;

input event_rst ;
wire event_rst ;

input RCV ;
wire RCV ;

input T1us ;
wire T1us ;

input clk ;
wire clk ;

input sync_in ;
wire sync_in ;

input PPI_fail ;
wire PPI_fail ;


input clk5mhz ;
wire clk5mhz ;

parameter SYNC_COMMAND     =32'h1234FFFF; //комана синхронизации ТНО относительно сигнала Т5мин и привязки ТНЦ , младший байт зарезервирован под слово содержащие описание сработавших эвентов
parameter NOT_SYNC_COMMAND =32'h9999FFFF; //команда автономности ТНО от ТНЦ				
parameter RESET_COMMAND    =32'h8888FFFF; //команда сброса счётчика часов
parameter Delay_RUN_COMMAND=8'h1; //команда задержки выдачи в работу новой пачки импульсов (посылается по ТОБМ) (второй байт командного слова)

reg [3:0] sync_reg=0;
reg sync_flag=0;
reg [7:0] sch_sync_reg=0;
reg reset_contol_TNO_reg=0;

reg [3:0] tick1=0;
reg [3:0] tick2=0;
reg [3:0] tick3=0;
reg [3:0] tick4=0;
reg [3:0] tick5=0;
reg [3:0] tick6=0;
reg [3:0] tick_TNO=0;

reg flag_reset_from_TNO=0;

reg [15:0] flg_control_reg=0;
reg [15:0] flg_trsp_control_reg=0;
wire CRC_control;


reg [15:0] delay_tno=0;  //регистры задержек
reg [15:0] delay_tno_x=0;
reg [15:0] delay_tno1=0;
reg [15:0] delay_tnc=0;
reg [15:0] delay_tobm=0;
reg [15:0] delay_tni=0;
reg [15:0] delay_tki=0;
reg [15:0] delay_tnp=0;
reg [15:0] delay_tkp=0;
reg [15:0] delay_t1hz=0;
reg [31:0] time_from_start=0;

reg tno_FLAG     =0;   // регистры флагов
reg tno_x_FLAG     =0; 
reg tno1_FLAG    =0;
reg tnc_FLAG     =0;
reg tobm_FLAG    =0;
reg tni_FLAG     =0;
reg tki_FLAG     =0;
reg tnp_FLAG     =0;
reg tkp_FLAG     =0;
reg t1hz_FLAG    =0;


reg tno_reg     =0;   // регистры флагов
reg tno_x_reg     =0; 
reg tno1_reg    =0;
reg tnc_reg     =0;
reg tobm_reg    =0;
reg tni_reg     =0;
reg tki_reg     =0;
reg tnp_reg     =0;
reg tkp_reg     =0;
reg t1hz_reg    =0;
reg time_rst_reg=0;
reg FLAG_tobm_reg=0;

reg reset_flag=0;
reg flag_NOT_sync=0;
reg PPI_fail_reg=0;

reg tno_reg5  =0;   // регистры флагов
reg tno_x_reg5  =0;  
reg tno1_reg5  =0; 
reg tnc_reg5  =0;
reg tobm_reg5 =0;
reg tni_reg5  =0;
reg tki_reg5  =0;
reg tnp_reg5  =0;
reg tkp_reg5  =0;
reg t1hz_reg5 =0;

reg tno_reg6  =0;   // регистры флагов
reg tnc_reg6  =0;
reg tni_reg6  =0;
reg tki_reg6  =0;
reg tnp_reg6  =0;
reg tkp_reg6  =0;
reg t1hz_reg6 =0;

reg Interval_TI=0;
reg Interval_TP=0;

reg ERROR_TNP=0;
reg ERROR_TNI=0;
reg ERROR_TKP=0;
reg ERROR_TKI=0;

reg Tizl_ZERO_flag=0; //флаг означающий что нет импульса излучения на интервале излучения
reg Tizl_ZERO_flag2=0; //флаг означающий что нет импульса излучения на интервале излучения

reg [31:0] TNO_rg  =32'hffffffff;   // регистры данных из памяти меток
reg [31:0] TNO1_rg =32'hffffffff;
reg [31:0] TNC_rg  =32'hffffffff;
reg [31:0] TOBM_rg =32'hffffffff;
reg [31:0] TNI_rg  =32'hffffffff;
reg [31:0] TKI_rg  =32'hffffffff;
reg [31:0] TNP_rg  =32'hffffffff;
reg [31:0] TKP_rg  =32'hffffffff;
reg [31:0] CMND_rg =32'hffffffff;

reg [31:0] TNO_rg2  =32'hffffffff;   // регистры данных из памяти меток
reg [31:0] TNO1_rg2 =32'hffffffff;
reg [31:0] TNC_rg2  =32'hffffffff;
reg [31:0] TOBM_rg2 =32'hffffffff;
reg [31:0] TNI_rg2  =32'hffffffff;
reg [31:0] TKI_rg2  =32'hffffffff;
reg [31:0] TNP_rg2  =32'hffffffff;
reg [31:0] TKP_rg2  =32'hffffffff;
reg [31:0] CMND_rg2 =32'hffffffff;
//регистры для CDC
reg [31:0] TNO_rg5  =32'hffffffff;   // регистры данных из памяти меток
reg [31:0] TNO1_rg5 =32'hffffffff;
reg [31:0] TNC_rg5  =32'hffffffff;
reg [31:0] TOBM_rg5 =32'hffffffff;
reg [31:0] TNI_rg5  =32'hffffffff;
reg [31:0] TKI_rg5  =32'hffffffff;
reg [31:0] TNP_rg5  =32'hffffffff;
reg [31:0] TKP_rg5  =32'hffffffff;
reg [31:0] CMND_rg5 =32'hffffffff;

reg tno_FLAG_CDC     =0;   // регистры флагов
reg tno_x_FLAG_CDC   =0; 
reg tno1_FLAG_CDC    =0;
reg tnc_FLAG_CDC     =0;
reg tobm_FLAG_CDC    =0;
reg tni_FLAG_CDC     =0;
reg tki_FLAG_CDC     =0;
reg tnp_FLAG_CDC     =0;
reg tkp_FLAG_CDC     =0;
reg t1hz_FLAG_CDC    =0;

reg FLAG_data_in=0;
reg FLAG_CDC_en=0;

reg tno_end  =0;   // регистры флагов
reg tno_x_end  =0; 
reg tno1_end =0;
reg tnc_end  =0;
reg tobm_end =0;
reg tni_end  =0;
reg tki_end  =0;
reg tnp_end  =0;
reg tkp_end  =0;

reg CRC_control_reg1=0;

reg ERROR_SUM_reg=0;

reg flag_1hz_sync     =0;	  
reg flag_RESET_time_OK=0;
reg flag_RESET_time   =0;

reg i_izl_reg=0;
reg i_get_reg=0;
						 

assign time_rst  = time_rst_reg;
assign flg_control={flg_control_reg[9],flg_control_reg[8],CRC_control_reg1, flg_control_reg[6], flg_control_reg[5], flg_control_reg[4], flg_control_reg[3],flg_control_reg[2], flg_control_reg[1], flg_control_reg[0]};

//assign CRC_control = flg_control_reg[0]^flg_control_reg[1]^flg_control_reg[2]^flg_control_reg[3]^flg_control_reg[4]^flg_control_reg[5]^flg_control_reg[6];

always @(posedge clk) sync_reg<={sync_reg[2:0],sync_in}; //поиcк фронта сигнала sync
always @(posedge clk) tick4<={tick4[2:0],RCV};      //поиск фронта сигнала 
always @(posedge clk) 
begin
	//---------поиск фронтов------------------------------------
		
		tick6<={tick6[2:0],event_rst};      //поиск фронта сигнала 	 event_rst
		tick2<={tick2[2:0],T1us};     //поиск фронта сигнала T1us
		tick_TNO<={tick_TNO[2:0],tno_reg};
				
	//------------------------------------------------------
end

always @(posedge clk)

if ((sync_reg[3:1]==3'b011)||(tick_TNO[3:1]==3'b011)) 
			begin
				time_from_start<=32'h00000000;
				time_rst_reg<=1;
				sch_sync_reg<=0;
						
			end

		else
		begin
		
			if (tick2[3:1]==3'b011)

						begin
						
						if (sch_sync_reg<20) sch_sync_reg<=sch_sync_reg+1; else begin time_rst_reg<=0; end //выдерживаем флаг time_rst_reg в поднятом состоянии 50 мкс, для надёги
						
						if (flag_RESET_time==0)  // счётчик микросекунд от старта, шкала времени
							begin
								time_from_start<=time_from_start+1;
								flag_RESET_time_OK=0;
							end
						else begin
							     time_from_start<=0;
							  	 flag_RESET_time_OK=1;
							 end
						
						end
		end


always @(posedge clk)


if (tick4[3:1]==3'b011)
	begin
		if ((CMND[15:8])!=Delay_RUN_COMMAND)
		begin
		
			TNO_rg <=TNO;
			TOBM_rg<=TOBM;
			TNC_rg <=TNC;
			TNI_rg <=TNI;//маскируем старший бит отвечающий за  интервал излучения нулевой частоты
			TKI_rg <=TKI;
			TNP_rg <=TNP;
			TKP_rg <=TKP;
			CMND_rg<=CMND|16'hFFFF; //младший байт - отработанные эвенты
			
			//Tizl_ZERO_flag<=TNI[31];
			
			flg_control_reg<=flg_control_reg&(~CMND[7:0])&10'b0011111111; 
			
						
		end else
		
		begin
		
			TNO_rg2 <=TNO;
			TOBM_rg2<=TOBM;
			TNC_rg2 <=TNC;
			TNI_rg2 <=TNI;
			TKI_rg2 <=TKI;
			TNP_rg2 <=TNP;
			TKP_rg2 <=TKP;
			CMND_rg2<=CMND|16'hFFFF;
			
			flg_control_reg<=flg_control_reg&(~CMND[7:0])&10'b0011111111; 
		
				
		end 
	end
else
	
if ((CMND_rg == SYNC_COMMAND)||(CMND_rg == NOT_SYNC_COMMAND)||(CMND_rg == RESET_COMMAND))  //проверка что пришла команда  - СБРОС

begin
		
   if (CMND_rg != NOT_SYNC_COMMAND)      sync_flag  <=1;	//флаг разрешающий синхронизацию	
	
	if (CMND_rg == NOT_SYNC_COMMAND)  flag_NOT_sync  <=1;  
	if (CMND_rg ==    RESET_COMMAND)  flag_RESET_time<=1;   //сброс счётчика времени без синхронизации
	if (CMND_rg ==     SYNC_COMMAND)  flag_NOT_sync  <=0;  //сброс счётчика времени по синхроимпульсу 
	
	flag_reset_from_TNO<=0;
	

	tno_reg <=0;
	tno1_reg <=0;
   delay_tno1	<=0;
	tno_x_reg<=0;
	tnc_reg <=0;
	tobm_reg<=0;
	tni_reg <=0;
	tki_reg <=0;
	tnp_reg <=0;
	tkp_reg <=0; 

	delay_tno	<=0;  //регистры задержек
	delay_tno_x <=0;
	delay_tno1	<=0;
	delay_tnc	<=0;
	delay_tobm	<=0;
	delay_tni	<=0;
	delay_tki	<=0;
	delay_tnp	<=0;
	delay_tkp	<=0;
	
		
	CMND_rg<=32'h00000000; 
    
end
	else if (flag_RESET_time_OK==1) 
	
	begin
	flag_RESET_time<=0;  // флаг сброса счётчика времени
	flg_control_reg<=0;
	sync_flag  <=0;
	flag_reset_from_TNO<=0; 
	
	if (flag_reset_from_TNO==1'b1)
	begin
		TNO_rg <=32'hffffffff;
		TOBM_rg<=32'hffffffff;
		TNC_rg <=32'hffffffff;
		TNI_rg <=32'hffffffff;
		TKI_rg <=32'hffffffff;
		TNP_rg <=32'hffffffff;
		TKP_rg <=32'hffffffff;
	end
		
	Interval_TP<=0;
	Interval_TI<=0;
	
	ERROR_TNI<=0;
	ERROR_TNP<=0;
		
	tno_reg <=0;
	//tno1_reg <=0;
	tno_x_reg<=0;
	tnc_reg <=0;
	tobm_reg<=0;
	tni_reg <=0;
	tki_reg <=0;
	tnp_reg <=0;
	tkp_reg <=0; 

	delay_tno	<=0;  //регистры задержек
	delay_tno1	<=0;
	delay_tno_x <=0;
	delay_tnc	<=0;
	delay_tobm	<=0;
	delay_tni	<=0;
	delay_tki	<=0;
	delay_tnp	<=0;
	delay_tkp	<=0;
	
	CMND_rg<=32'h00000000; 
	
	end else

	begin 

	if (tobm_reg)
	begin
		TNO_rg <=TNO_rg2;
		TOBM_rg<=TOBM_rg2;
		TNC_rg <=TNC_rg2;
		TNI_rg <=TNI_rg2;
		TKI_rg <=TKI_rg2;
		TNP_rg <=TNP_rg2;
		TKP_rg <=TKP_rg2;
		CMND_rg<=CMND_rg2;
		
		//Tizl_ZERO_flag<=TNI_rg2[31];
		
			
	end
			

		if (tno_reg==1)  begin sync_flag  <=1;	flag_reset_from_TNO<=1; end//флаг разрешающий синхронизацию	
		

		flg_control_reg<=flg_control_reg|{6'h0,ERROR_TNI|ERROR_TNP,PPI_fail_reg,1'h0,tno_reg5,tnc_reg5,tni_reg,tki_reg5,tnp_reg5,tkp_reg5,tobm_reg5};
		
		//tni_reg - может быть в "1" а tni_reg5 - в "0" так как есть интервал излучения нулевой частоты (запрещён импульс излучения, но он должен быть отработан)
				
		PPI_fail_reg<=PPI_fail;
							
	//------------------------------------------------------------------------------------------------------------------	
		
			if ((TNP_rg ==time_from_start)&&(!tnp_reg)&&(TNP_rg !=0)) begin tnp_reg <=1; TNP_rg<=32'h7FFFFFFF; end	 
				else if (tnp_reg )  if (delay_tnp <13  ) delay_tnp <=delay_tnp +1; else begin delay_tnp <=0; tnp_reg <=0; end
			
			if ((TKP_rg ==time_from_start)&&(!tkp_reg)&&(TKP_rg !=0)) begin tkp_reg <=1; TKP_rg<=32'h7FFFFFFF; end
				else if (tkp_reg )  if (delay_tkp <13  ) delay_tkp <=delay_tkp +1; else begin delay_tkp <=0; tkp_reg <=0; end
			
			if ((TKI_rg ==time_from_start)&&(!tki_reg)&&(TKI_rg !=0)) begin tki_reg <=1; TKI_rg<=32'h7FFFFFFF; end
				else if (tki_reg )  if (delay_tki <13  ) delay_tki <=delay_tki +1; else begin delay_tki <=0; tki_reg <=0; end
			
			if ((TNI_rg ==time_from_start)&&(!tni_reg)&&(TNI_rg !=0)) begin tni_reg <=1; TNI_rg<=32'h7FFFFFFF; end	
				else if (tni_reg )  if (delay_tni <13  ) delay_tni <=delay_tni +1; else begin delay_tni <=0; tni_reg <=0; end
			
			if ((TOBM_rg==time_from_start)&&(!tobm_reg)&&(TOBM_rg !=0)) begin tobm_reg<=1; TOBM_rg<=32'h7FFFFFFF;end
				else if (tobm_reg)  if (delay_tobm<13  ) delay_tobm<=delay_tobm+1; else begin delay_tobm<=0; tobm_reg<=0; end 
			
			if ((TNC_rg ==time_from_start)&&(!tnc_reg)) begin tnc_reg <=1; TNC_rg<=32'h7FFFFFFF;end
				else if (tnc_reg )  if (delay_tnc <13  ) delay_tnc <=delay_tnc +1; else begin delay_tnc <=0; tnc_reg <=0; end
			
			if ((TNO_rg ==time_from_start)&&(!tno_reg)) begin tno_reg <=1; TNO_rg<=32'h7FFFFFFF; end
				else if (tno_reg )  if (delay_tno <13  ) delay_tno <=delay_tno +1; else begin delay_tno <=0; tno_reg <=0; end
			
			if ((tno_reg5)&&(!tno_x_reg)) begin tno_x_reg <=1;end
				else if (tno_x_reg )  if (delay_tno_x <26  ) delay_tno_x <=delay_tno_x +1; else begin delay_tno_x <=0; tno_x_reg<=0; end
			
			if ((time_from_start==0)&&(!tno1_reg)&&(delay_tno1==0)) begin tno1_reg<=1; TNO1_rg<=32'h7FFFFFFF; end
			else if (tno1_reg)  
				begin
					if (delay_tno1<13  ) delay_tno1<=delay_tno1+1; else	tno1_reg<=0; 
				end	
					else
						begin 
							if (time_rst_reg==0) delay_tno1<=0; 
						end
	
	//------------------------------------------------------------------------------------------------------------------							
	
	
	if (tnp_reg) Interval_TP<=1; else if (tkp_reg ) Interval_TP<=0;
	if (tni_reg) Interval_TI<=1; else if (tki_reg5) Interval_TI<=0;
	
	// регистры флагов

	tno_reg5       <=tno1_reg;   //этот флаг сообщает что обзор заканчивается
	tno_x_reg5     <=tno_x_reg;   //этот флаг сообщает что обзор заканчивается
	tnc_reg5       <=tnc_reg;
	tobm_reg5      <=tobm_reg;
	
	tki_reg5       <=tki_reg|tno_reg5;
	tkp_reg5       <=tkp_reg;
	t1hz_reg5      <=t1hz_reg;
	
	//tki_reg6<=tki_reg5|tno_reg5;
	tki_reg6<=tki_reg5;
	tkp_reg6<=tkp_reg5;
	
	tni_reg6<=tni_reg5&(~Interval_TP);//защита от перекоса интервалов
	tnp_reg6<=tnp_reg5&(~Interval_TI);//защита от перекоса интервалов
	
	//tni_reg6<=tni_reg5;//защита от перекоса интервалов
	//tnp_reg6<=tnp_reg5;//защита от перекоса интервалов
	
	tni_reg5<=tni_reg;
	tnp_reg5<=tnp_reg;
	
	if ((Interval_TP!=0)&&(tni_reg)) ERROR_TNI<=1; else if (tnc_reg) ERROR_TNI<=0;
	if ((Interval_TI!=0)&&(tnp_reg)) ERROR_TNP<=1; else if (tnc_reg) ERROR_TNP<=0;
	
		FLAG_tobm_reg<=(PPI_fail_reg|tnc_reg|tni_reg|tnp_reg|tobm_reg|tki_reg|tkp_reg);//PPI_fail,tki_reg,tkp_reg
		ERROR_SUM_reg<=ERROR_TNP|ERROR_TNI;
		CRC_control_reg1 <= flg_control_reg[0]^flg_control_reg[1]^flg_control_reg[2]^flg_control_reg[3]^flg_control_reg[4]^flg_control_reg[5]^flg_control_reg[6];
	 
end
	
	assign error = ERROR_SUM_reg;
	assign I_izl = Interval_TI;
	assign I_get = Interval_TP;
	
   assign TKP_o = tkp_reg6;
   assign TNP_o = tnp_reg6;
   assign TKI_o = tki_reg6;
   assign TNI_o = tni_reg6;

//	assign reset_contol_TNO = flag_RESET_time;

   assign reset_contol_TNO = 0;
	
	assign tst_32    = TOBM;//time_from_start;
	
	assign TNP_f     = tnp_reg;
	assign TKP_f     = tkp_reg;
	assign TNC_f     = tnc_reg;
	assign TKI_f     = tki_reg5;
	assign TNI_f     = tni_reg;
	assign TNO_f     = tno_reg5; //формируем сигнал ТНО в начале обзора в зависимости от наличия синхронизации
	assign TOBM_f    = tno_x_reg5;// tno_x_reg5;
	
	assign TOBM_plis = FLAG_tobm_reg;
	
	
endmodule 