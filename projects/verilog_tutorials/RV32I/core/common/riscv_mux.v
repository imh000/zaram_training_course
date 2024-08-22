`ifndef NOINC
`include "../common/riscv_configs.v"
`endif

module riscv_mux
#(
	parameter N_MUX_IN = 2
)
(
	input	  [$clog2(N_MUX_IN)-1:0]   i_mux_sel,
	input	  [(N_MUX_IN * `XLEN)-1:0] i_mux_concat_data,
	output	  [`XLEN-1:0]			   o_mux_data
);

	wire [`XLEN-1:0] mux_input_arr [0:N_MUX_IN-1];

	genvar i;
	generate
		for(i=0; i<N_MUX_IN; i=i+1) begin
			assign mux_input_arr[i] = i_mux_concat_data[`XLEN*(i+1)-1-:`XLEN];
		end
	endgenerate

	assign o_mux_data = mux_input_arr[i_mux_sel];

endmodule
