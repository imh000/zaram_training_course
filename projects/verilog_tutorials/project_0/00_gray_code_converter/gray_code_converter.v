module bin_to_gray
#(
	parameter bit_size = 8
)
(
	input    [bit_size-1:0]   bin,
	output   [bit_size-1:0]   gray
);

	assign gray = (bin >> 1) ^ bin;

endmodule

module gray_to_bin
#(
	parameter bit_size = 8
)
(
	input    [bit_size-1:0]   gray,
	output   [bit_size-1:0]   bin
);

	assign bin = (bin >> 1) ^ gray;

endmodule
