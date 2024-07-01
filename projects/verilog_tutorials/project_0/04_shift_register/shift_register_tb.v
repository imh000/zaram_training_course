// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		50		// # of Test Vector

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"shift_register.v"

module shift_register_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	parameter bit_size = 8;

	reg clk;
	reg load;
	reg Sin;
	reg [bit_size-1:0] d;
	wire [bit_size-1:0] q;
	wire Sout;

	shift_register
	#(
		.bit_size			(bit_size			)
	)
	u_shift_register(
		.clk				(clk				),
		.load				(load				),
		.Sin				(Sin				),
		.d					(d					),
		.q					(q					),
		.Sout				(Sout				)
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
			load = 0;
			Sin = 0;
			d = 0;
		end
	endtask

	always #(500/`CLKFREQ) clk = ~clk;

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();

		for (i=0; i<`SIMCYCLE; i++) begin
			load = $urandom;
			Sin  = $urandom;
			d = $urandom;
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
			$dumpfile("shift_register_tb.vcd");
			$dumpvars;
		end
	end

endmodule
