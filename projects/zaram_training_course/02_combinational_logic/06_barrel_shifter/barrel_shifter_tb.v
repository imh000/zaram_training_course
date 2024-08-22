
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
`include "barrel_shifter.v"

module barrel_shifter_tb();
	parameter bit_size = 8;
	reg [bit_size-1:0] data;
	reg [$clog2(bit_size)-1:0] num_shift; 	// number to shift
	reg direction; 		// 0: left, 1:right
	reg [1:0] sel;		// 0: logical shift, 1:arithmetic shift, 2:rotate
	wire	 [bit_size-1:0] out;
	wire	 overflow;			//logical and arithmetic overflow;

	barrel_shifter
	#(
		.bit_size			(bit_size			)
	)
	u_barrel_shifter(
		.data				(data				),
		.num_shift			(num_shift			),
		.direction			(direction			),
		.sel				(sel				),
		.out				(out				),
		.overflow			(overflow			)
	);


// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg [8*32-1:0] taskState;
	integer err = 0;

	task init;
		begin
//			taskState = "Init";
			data	= 0;
			num_shift = 0;
			direction = 0;
			sel =0;

		end
	endtask
/*
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
*/

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
//		resetReleaseAfterNCycles(4);

		for (i=0; i<`SIMCYCLE; i++) begin
			data = $urandom;
			num_shift = $urandom;
			direction = $urandom;
			sel = $urandom;
		#(1000/`CLKFREQ);
		end
		$finish;
	end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------

	reg [8*32-1:0]  vcd_file;
    initial begin
        if ($value$plusargs("vcd_file=%s", vcd_file)) begin
            $dumpfile(vcd_file);
            $dumpvars;
        end
    end
endmodule
