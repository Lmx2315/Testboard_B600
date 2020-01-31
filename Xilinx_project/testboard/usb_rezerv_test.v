module usb_test 
(
input upr,
input clk,
output tx_485,
output rts_485
);

reg [31:0] accum=0;

always @(posedge clk)
if (upr)
begin
	accum<=accum+1;
	
end
else accum<=0;

assign tx_485 =accum[5];
assign rts_485=upr;

endmodule