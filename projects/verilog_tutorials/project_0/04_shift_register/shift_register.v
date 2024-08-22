module shift_register
#(
	parameter bit_size = 8
)
(
	input 				  clk,
	input 				  load,
	input 				  Sin,
	input  [bit_size-1:0] d,
	output [bit_size-1:0] q
);

	mux_dff
	u_mux_dff(
		.clk				(clk				),
		.load				(load				),
		.in0				(Sin				),
		.in1				(d[0]				),
		.q					(q[0]				)
	);

	genvar i;
	generate
		for (i=1; i<bit_size; i=i+1) begin : shift_register_block
			mux_dff
			u_mux_dff(
				.clk				(clk				),
				.load				(load				),
				.in0				(q[i-1]				),
				.in1				(d[i]				),
				.q					(q[i]				)
			);
		end
	endgenerate

endmodule

module mux_dff
(
	input clk,
	input load,
	input in0,
	input in1,
	output reg q
);

	reg mux_out;

	always @ (*) begin
		case(load)
			0 : mux_out = in0;
			1 : mux_out = in1;
		endcase
	end

	always @ (posedge clk) begin
		q <= mux_out;
	end
endmodule
