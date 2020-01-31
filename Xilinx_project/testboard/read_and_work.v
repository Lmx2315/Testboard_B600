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
module form_imp_master (clk5mhz,sync_in,RCV,TKP_f,TNP_f ,TKI_f ,TNI_f ,TNC_f ,TOBM_f ,
								TNO_f,TKP_o,TNP_o,TKI_o,TNI_o,
								CMND,TOBM_plis,T1us,clk,time_rst,flg_control,event_rst,
								tst_32,reset_contol_TNO,I_izl,I_get,error,
								DDS_delay,dT_kalibrovka,dT_pomeha,
								Pni1,Pii1,Pnp1,Pip1,QIT1,
								Pni2,Pii2,Pnp2,Pip2,QIT2,
								Pni3,Pii3,Pnp3,Pip3,QIT3,
								N_temp,TNO
								);

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

input [31:0] CMND ;
wire [31:0] CMND ;	

input [15:0] DDS_delay;
input [31:0] dT_kalibrovka;
input [31:0] dT_pomeha;

input [31:0] Pni1;
input [31:0] Pii1;
input [31:0] Pnp1; 
input [31:0] Pip1; 

input [31:0] Pni2;
input [31:0] Pii2;
input [31:0] Pnp2; 
input [31:0] Pip2; 

input [31:0] Pni3;
input [31:0] Pii3;
input [31:0] Pnp3; 
input [31:0] Pip3;

input [15:0] QIT1;
input [15:0] QIT2;
input [15:0] QIT3;

input [31:0] TNO;	  

input [7:0] N_temp;

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

input clk5mhz ;
wire clk5mhz ;


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
reg [2:0] front_1us=0;

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

reg [15:0] reg_DDS_delay=0;
reg [31:0] reg_dT_kalibrovka=0;
reg [31:0] reg_dT_pomeha=0;

reg [31:0] reg_Pni=0;
reg [31:0] reg_Pii=0;
reg [31:0] reg_Pnp=0; 
reg [31:0] reg_Pip=0; 

reg [31:0] reg_Pni1;
reg [31:0] reg_Pii1;
reg [31:0] reg_Pnp1; 
reg [31:0] reg_Pip1; 

reg [31:0] reg_Pni2;
reg [31:0] reg_Pii2;
reg [31:0] reg_Pnp2; 
reg [31:0] reg_Pip2; 

reg [31:0] reg_Pni3;
reg [31:0] reg_Pii3;
reg [31:0] reg_Pnp3; 
reg [31:0] reg_Pip3;

reg [15:0] reg_QIT1;
reg [15:0] reg_QIT2;
reg [15:0] reg_QIT3;

reg [31:0] var_TNC_rg=0;

reg flag_dop_interval=1;
reg [2:0] front_TNC=0;
reg [2:0] front_TOBM=0;	  
reg [7:0] flag_CALCULATION=0;//флаг запуска расчёта интервала	
reg [31:0] Alfa=0;//
reg [7:0] Time_step=1; //шаг времени в счётчеке часов , нужен для остановки и запуска

reg [15:0] quantity_impuls_temp=0; //количество импульсов в темпе1
reg [15:0] quantity_impuls_temp2=0; //количество импульсов в темпе2 
reg [15:0] quantity_impuls_temp3=0; //количество импульсов в темпе3	
reg [ 7:0] quantity_temps=0;


always @(posedge clk)  front_TNC <={front_TNC [1:0],tnc_reg }; //ищем вронт сигнала ТНЦ
always @(posedge clk)  front_TOBM<={front_TOBM[1:0],tobm_reg}; //ищем вронт сигнала ТНЦ	 
always @(posedge clk)  front_1us <={front_1us[1:0],T1us};//ищем фронт T1us
	
reg [7:0] reg_regim=0;	//0 - калибровка 
						//1 - приём помехи
						//2 - первый темп
						//3 - второй темп
						//4 - третий темп	  

always @(posedge clk)
begin	
	
