// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		10		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"signed_adder.v"

module signed_adder_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	reg signed [3:0] a;
	reg signed		 [3:0] b;
	reg			   cin;
	wire signed [5:0] sum;

	signed_adder
	u_signed_adder(
		.a					(a					),
		.b					(b					),
		.cin				(cin				),
		.sum				(sum				)
	);

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	task init;
		begin
			a = 0;
			b = 0;
			cin = 0;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();

		for (i=0; i<`SIMCYCLE; i++) begin
			a = $random;
			b = $random;
			cin = $random;
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
			$dumpfile("signed_adder_tb.vcd");
			$dumpvars;
		end
	end

endmodule
