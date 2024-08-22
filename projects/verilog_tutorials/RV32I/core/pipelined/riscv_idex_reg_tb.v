// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		10		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"riscv_IDEX_register.v"

module riscv_IDEX_register_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg		i_clk;
	reg		i_FlushE;
	reg		[`XLEN-1:0] i_ID_rs1_data;
	reg		[`XLEN-1:0] i_ID_rs2_data;
	reg		[`XLEN-1:0] i_ID_pc_data;
	reg		[4:0] i_ID_rs1_addr;
	reg		[4:0] i_ID_rs2_addr;
	reg		[4:0] i_ID_rd_addr;
	reg		[`XLEN-1:0] i_ID_imm;
	reg		[`XLEN-1:0] i_ID_pc_plus_4_data;
	wire	[`XLEN-1:0] o_EX_rs1_data;
	wire	[`XLEN-1:0] o_EX_rs2_data;
	wire	[`XLEN-1:0] o_EX_pc_data;
	wire	[4:0] o_EX_rs1_addr;
	wire	[4:0] o_EX_rs2_addr;
	wire	[4:0] o_EX_rd_addr;
	wire	[`XLEN-1:0] o_EX_imm;
	wire	[`XLEN-1:0] o_EX_pc_plus_4_data;

	riscv_IDEX_register
	u_riscv_IDEX_register(
		.i_clk				(i_clk				),
		.i_FlushE			(i_FlushE			),
		.i_ID_rs1_data		(i_ID_rs1_data		),
		.i_ID_rs2_data		(i_ID_rs2_data		),
		.i_ID_pc_data		(i_ID_pc_data		),
		.i_ID_rs1_addr		(i_ID_rs1_addr		),
		.i_ID_rs2_addr		(i_ID_rs2_addr		),
		.i_ID_rd_addr		(i_ID_rd_addr		),
		.i_ID_imm			(i_ID_imm			),
		.i_ID_pc_plus_4_data(i_ID_pc_plus_4_data),
		.o_EX_rs1_data		(o_EX_rs1_data		),
		.o_EX_rs2_data		(o_EX_rs2_data		),
		.o_EX_pc_data		(o_EX_pc_data		),
		.o_EX_rs1_addr		(o_EX_rs1_addr		),
		.o_EX_rs2_addr		(o_EX_rs2_addr		),
		.o_EX_rd_addr		(o_EX_rd_addr		),
		.o_EX_imm			(o_EX_imm			),
		.o_EX_pc_plus_4_data(o_EX_pc_plus_4_data)
	);
// --------------------------------------------------
//	Clock
// --------------------------------------------------
	always	#(500/`CLKFREQ)		i_clk = ~i_clk;

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg		[4*32-1:0]	taskState;
	integer				err	= 0;

	task init;
		begin
			taskState		= "Init";
			i_clk				= 0;
			i_FlushE			= 0;
			i_ID_rs1_data		= 0;
			i_ID_rs2_data		= 0;
			i_ID_pc_data		= 0;
			i_ID_rs1_addr		= 0;
			i_ID_rs2_addr		= 0;
			i_ID_rd_addr		= 0;
			i_ID_imm			= 0;
			i_ID_pc_plus_4_data	= 0;
		end
	endtask


//	task resetReleaseAfterNCycles;
//		input [9:0] n;
//		begin
//			taskState = "enable OFF";
//			i_FlushE = 1'b0;
//			#(n*1000/`CLKFREQ);
//			i_FlushE = 1'b1; 
//			taskState = "enable On";
//			#(n*1000/`CLKFREQ);
//			i_FlushE = 1'b0;
//			taskState = "enable OFF";
//		end
//	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		//resetReleaseAfterNCycles(10);

		for (i=0; i<`SIMCYCLE; i++) begin
			i_ID_rs1_data = $urandom;
			i_ID_rs2_data = $urandom;
			i_ID_pc_data = $urandom;
			i_ID_rs1_addr = $urandom;
			i_ID_rs2_addr = $urandom;
			i_ID_rd_addr = $urandom;
			i_ID_imm = $urandom;
			i_ID_pc_plus_4_data = $urandom;
			i_FlushE = $urandom;
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
			$dumpfile("riscv_IDEX_register_tb.vcd");
			$dumpvars;
		end
	end

endmodule
