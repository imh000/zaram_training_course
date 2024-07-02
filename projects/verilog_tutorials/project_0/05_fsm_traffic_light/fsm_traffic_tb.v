// // --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		50		// # of Test Vector
`define DEBUG

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"fsm_traffic.v"

module fsm_traffic_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg clk;
	reg rstn;
	reg Ta;
	reg Tb;
	reg P;
	reg R;
	wire [1:0] La;
	wire [1:0] Lb;

	fsm_traffic
	u_fsm_traffic(
		.clk				(clk				),
		.rstn				(rstn				),
		.Ta					(Ta					),
		.Tb					(Tb					),
		.P					(P					),
		.R					(R					),
		.La					(La					),
		.Lb					(Lb					)
	);


// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	integer err = 0;

	task init;
		begin
			taskState = "Init";
			clk = 0;
			rstn = 0;
			P = 0;
			R = 0;
			Ta = 0;
			Tb = 0;
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
			P = $urandom;
			R = $urandom;
			Ta = $urandom;
			Tb = $urandom;
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
			$dumpfile("fsm_traffic_tb.vcd");
			$dumpvars;
		end
	end

endmodule
