// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		50		// # of Test Vector
`define NOINC

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"../common/riscv_configs.v"
`include	"riscv_ifid_reg.v"

module riscv_ifid_reg_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg i_clk;
	reg i_rstn;
	reg i_stallD;
	reg i_flushD;
	reg [`XLEN-1:0] i_if_instr;
	reg [`XLEN-1:0] i_if_pc;
	reg [`XLEN-1:0] i_if_pc_plus_4;
	wire	 [`XLEN-1:0] o_id_instr;
	wire	 [`XLEN-1:0] o_id_pc;
	wire	 [`XLEN-1:0] o_id_pc_plus_4;

	riscv_ifid_reg
	u_riscv_ifid_reg(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_stallD			(i_stallD			),
		.i_flushD			(i_flushD			),
		.i_if_instr			(i_if_instr			),
		.i_if_pc			(i_if_pc			),
		.i_if_pc_plus_4		(i_if_pc_plus_4		),
		.o_id_instr			(o_id_instr			),
		.o_id_pc			(o_id_pc			),
		.o_id_pc_plus_4		(o_id_pc_plus_4		)
	);


// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	integer err = 0;

	task init;
		begin
			taskState = "Init";
			i_clk			= 0;
			i_rstn			= 0;
			i_stallD		= 0;
			i_flushD		= 0;
			i_if_instr		= 0;
			i_if_pc			= 0;
			i_if_pc_plus_4	= 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input [9:0] n;
		begin
			taskState = "Reset On";
			i_rstn = 1'b0;
			#(1000/`CLKFREQ);
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
			i_stallD = $urandom;
			i_flushD = $urandom;
			i_if_instr = $urandom;
			i_if_pc = $urandom;
			i_if_pc_plus_4 = $urandom;
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
		end else begin
			$dumpfile("riscv_ifid_reg_tb.vcd");
			$dumpvars;
		end
	end

endmodule
