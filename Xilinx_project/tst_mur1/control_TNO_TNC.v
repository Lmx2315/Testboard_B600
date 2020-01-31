//-----------------------------------------------------------------------------
//
// Title       : control_TNO_TNC
// Design      : sinh1_v1
// Author      : Microsoft
// Company     : Microsoft
//
//-----------------------------------------------------------------------------
//
// File        : control_TNO_TNC.v
// Generated   : Fri Mar  7 15:17:51 2014
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
//{module {control_TNO_TNC}}
module control_TNO_TNC ( clk ,clk1us,reset_TNO,reset_TNC ,Time_TNC ,Time_TNO,rst);

output [31:0] Time_TNC ;
wire [31:0] Time_TNC ;
output [31:0] Time_TNO ;
wire [31:0] Time_TNO ;

input reset_TNO ;
wire reset_TNO ;

input rst ;
wire rst ;

input reset_TNC ;
wire reset_TNC ;

input clk ;
wire clk ;
input clk1us ;
wire clk1us ;


reg [3:0] front_t1us=0;	  
reg [3:0] front_tno=0;	 
reg [3:0] front_tnc=0;
reg [3:0] front_rst=0;

reg tno_reg=0,tnc_reg=0;
reg rst_reg=0;


reg [31:0] tno_reg1=0,tno_reg2=0;
reg [31:0] tnc_reg1=0,tnc_reg2=0;

	
always@ (posedge clk)
	front_t1us<={front_t1us[2:0],clk1us};			 
	
always@ (posedge clk)
	front_tno<={front_tno[2:0],reset_TNO};	
	
always@ (posedge clk)
	front_tnc<={front_tnc[2:0],reset_TNC};	
	
always@ (posedge clk)
	front_rst<={front_rst[2:0],rst};	
	
	
always@(posedge clk) 


if (front_rst[3:1]==3'b011)
begin
	tnc_reg1<=0;
	tnc_reg2<=0;
	
	tno_reg1<=0;
	tno_reg2<=0;


end else

begin


	if ((front_tnc[3:1]==3'b001)||(front_tno[3:1]==3'b001))
		
		begin
		
		
			if (front_tnc[3:1]==3'b001)
			
			begin
					tnc_reg1<=0;
					tnc_reg2<=tnc_reg1;		
				//	tnc_reg2<=2000;	
										
			end
			
			if (front_tno[3:1]==3'b001)

			begin
					tno_reg1<=0;
					tno_reg2<=tno_reg1;	
				//	tno_reg2<=3000000;						
			
			end	
	
					
		end	
	
	else
				
		if (front_t1us[3:1]==3'b011)	
					
		  begin
   			 tno_reg1<=tno_reg1+1;
 			    tnc_reg1<=tnc_reg1+1;

				 if (tnc_reg2<tnc_reg1) tnc_reg2<=tnc_reg1;
				 if (tno_reg2<tno_reg1) tno_reg2<=tno_reg1;
				 
		  end	 
end		  
			
		  
		  assign  Time_TNO=tno_reg2;
		  assign  Time_TNC=tnc_reg2;
	

endmodule
