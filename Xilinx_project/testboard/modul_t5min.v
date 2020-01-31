//-----------------------------------------------------------------------------
//
// Title       : modul_t5min
// Design      : arria5_tst1
// Author      : imk
// Company     : nasa
//
//-----------------------------------------------------------------------------
//
// File        : c:\My_Designs\b072\arria5_tst1\src\modul_t5min.v
// Generated   : Mon Apr 16 11:00:29 2018
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
//{module {modul_t5min}}
module modul_t5min ( clk ,t1us ,t5min );

output t5min ;
wire t5min ;

input clk ;
wire clk ;
input t1us ;
wire t1us ;

reg [2:0] front_1us=0;
reg [31:0] sch=19900000;  
reg flag_t5min=0;

always @(posedge clk) front_1us<={front_1us[1:0],t1us};

always @(posedge clk)
	
	begin
		
	if (front_1us==3'b011) sch<=sch+1;
		
	if ((sch==60000000)&&(front_1us==3'b011)) 
		begin 
		flag_t5min<=1;
		sch<=0;
		end
			else flag_t5min<=0; //oaeia? ia 20 nae		
	end	
	
	assign 	t5min = flag_t5min;
	

endmodule
