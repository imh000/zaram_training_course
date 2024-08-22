// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		50		// # of Test Vector
`define DEBUG

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"fsm_detect_moore.v"

module fsm_detect_moore_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg clk;
	reg rstn;
	reg in;
	wire out;

	fsm_detect_moore
	u_fsm_detect_moore(
		.clk				(clk				),
		.rstn				(rstn				),
		.in					(in					),
		.out				(out				)
	);

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	reg [8*32-1:0] stateMonitor;

	integer err = 0;

	task init;
		begin
			taskState = "Init";
			clk		= 0;
			rstn	= 0;
			in		= 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input [9:0] n;
		begin
			taskState = "Reset On";
			rstn = 1'b0;
			#(1000/`CLKFREQ);
			rstn = 1'b1; 
			taskState = "Reset OFF";
		end
	endtask


	always #(500/`CLKFREQ) clk = ~clk;

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		resetReleaseAfterNCycles(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			in = $urandom;
			#(1000/`CLKFREQ);
		end
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
			$dumpfile("fsm_detect_moore_tb.vcd");
			$dumpvars;
		end
	end

endmodule
