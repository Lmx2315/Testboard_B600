`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:36:30 07/16/2015 
// Design Name: 
// Module Name:    control_F5_F64 
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
module control_F5_F64(
    input f5,
    input f64,
    input clk,
    output ERROR_5,
    output ERROR_64,
	 output t1us,
	 output f16
    );
	 
reg [7:0] sch5_1us=0;	 
reg [7:0] sch5=0;
reg [7:0] sch64=0;
reg [7:0] sch_tst_5=0;
reg [7:0] sch_tst_64=0;
reg [7:0] sch_tst_Main=0;

reg [7:0] schREZ_1us=0;
reg t1us5_reg=0;
reg t1usREZ_reg=0;

reg [4:0] front_5=0;
reg [4:0] front_64=0;

reg FLAG_ERROR5=0;
reg FLAG_ERROR64=0;

reg [7:0] sch_fout=0;

wire frt_5;
wire frt_64;

assign frt_5=(~front_5[4])&front_5[3]&front_5[2];
assign frt_64=(~front_64[4])&front_64[3]&front_64[2];

always@ (posedge clk)
begin

front_5<={front_5[3:0],sch5[0]};
front_64<={front_64[3:0],sch64[3]};

if (schREZ_1us== 9) t1usREZ_reg<=1; else
if (schREZ_1us==19) t1usREZ_reg<=0;

if (schREZ_1us!=19) schREZ_1us<=schREZ_1us+1;
else schREZ_1us<=0;


if (sch_tst_Main!=128) 
begin

if (frt_5) sch_tst_5<=sch_tst_5+1;
if (frt_64) sch_tst_64<=sch_tst_64+1;

sch_tst_Main<=sch_tst_Main+1; 

end
else
begin

if (sch_tst_5>6) FLAG_ERROR5<=0; else FLAG_ERROR5<=1; 
if (sch_tst_64>6) FLAG_ERROR64<=0; else FLAG_ERROR64<=1; 

 sch_tst_5<=0;
 sch_tst_64<=0;
 sch_tst_Main<=0;

end

end

always@ (posedge f5)
begin

sch5<=sch5+1;

if (sch5_1us==2) t1us5_reg<=1; else
if (sch5_1us==4) t1us5_reg<=0;

if (sch5_1us!=4) sch5_1us<=sch5_1us+1;
else sch5_1us<=0;

end



always@ (posedge f64)
begin
sch64<=sch64+1;
end

assign ERROR_5  = FLAG_ERROR5;
assign ERROR_64 = FLAG_ERROR64;
//assign t1us =(FLAG_ERROR5)?t1usREZ_reg:t1us5_reg;
//assign t1us =t1us5_reg;
assign t1us =sch64[5];
assign f16 = sch64[0];


endmodule
