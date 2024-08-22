`ifndef NOINC
`include "../common/riscv_configs.v"
`include "../common/riscv_dmem.v"
`include "../common/riscv_dmem_interface.v"
`endif

module riscv_mem
(
	input i_clk,
	input i_rstn,

	input [2:0] i_mem_funct3,
	input [1:0] i_mem_ctrl_result_src,

	input i_mem_ctrl_mem_write,
	input [`XLEN/8-1:0] i_mem_ctrl_byte_sel,

	input [`XLEN-1:0] i_mem_write_data,
	input [`XLEN-1:0] i_mem_alu_result,
	input [`XLEN-1:0] i_mem_imm,
	input [`XLEN-1:0] i_mem_pc_plus_imm,
	input [`XLEN-1:0] i_mem_pc_plus_4,
	output [`XLEN-1:0] o_mem_rd_result,
	output [`XLEN-1:0] o_mem_read_data
);

	wire [`XLEN-1:0] dmem_addr;
	wire dmem_mem_write;
	wire [`XLEN-1:0] dmem_wr_data;
	wire [3:0] dmem_byte_sel;
	wire [`XLEN-1:0] dmem_rd_data;

	wire [(4*`XLEN)-1:0] mux_concat_src_result;
	assign mux_concat_src_result = {i_mem_pc_plus_4, i_mem_pc_plus_imm, i_mem_imm, i_mem_alu_result};

	riscv_dmem_interface
	u_riscv_dmem_interface(
		.i_clk					(i_clk					),
		.i_dmem_intf_addr		(i_mem_alu_result		),
		.i_dmem_intf_wr_en		(i_mem_ctrl_mem_write	),
		.i_dmem_intf_wr_data	(i_mem_write_data		),
		.i_dmem_intf_rd_data	(dmem_rd_data			),
		.i_dmem_intf_byte_sel	(i_mem_ctrl_byte_sel	),
		.i_dmem_intf_func3		(i_mem_funct3			),
		.o_dmem_intf_addr		(dmem_addr				),
		.o_dmem_intf_wr_en		(dmem_mem_write			),
		.o_dmem_intf_wr_data	(dmem_wr_data			),
		.o_dmem_intf_byte_sel	(dmem_byte_sel			),
		.o_dmem_intf_rd_data	(o_mem_read_data		)
	);

	riscv_dmem
	u_riscv_dmem(
		.i_clk				(i_clk							),
		.i_dmem_wr_en		(dmem_mem_write					),
		.i_dmem_byte_sel	(dmem_byte_sel					),
		.i_dmem_addr		(dmem_addr[`DMEM_ADDR_BIT-1:2]	),
		.i_dmem_data		(dmem_wr_data					),
		.o_dmem_data		(dmem_rd_data					)
	);

	riscv_mux
	#(
		.N_MUX_IN			(4					)
	)
	u_riscv_mux_rd(
		.i_mux_sel			(i_mem_ctrl_result_src	),
		.i_mux_concat_data	(mux_concat_src_result	),
		.o_mux_data			(o_mem_rd_result		)
	);

endmodule
