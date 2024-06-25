module even_parity
(
	input [7:0] a,
	output parity
);
	assign parity = ^a;

endmodule
