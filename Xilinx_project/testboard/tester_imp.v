//-----------------------------------------------------------------------------
//
// Title       : tester_imp
// Design      : arria5_tst1
// Author      : imk
// Company     : nasa
//
//-----------------------------------------------------------------------------
//
// File        : c:\My_Designs\b072\arria5_tst1\src\tester_imp.v
// Generated   : Tue Apr 24 14:52:43 2018
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
//{module {tester_imp}}
module tester_imp (
	output reg [15:0] tni,
	output reg [15:0] tni1,
	output reg [15:0] tki,
	output reg [15:0] t1_4,
	output reg [15:0] tki1,
	output reg [15:0] tnp,
	output reg [15:0] tkp,
	output reg [15:0] tkp1,
	output reg [15:0] tobm,
	output reg [15:0] tnc,
	output reg [15:0] tno,
	output reg [31:0] rezerv4,
	output reg [31:0] rezerv,
	output reg [31:0] rezerv1,
	output reg [31:0] rezerv2,
	output reg [31:0] rezerv3,
	output reg [31:0] int_I,
	output reg [31:0] int_P,
	output reg [31:0] int_TNC,
	output reg [31:0] int_TNO,
	output reg [24:0] control,
	output wire int_event,
	input  wire clk,
	input  wire tus,
	input  wire [15:0] i,
	input  wire rst
);

parameter min_delta_TNC=1000;//256 us
parameter min_delta_TNO=4000000;//1 sec

reg [31:0] tni_delta=0;
reg [15:0] tni_imp=0;

reg [31:0] tni1_delta=0;
reg [15:0] tni1_imp=0; 

reg [31:0] tki_delta=0;
reg [15:0] tki_imp=0; 

reg [31:0] t1_4_delta=0;
reg [15:0] t1_4_imp=0; 	  

reg [31:0] tki1_delta=0;
reg [15:0] tki1_imp=0; 

reg [31:0] tnp_delta=0;
reg [15:0] tnp_imp=0; 

reg [31:0] tkp_delta=0;
reg [15:0] tkp_imp=0; 

reg [31:0] tkp1_delta=0;
reg [15:0] tkp1_imp=0; 

reg [31:0] tobm_delta=0;
reg [15:0] tobm_imp=0; 

reg [31:0] tnc_delta=0;
reg [15:0] tnc_imp=0;

reg [31:0] tno_delta=0;
reg [15:0] tno_imp=0;

reg [31:0] reg_interv_I=0;
reg [31:0] reg_interv_P=0;
reg [31:0] interv_TNC=0;
reg [31:0] interv_TNO=0;

reg [15:0] control_reg=0;

reg [2:0] front_us=0;
reg [2:0] front0=0;
reg [2:0] front1=0;
reg [2:0] front2=0;
reg [2:0] front3=0;
reg [2:0] front4=0;
reg [2:0] front5=0;
reg [2:0] front6=0;
reg [2:0] front7=0;
reg [2:0] front8=0;
reg [2:0] front9=0;
reg [2:0] frontA=0;
reg [2:0] frontB=0;
reg [2:0] frontC=0;
reg [2:0] frontD=0;
reg [2:0] frontE=0;
reg [2:0] frontF=0;

reg flag_tniZ=0;
reg flag_tni1Z=0;
reg flag_tkiZ=0;
reg flag_t1_4Z=0;
reg flag_tki1Z=0;
reg flag_tnpZ=0;
reg flag_tkpZ=0;
reg flag_tkp1Z=0;
reg flag_tobmZ=0;
reg flag_tncZ=0;
reg flag_tnoZ=0;
reg flag_rezerv4Z=0;
reg flag_rezervZ=0;
reg flag_rezerv1Z=0;
reg flag_rezerv2Z=0;
reg flag_rezerv3Z=0;

reg flag_tni=0;
reg flag_tni1=0;
reg flag_tki=0;
reg flag_t1_4=0;
reg flag_tki1=0;
reg flag_tnp=0;
reg flag_tkp=0;
reg flag_tkp1=0;
reg flag_tobm=0;
reg flag_tnc=0;
reg flag_tno=0;
reg flag_rezerv4=0;
reg flag_rezerv=0;
reg flag_rezerv1=0;
reg flag_rezerv2=0;
reg flag_rezerv3=0;
reg flag_us=0;

