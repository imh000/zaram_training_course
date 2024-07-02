module shift_register
#(
	parameter bit_size = 8
)
(
	input 				  clk,
	input 				  load,
	input 				  Sin,
	input  [bit_size-1:0] d,
	output [bit_size-1:0] q,
	output				  Sout
);

		mux_dff
		u_mux_dff(
			.clk				(clk				),
			.load				(load				),
			.Sin				(Sin				),
			.d					(d[0]				),
			.q					(q[0]				)
		);

	genvar i;
	generate
		for (i=1; i<bit_size; i=i+1) begin : shift_register_block
			mux_dff
			u_mux_dff(
				.clk				(clk				),
				.load				(load				),
				.Sin				(q[i-1]				),
				.d					(d[i]				),
				.q					(q[i]				)
			);
		end

		assign Sout = q[7];

	endgenerate
	
endmodule

module mux_dff
(
	input clk,
	input load,
	input Sin,
	input d,
	output reg q,
	output reg Sout
);

	reg mux_out;

	always @ (*) begin
		case(load)
			0 : mux_out = Sin;
			1 : mux_out = d;
		endcase
	end

	always @ (posedge clk) begin
		q <= mux_out;
	end

endmodule
