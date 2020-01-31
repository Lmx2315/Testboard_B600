//-----------------------------------------------------------------------------
//
// Title       : IMP_delayer
// Design      : arria5_tst1
// Author      : imk
// Company     : nasa
//
//-----------------------------------------------------------------------------
//
// File        : c:\My_Designs\b072\arria5_tst1\src\IMP_delayer.v
// Generated   : Thu Apr 26 14:13:29 2018
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
//{module {IMP_delayer}}
module IMP_delayer (
	output wire o_imp,
	input wire clk,
	input wire imp,
	input wire tus
); 

parameter delay=100*8;


reg [2:0] front1=0;
reg [2:0] front2=0;
reg [31:0] sch=0;
reg flag_imp=0;
reg flag_dimp=0;

always @(posedge clk) front1<={front1[1:0],imp};
always @(posedge clk) front2<={front2[1:0],tus};
always @(posedge clk) if (front1==3'b011) flag_imp<=1; else if (sch>(delay+80))	flag_imp<=0;
	
always @(posedge clk)
	if ((front2==3'b001)&&(flag_imp))
		begin
			 sch<=sch+1; 			
			 if (sch==delay) flag_dimp<=1;			
		end
		else  if (flag_imp==0)  begin sch<=0; flag_dimp<=0; end	
			
assign 	o_imp = flag_dimp;	
		
endmodule

