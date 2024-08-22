`ifndef NOINC
`include "../common/riscv_configs.v"
`include "../common/riscv_mux.v"
`endif

module riscv_wb
(
	input i_wb_ctrl_rd_src,
	input [`XLEN-1:0] i_wb_rd_data,
	input [`XLEN-1:0] i_wb_read_data,
	output [`XLEN-1:0] o_wb_rd_result
);

	wire [(2*`XLEN)-1:0] mux_concat_rd;
//	assign mux_concat_rd = {i_wb_read_data, i_wb_rd_data};
	assign mux_concat_rd = {i_wb_rd_data, i_wb_read_data};

	riscv_mux
	#(
		.N_MUX_IN			(2						)
	)
	u_riscv_mux(
		.i_mux_sel			(i_wb_ctrl_rd_src		),
		.i_mux_concat_data	(mux_concat_rd			),
		.o_mux_data			(o_wb_rd_result			)
	);

endmodule
