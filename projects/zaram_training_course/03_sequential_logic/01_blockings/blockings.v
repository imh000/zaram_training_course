module block
(
	input clk,
	input d,
	output reg q
);

	reg n1;

	always @ (posedge clk) begin
		n1 = d;
		q = n1;
	end
	endmodule

module non_block
(
	input clk,
	input d,
	output reg q
);

	reg n1;

	always @ (posedge clk) begin
		n1 <= d;
		q <= n1;
	end
	endmodule
