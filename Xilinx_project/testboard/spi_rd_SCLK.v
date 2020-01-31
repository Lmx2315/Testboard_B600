
//{{ Section below this comment is automatically maintained
//   and may be overwritten
//{module {Block_upr_spi1}}
module Block_rd_spi ( clk,sclk,mosi,miso,cs ,rst ,inport );	

parameter Nbit=8;	
parameter param_adr=1; 

input  [Nbit-1:0] inport ;
wire   [Nbit-1:0] inport ;

output  miso;

input clk ;
wire clk ;	 
input sclk ;
wire sclk ;
input mosi ;
wire mosi ;
input cs ;
wire cs ;
input rst ;
wire rst ;	

reg [7:0] data_in=0; 
 
reg flag=0;   
reg [7:0] sch=5;	   
reg [Nbit:0] reg_out=0;	


always @(sclk or cs)
if (cs==1)
begin
sch<=0;	
flag<=0;
data_in<=0;
end
else	
if (sclk==1)
begin 
	data_in<={data_in[6:0],mosi};	  
	sch<=sch+1;  
end	
else
if (sclk==0)
begin  
	if (flag) reg_out<=reg_out<<1; else reg_out<=inport;
	if (sch==7) 
	begin 
		if (data_in==param_adr)	flag<=1; 
	end else if (sch==Nbit+8)	flag<=0; 	
end
 
assign    miso =  (flag==0)?1'h1:reg_out[Nbit];	
	
endmodule