reg flag_interv_I=0;
reg flag_interv_P=0;
reg flag_interv_TNC=0;
reg flag_interv_TNO=0;
reg error_int_IP =0;
reg error_imp_TNI  =0;
reg error_imp_TNP  =0;
reg error_imp_TKI  =0;
reg error_imp_TKP  =0;
reg error_imp_TNC=0;
reg error_imp_TNO=0;


//assign int_event=   flag_tniZ|flag_tni1Z  |flag_tkiZ    |flag_t1_4Z   |
//				   flag_tki1Z|flag_tnpZ   |flag_tkpZ    |flag_tkp1Z   |flag_tobmZ|flag_tncZ|
//				flag_rezerv4Z|flag_rezervZ|flag_rezerv1Z|flag_rezerv2Z|flag_rezerv3Z;
				
assign int_event=   flag_tkiZ|flag_t1_4Z|flag_tkpZ|flag_tncZ|flag_tnoZ;

always @(posedge clk)  front_us<={front_us[1:0],tus};
always @(posedge clk)  front0  <={front0  [1:0],i[15]};//tni
always @(posedge clk)  front1  <={front1  [1:0],i[14]};//tni1
always @(posedge clk)  front2  <={front2  [1:0],i[13]};//tki
always @(posedge clk)  front3  <={front3  [1:0],i[12]};//t1_4	
always @(posedge clk)  front4  <={front4  [1:0],i[11]};//tki1	
always @(posedge clk)  front5  <={front5  [1:0],i[10]};//tnp
always @(posedge clk)  front6  <={front6  [1:0],i[ 9]};//tkp 
always @(posedge clk)  front7  <={front7  [1:0],i[ 8]};//tkp1 
always @(posedge clk)  front8  <={front8  [1:0],i[ 7]};//tobm 
always @(posedge clk)  front9  <={front9  [1:0],i[ 6]};//tnc
always @(posedge clk)  frontA  <={frontA  [1:0],i[ 5]};//tno
always @(posedge clk)  frontB  <={frontB  [1:0],i[ 4]};//rezerv4
always @(posedge clk)  frontC  <={frontC  [1:0],i[ 3]};//rezerv
always @(posedge clk)  frontD  <={frontD  [1:0],i[ 2]};//rezerv1
always @(posedge clk)  frontE  <={frontE  [1:0],i[ 1]};//rezerv2
always @(posedge clk)  frontF  <={frontF  [1:0],i[ 0]};//rezerv3

