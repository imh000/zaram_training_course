module latch
#(
	parameter num = 8
)
(
	input clk,
	input [num-1:0]d,
	output reg [num-1:0] q
);
	always @ (*) begin
		if(clk)
			q <= d;
	end
	endmodule

module dff
#(
	parameter num = 10
)
(
	input clk,
	input [num-1:0] d,
	output reg [num-1:0] q
);
	always @ (posedge clk) begin
		q <= d;
	end
	endmodule

