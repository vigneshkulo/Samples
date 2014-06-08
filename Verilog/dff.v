`timescale 1ns / 1ps

module dff(d,c,a,b,e,clk,rst,q,r,t);
input[2:0] d;
input c;
input a;
input b;
input e;
input clk;
input rst;
output q;
output r;
output t;
output fsom;
				reg t;
reg r ;
reg q;
reg x;

always@(posedge clk)
if(rst)
begin
t <= 1'b 0;end
else
begin
t <= e;
end

	IDLE:	if:	

case	(	d	)
case	(	x	)
000: q=a;
001: q=b;
default: $display("Error");
endcase

if( c == 1)
			r <= 1'b 1;
else
r 			<= 1'b 0;
end
fsom = a * b;
			endmodule 
