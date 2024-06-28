module shift_register
#(
	parameter bit_size = 8
)
(
	input clk,
	input load,
	input Sin,
	input [bit_size-1:0] d,
	output [bit_size-1:0] q,
	output Sout
);

	
