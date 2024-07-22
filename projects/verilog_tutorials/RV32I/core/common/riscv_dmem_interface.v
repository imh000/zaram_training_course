`ifndef	NOINC
`include "riscv_configs.v"
`endif

module riscv_dmem_interface
(
	//FROM CPU
	input [`XLEN-1:0] i_dmem_intf_wr_data,
	input [`XLEN/8-1:0] i_dmem_intf_byte_sel,
	//From Memory
	input [`XLEN-1:0] i_dmem_intf_rd_data,
	// Control & clock
	input [2:0] i_dmem_intf_func3,
	input i_clk,
	//Bypass signal
	input [`XLEN-1:0] i_dmem_intf_addr,
	input i_dmem_intf_wen,
	output [`XLEN-1:0] o_dmem_intf_addr,
	output o_dmem_intf_wen,
	//To data Memory
	output [`XLEN-1:0] o_dmem_intf_wr_data,
	output [`XLEN/8-1:0] o_dmem_intf_byte_sel,
	//TO CPU
	output reg [`XLEN-1:0] o_dmem_intf_rd_data
);

	// Bypass signal
	assign o_dmem_intf_addr = i_dmem_intf_addr;
	assign o_dmem_intf_wen = i_dmem_intf_wen;

	// To Data Memory
	assign o_dmem_intf_wr_data
endmodule
