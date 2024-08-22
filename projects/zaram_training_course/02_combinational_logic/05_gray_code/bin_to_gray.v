module bin_to_gray
(
	input [2:0] bin,
	output [2:0] gray
);
	assign gray = (bin >> 1) ^ bin;
endmodule
