// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		100		// # of Test Vector
`define IMEM_INIT
`define IMEM_INIT_FILE	"/home/limh/projects/verilog_tutorials/RV32I/core/singlecycle/riscv_program.mif"
`define NOINC
`define DEBUG

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include "../common/riscv_configs.v"
`include "../common/riscv_adder.v"
`include "../common/riscv_alu.v"
`include "../common/riscv_dmem.v"
`include "../common/riscv_dmem_interface.v"
`include "../common/riscv_imem.v"
`include "../common/riscv_immdecode.v"
`include "../common/riscv_register.v"
`include "../common/riscv_register_file.v"
`include "../common/riscv_mux.v"
`include "riscv_cpu.v"
`include "riscv_ctrl.v"
`include "riscv_datapath.v"
`include "riscv_top.v"

module riscv_top_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg i_clk;
	reg i_rstn;
	wire [`XLEN-1:0] o_riscv_imem_pc;
	wire [`XLEN-1:0] o_riscv_imem_instr;
	wire [`XLEN-1:0] o_riscv_dmem_addr;
	wire o_riscv_dmem_wr_en;
	wire [`XLEN-1:0] o_riscv_dmem_wr_data;
	wire [`XLEN-1:0] o_riscv_dmem_rd_data;
	wire [`XLEN/8-1:0] o_riscv_dmem_byte_sel;

	riscv_top
	#(
		.REGISTER_INIT			(0						)
	)
	u_riscv_top(
		.i_clk					(i_clk					),
		.i_rstn					(i_rstn					),
		.o_riscv_imem_pc		(o_riscv_imem_pc		),
		.o_riscv_imem_instr		(o_riscv_imem_instr		),
		.o_riscv_dmem_addr		(o_riscv_dmem_addr		),
		.o_riscv_dmem_wr_en		(o_riscv_dmem_wr_en		),
		.o_riscv_dmem_wr_data	(o_riscv_dmem_wr_data	),
		.o_riscv_dmem_rd_data	(o_riscv_dmem_rd_data	),
		.o_riscv_dmem_byte_sel	(o_riscv_dmem_byte_sel	)
	);

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	integer err = 0;

	task init;
		begin
			taskState = "Init";
			i_clk = 0;
			i_rstn = 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input [9:0] n;
		begin
			taskState = "Reset On";
			i_rstn = 1'b0;
			#(n*1000/`CLKFREQ);
			i_rstn = 1'b1; 
			taskState = "Reset OFF";
		end
	endtask

	always #(500/`CLKFREQ) i_clk = ~i_clk;

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		resetReleaseAfterNCycles(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ);
		end
		#(1000/`CLKFREQ);
		$finish;
	end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
			for(i=0; i<2**(`DMEM_ADDR_BIT-2)-1; i++) begin
				$dumpvars(0, u_riscv_top.u_riscv_dmem.dmem_arr[i]);
			end
			for(i=0; i<32; i++) begin
				$dumpvars(0, u_riscv_top.u_riscv_cpu.u_riscv_datapath.u_riscv_register_file.registers[i]);
			end
		end else begin
			$dumpfile("riscv_top_tb.vcd");
			$dumpvars;
		end
	end

endmodule