always @(posedge clk) if (front_us==3'b001) flag_us     <=1; else flag_us <=0;
always @(posedge clk) if (front0  ==3'b011) flag_tni    <=1; else if (front0  ==3'b110) begin flag_tni    <=0; flag_tniZ    <=1;end else flag_tniZ    <=0;
always @(posedge clk) if (front1  ==3'b011) flag_tni1   <=1; else if (front1  ==3'b110) begin flag_tni1   <=0; flag_tni1Z   <=1;end else flag_tni1Z   <=0;
always @(posedge clk) if (front2  ==3'b011) flag_tki    <=1; else if (front2  ==3'b110) begin flag_tki    <=0; flag_tkiZ    <=1;end else flag_tkiZ    <=0;
always @(posedge clk) if (front3  ==3'b011) flag_t1_4   <=1; else if (front3  ==3'b110) begin flag_t1_4   <=0; flag_t1_4Z   <=1;end else flag_t1_4Z   <=0;
always @(posedge clk) if (front4  ==3'b011) flag_tki1   <=1; else if (front4  ==3'b110) begin flag_tki1   <=0; flag_tki1Z   <=1;end else flag_tki1Z   <=0;
always @(posedge clk) if (front5  ==3'b011) flag_tnp    <=1; else if (front5  ==3'b110) begin flag_tnp    <=0; flag_tnpZ    <=1;end else flag_tnpZ    <=0;
always @(posedge clk) if (front6  ==3'b011) flag_tkp    <=1; else if (front6  ==3'b110) begin flag_tkp    <=0; flag_tkpZ    <=1;end else flag_tkpZ    <=0;
always @(posedge clk) if (front7  ==3'b011) flag_tkp1   <=1; else if (front7  ==3'b110) begin flag_tkp1   <=0; flag_tkp1Z   <=1;end else flag_tkp1Z   <=0;
always @(posedge clk) if (front8  ==3'b011) flag_tobm   <=1; else if (front8  ==3'b110) begin flag_tobm   <=0; flag_tobmZ   <=1;end else flag_tobmZ   <=0;
always @(posedge clk) if (front9  ==3'b011) flag_tnc    <=1; else if (front9  ==3'b110) begin flag_tnc    <=0; flag_tncZ    <=1;end else flag_tncZ    <=0;
always @(posedge clk) if (frontA  ==3'b011) flag_tno    <=1; else if (frontA  ==3'b110) begin flag_tno    <=0; flag_tnoZ    <=1;end else flag_tnoZ    <=0;
always @(posedge clk) if (frontB  ==3'b011) flag_rezerv4<=1; else if (frontB  ==3'b110) begin flag_rezerv4<=0; flag_rezerv4Z<=1;end else flag_rezerv4Z<=0;
always @(posedge clk) if (frontC  ==3'b011) flag_rezerv <=1; else if (frontC  ==3'b110) begin flag_rezerv <=0; flag_rezervZ <=1;end else flag_rezervZ <=0;
always @(posedge clk) if (frontD  ==3'b011) flag_rezerv1<=1; else if (frontD  ==3'b110) begin flag_rezerv1<=0; flag_rezerv1Z<=1;end else flag_rezerv1Z<=0;
always @(posedge clk) if (frontE  ==3'b011) flag_rezerv2<=1; else if (frontE  ==3'b110) begin flag_rezerv2<=0; flag_rezerv2Z<=1;end else flag_rezerv2Z<=0;
always @(posedge clk) if (frontF  ==3'b011) flag_rezerv3<=1; else if (frontF  ==3'b110) begin flag_rezerv3<=0; flag_rezerv3Z<=1;end else flag_rezerv3Z<=0;

always @(posedge clk) //подсчёт длительности импульсов в тактах clk
begin
	if (flag_tni )   begin if (tni_imp <16'hffff) tni_imp <= tni_imp+1'b1; end else begin    tni_imp<=0; end
	if (flag_tni1)   begin if (tni1_imp<16'hffff) tni1_imp<=tni1_imp+1'b1; end else begin   tni1_imp<=0; end
	if (flag_tki )   begin if (tki_imp <16'hffff) tki_imp <= tki_imp+1'b1; end else begin    tki_imp<=0; end
	if (flag_t1_4)   begin if (t1_4_imp<16'hffff) t1_4_imp<=t1_4_imp+1'b1; end else begin   t1_4_imp<=0; end
	if (flag_tki1)   begin if (tki1_imp<16'hffff) tki1_imp<=tki1_imp+1'b1; end else begin   tki1_imp<=0; end
	if (flag_tnp )   begin if (tnp_imp <16'hffff) tnp_imp <= tnp_imp+1'b1; end else begin    tnp_imp<=0; end
	if (flag_tkp )   begin if (tkp_imp <16'hffff) tkp_imp <= tkp_imp+1'b1; end else begin    tkp_imp<=0; end
	if (flag_tkp1)   begin if (tkp1_imp<16'hffff) tkp1_imp<=tkp1_imp+1'b1; end else begin   tkp1_imp<=0; end
	if (flag_tobm)   begin if (tobm_imp<16'hffff) tobm_imp<=tobm_imp+1'b1; end else begin   tobm_imp<=0; end
	if (flag_tnc )   begin if (tnc_imp <16'hffff) tnc_imp <= tnc_imp+1'b1; end else begin    tnc_imp<=0; end
	if (flag_tno )   begin if (tno_imp <16'hffff) tno_imp <= tno_imp+1'b1; end else begin    tno_imp<=0; end
	
	if (flag_tniZ) 	tni  [15: 0]<= tni_imp;
	if (flag_tni1Z)	tni1 [15: 0]<=tni1_imp;
	if (flag_tkiZ)	tki  [15: 0]<= tki_imp;
	if (flag_t1_4Z)	t1_4 [15: 0]<=t1_4_imp;
	if (flag_tki1Z)	tki1 [15: 0]<= tki1_imp;
	if (flag_tnpZ)	tnp  [15: 0]<= tnp_imp;
	if (flag_tkpZ)	tkp  [15: 0]<= tkp_imp;
	if (flag_tkp1Z)	tkp1 [15: 0]<=tkp1_imp;
	if (flag_tobmZ)	tobm [15: 0]<=tobm_imp;
	if (flag_tncZ)	tnc  [15: 0]<= tnc_imp;
	if (flag_tnoZ)	tno  [15: 0]<= tno_imp;
	
	if (front0  ==3'b011) flag_interv_I  <=1; else if (front2  ==3'b110)  begin int_I<=reg_interv_I; flag_interv_I<=0; end
	if (front5  ==3'b011) flag_interv_P  <=1; else if (front6  ==3'b110)  begin int_P<=reg_interv_P; flag_interv_P<=0; end	
	
end


always @(posedge clk) //подсчёт длительности 
if (flag_us)
begin
	if (flag_interv_I  )    reg_interv_I<=reg_interv_I   +1; else   reg_interv_I<=0;
	if (flag_interv_P  )    reg_interv_P<=reg_interv_P   +1; else   reg_interv_P<=0;	 
end

always @(posedge clk) //подсчёт длительности  TNC
if (front9  ==3'b011)  
begin 
	int_TNC<=interv_TNC; 
	interv_TNC<=0; 
	end 
	else if (flag_us) interv_TNC<=interv_TNC +1; 
		
always @(posedge clk) //подсчёт длительности TNO
if (frontA  ==3'b011)  
begin 
	int_TNO<=interv_TNO; 
	interv_TNO<=0; 
	end 
	else if (flag_us) interv_TNO<=interv_TNO +1; 


always @(posedge clk)
if (rst)
begin
	control<=0;
	error_int_IP<=0;//флаг аварии - пересечения интервалов излучения и приёма, сбрасывается ресетом
	error_imp_TNI<=0;
	error_imp_TNP<=0;
	error_imp_TNC<=0;
	error_imp_TNO<=0;
	
end else
		begin
		if ((flag_interv_I==1)&&(flag_interv_P==1)) error_int_IP<=1; 
		if ((flag_interv_I==1)&&(front0  ==3'b011)) error_imp_TNI<=1;		
		if ((flag_interv_P==1)&&(front5  ==3'b011)) error_imp_TNP<=1;
		if  (int_TNC<min_delta_TNC) error_imp_TNC<=1;
		if  (int_TNO<min_delta_TNO) error_imp_TNO<=1;
	
	//control<=24'b000001111111111111111;
		control<=control|
					  (error_imp_TNO<<20)|
					  (error_imp_TNC<<19)|
					  (error_imp_TNI<<18)|
					  (error_imp_TNP<<17)|
					  (error_int_IP <<16)|
					  (flag_tniZ    <<15)|
					  (flag_tni1Z   <<14)|
					  (flag_tkiZ    <<13)|
					  (flag_t1_4Z   <<12)|
					  (flag_tki1Z   <<11)|
					  (flag_tnpZ    <<10)|
					  (flag_tkpZ    << 9)|
					  (flag_tkp1Z   << 8)|
					  (flag_tobmZ   << 7)|
					  (flag_tncZ    << 6)|
					  (flag_tnoZ    << 5)|
					  (flag_rezerv4Z<< 4)|
					  (flag_rezervZ << 3)|
					  (flag_rezerv1Z<< 2)|
					  (flag_rezerv2Z<< 1)|
					  (flag_rezerv3Z<< 0);				  
					  
		end

endmodule




