if ((front_TNC ==3'b011)||(front_TOBM==3'b011)) 
	begin 	
		if (front_TNC ==3'b011)
			begin
			if (flag_dop_interval==1)   reg_regim<=0; else  reg_regim<=2;
			flag_CALCULATION<=1;
			end
			else 
				if (front_TOBM==3'b011)
					begin
					if ((quantity_impuls_temp==0)&&(reg_regim<quantity_temps)) 
						begin 
						    reg_regim<=reg_regim+1;
							flag_CALCULATION<=1;
						end	
							else 
								begin 
									if (quantity_impuls_temp>0) flag_CALCULATION<=2; 
								end
					end
	
		Alfa<=time_from_start; //запоминаем текущее время
	end 
	else
	if (flag_CALCULATION==1)
		begin 
			case (reg_regim)  
				8'd0://режим калибровки
				begin
				quantity_impuls_temp<=0;
				end
				8'd1://режим приёма помехи
				begin 
				quantity_impuls_temp<=0;			
				end
				8'd2://режим первого темпа
				begin 
				reg_Pni<=reg_Pni1;
				reg_Pii<=reg_Pii1;
				reg_Pnp<=reg_Pnp1;
				reg_Pip<=reg_Pip1;
				quantity_impuls_temp<=reg_QIT1;
				end
				8'd3://режим второго темпа
				begin
				reg_Pni<=reg_Pni2;
				reg_Pii<=reg_Pii2;
				reg_Pnp<=reg_Pnp2;
				reg_Pip<=reg_Pip2;
				quantity_impuls_temp<=reg_QIT2;
				end	 
				8'd4://режим третьего темпа
				begin
				reg_Pni<=reg_Pni3;
				reg_Pii<=reg_Pii3;
				reg_Pnp<=reg_Pnp3;
				reg_Pip<=reg_Pip3;
				quantity_impuls_temp<=reg_QIT3;
				end
			endcase			
			flag_CALCULATION<=2;
		end
		else
	if (flag_CALCULATION==2)
		begin 
			case (reg_regim)  
				8'd0://режим калибровки
				begin
				TNP_rg <=Alfa+DDS_delay;	
				TKP_rg <=Alfa+DDS_delay+dT_kalibrovka; 
				TOBM_rg<=Alfa+DDS_delay+dT_kalibrovka;
				end
				8'd1://режим приёма помехи
				begin 
				TNP_rg <=Alfa+DDS_delay;
				TKP_rg <=Alfa+DDS_delay+dT_pomeha;
				TOBM_rg<=Alfa+DDS_delay+dT_pomeha;			
				end
				default://режим формирования темпа
				begin
				TNI_rg <=Alfa+reg_Pni;	
				TKI_rg <=Alfa+reg_Pni+reg_Pii;
				TNP_rg <=Alfa+reg_Pni+reg_Pii+reg_Pnp;
				TKP_rg <=Alfa+reg_Pni+reg_Pii+reg_Pnp+reg_Pip;
				TOBM_rg<=Alfa+reg_Pni+reg_Pii+reg_Pnp+reg_Pip;
				quantity_impuls_temp<=quantity_impuls_temp-1; 
				if ((quantity_impuls_temp==1)&&(reg_regim==quantity_temps)) var_TNC_rg<=Alfa+reg_Pni+reg_Pii+reg_Pnp+reg_Pip+8;
				end
			endcase
			flag_CALCULATION<=0;
		end	
end	

always @(posedge clk)
begin
		if (time_from_start==0) TNC_rg<=144;//через 144 мкс после ТНО формируется ТНЦ	  
			else  if (time_from_start>144)TNC_rg<=var_TNC_rg;
end
	



assign time_rst  = time_rst_reg;
assign flg_control={flg_control_reg[9],flg_control_reg[8],CRC_control_reg1, flg_control_reg[6], flg_control_reg[5], flg_control_reg[4], flg_control_reg[3],flg_control_reg[2], flg_control_reg[1], flg_control_reg[0]};

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
if ((sync_reg[3:1]==3'b011)||(tick_TNO[2:0]==3'b001)) 
 begin
 time_from_start<=32'h00000000;
 time_rst_reg<=1;
 sch_sync_reg<=0;

 end
	else
	begin
	if (tick2[2:0]==3'b001)
 	begin
		if (sch_sync_reg<20) sch_sync_reg<=sch_sync_reg+1; else begin time_rst_reg<=0; end //выдерживаем флаг time_rst_reg в поднятом состоянии 50 мкс, для надёги
		if (flag_RESET_time==0)  // счётчик микросекунд от старта, шкала времени
			begin
			time_from_start<=time_from_start+Time_step;
			flag_RESET_time_OK=0;
			end
		else 
			begin
		     time_from_start<=0; 
		  	 flag_RESET_time_OK=1;
			 end
						
	end
	end


always @(posedge clk)

if (tick4[3:1]==3'b011)
begin
		
reg_DDS_delay    <=DDS_delay;
reg_dT_kalibrovka<=dT_kalibrovka;
reg_dT_pomeha    <=dT_pomeha;

reg_Pni1<=Pni1;
reg_Pii1<=Pii1;
reg_Pnp1<=Pnp1; 
reg_Pip1<=Pip1; 

reg_Pni2<=Pni2;
reg_Pii2<=Pii2;
reg_Pnp2<=Pnp2; 
reg_Pip2<=Pip2; 

reg_Pni3<=Pni3;
reg_Pii3<=Pii3;
reg_Pnp3<=Pnp3; 
reg_Pip3<=Pip3;

reg_QIT1<=QIT1;
reg_QIT2<=QIT2;
reg_QIT3<=QIT3;

 TNO_rg  <=TNO; //длительность интервала ТНО 	


if (flag_dop_interval==1) quantity_temps<=N_temp+1; else  quantity_temps<=N_temp;

if ((CMND|16'hFFFF)!=32'h0000FFFF) Time_step<=1; else Time_step<=0;
if ((CMND|16'hFFFF)==32'h0001FFFF) tno_reg <=1; //сброс времени а аккумуляторе часов

flg_control_reg<=flg_control_reg&(~CMND[7:0])&10'b0011111111; 
end
else
	if (front_1us==3'b001)
begin  
	 //------------------------------------------------------------------------------------------------------------------	
		
			if ((TNP_rg ==time_from_start)&&(!tnp_reg)&&(TNP_rg !=0)) begin tnp_reg <=1; end	 
				else if (tnp_reg )  if (delay_tnp <3  ) delay_tnp <=delay_tnp +1; else begin delay_tnp <=0; tnp_reg <=0; end
			
			if ((TKP_rg ==time_from_start)&&(!tkp_reg)&&(TKP_rg !=0)) begin tkp_reg <=1;end
				else if (tkp_reg )  if (delay_tkp <3  ) delay_tkp <=delay_tkp +1; else begin delay_tkp <=0; tkp_reg <=0; end
			
			if ((TKI_rg ==time_from_start)&&(!tki_reg)&&(TKI_rg !=0)) begin tki_reg <=1;  end
				else if (tki_reg )  if (delay_tki <3  ) delay_tki <=delay_tki +1; else begin delay_tki <=0; tki_reg <=0; end
			
			if ((TNI_rg ==time_from_start)&&(!tni_reg)&&(TNI_rg !=0)) begin tni_reg <=1;  end	
				else if (tni_reg )  if (delay_tni <3  ) delay_tni <=delay_tni +1; else begin delay_tni <=0; tni_reg <=0; end
			
			if ((TOBM_rg==time_from_start)&&(!tobm_reg)&&(TOBM_rg !=0)) begin tobm_reg<=1;end
				else if (tobm_reg)  if (delay_tobm<3  ) delay_tobm<=delay_tobm+1; else begin delay_tobm<=0; tobm_reg<=0; end 
			
			if ((TNC_rg ==time_from_start)&&(!tnc_reg)) begin tnc_reg <=1; end
				else if (tnc_reg )  if (delay_tnc <3  ) delay_tnc <=delay_tnc +1; else begin delay_tnc <=0; tnc_reg <=0; end
			
			if ((TNO_rg ==time_from_start)&&(!tno_reg)) begin tno_reg <=1; end
				else if (tno_reg )  if (delay_tno <3  ) delay_tno <=delay_tno +1; else begin delay_tno <=0; tno_reg <=0; end
			
			if ((tno_reg5)&&(!tno_x_reg)) begin tno_x_reg <=1;end
				else if (tno_x_reg )  if (delay_tno_x <8  ) delay_tno_x <=delay_tno_x +1; else begin delay_tno_x <=0; tno_x_reg<=0; end
			
			if ((time_from_start==0)&&(!tno1_reg)&&(delay_tno1==0)) begin tno1_reg<=1;end
			else if (tno1_reg)  
				begin
					if (delay_tno1<3  ) delay_tno1<=delay_tno1+1; else	tno1_reg<=0; 
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
	
	assign tst_32    = N_temp;//time_from_start;
	
	assign TNP_f     = tnp_reg;
	assign TKP_f     = tkp_reg;
	assign TNC_f     = tnc_reg;
	assign TKI_f     = tki_reg5;
	assign TNI_f     = tni_reg;
	assign TNO_f     = tno_reg5; //формируем сигнал ТНО в начале обзора в зависимости от наличия синхронизации
	assign TOBM_f    = tno_x_reg5;// tno_x_reg5;
	
	assign TOBM_plis = FLAG_tobm_reg;
	
	
endmodule 