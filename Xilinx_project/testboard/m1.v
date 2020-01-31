`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:39:46 09/10/2015 
// Design Name: 
// Module Name:    tst_sg1 
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
module tst_sg1(
	 input clk,
	 input t5min,
	 input clk5mhz,
    input [7:0] upr,
	 input TNO,
    input TNC,
    input TNI,
    input TKI,
    input TNP,
    input TKP,
    input TOBM,
	 input IntI,
	 input IntP,
	 input Error,
    output sig1,
    output sig2,
	 output contrl
    );

reg out_reg1;
reg out_reg2;

reg [5:0] sum_reg=0;
reg sch_delay=0;
reg flag_sum=0;


assign sig1 = out_reg1;
assign sig2 = out_reg2;

assign contrl =sum_reg[0];

always @(posedge clk)
begin

sum_reg[0]<=TNC|TNO|TNI|TKI|TNP|TKP;
sum_reg[1]<=sum_reg[0];
sum_reg[2]<=sum_reg[1];
sum_reg[3]<=sum_reg[2];
sum_reg[4]<=sum_reg[3];

end


always @(posedge clk)
begin

	if (upr==1) 
	begin
	out_reg1<=TNC;
	out_reg2<=IntI;
	end
	
	if (upr==2) 
	begin
	out_reg1<=TNC;
	out_reg2<=IntP;
	end
		
	if (upr==3) 
	begin
	out_reg1<=IntI;
	out_reg2<=IntP;
	end
	
	if (upr==4) 
	begin
	out_reg1<=TNO;
	out_reg2<=TNC;
	end
	
	if (upr==5) 
	begin
	out_reg1<=TNC;
	out_reg2<=TNP;
	end
		
	if (upr==6) 
	begin
	out_reg1<=TNC;
	out_reg2<=TKP;
	end
	
	if (upr==7) 
	begin
	out_reg1<=TNC;
	out_reg2<=TNI;
	end
	
	if (upr==8) 
	begin
	out_reg1<=TNC;
	out_reg2<=TKI;
	end
	
	if (upr==9) 
	begin
	out_reg1<=TNC;
	out_reg2<=Error;
	end
			
	if (upr==10) 
	begin
	out_reg1<=TNC;
	out_reg2<=TOBM;
	end
	
	if (upr==11) 
	begin
	out_reg1<=TNC;
	out_reg2<=IntP|IntI;
	end
	
   if (upr==0) 
	begin
	out_reg1<=t5min;
	out_reg2<=clk5mhz;
	end	

end

endmodule
