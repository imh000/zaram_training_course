// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		50		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"riscv_register.v"

module riscv_register_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	
	parameter REGISTER_INIT = `XLEN'h0A0A0A0A;

	reg				   i_clk;
	reg				   i_rstn;
	reg				   i_register_en  ;
	reg	   [`XLEN-1:0] i_register_d   ;
	wire	 [`XLEN-1:0] o_register_q;

	riscv_register
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_register(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_register_en		(i_register_en		),
		.i_register_d		(i_register_d		),
		.o_register_q		(o_register_q		)
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
			i_register_en = 0;
			i_register_d = 0;
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
			i_register_en = 1;
			i_register_d = $urandom;
			#(1000/`CLKFREQ);
			i_register_en = 0;
			i_register_d = $urandom;
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
			$dumpfile("riscv_register_tb.vcd");
			$dumpvars;
		end
	end

endmodule
