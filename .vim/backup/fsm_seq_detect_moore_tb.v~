`define DEBUG
`define CLKFREQ		100
`define NVEC		50
`define SIMCYCLE	`NVEC

`include "fsm_seq_detect_moore.v"

module fsm_seq_detect_moore_tb();
	reg clk;
	reg rstn;
	reg i_seq;
	wire	 out;

	fsm_seq_detect_moore
	u_fsm_seq_detect_moore(
		.clk				(clk				),
		.rstn				(rstn				),
		.i_seq				(i_seq				),
		.out				(out				)
	);



always #(500/`CLKFREQ) clk = ~clk;

reg [8*32-1:0] taskState;
integer err = 0;

task init;
	begin
		taskState = "Init";
		clk = 0;
		rstn = 0;
		i_seq = 0;
	end
endtask

task resetNCycle;
	input [9:0] i;
	begin
		taskState = "Reset On";
		rstn = 0;
		#(i*1000/`CLKFREQ);
		rstn = 1;
		taskState = "Reset off";
	end
endtask

	integer		i, j;
	initial begin
		init();
		resetNCycle(4);
		for (i=0; i<`SIMCYCLE; i++) begin
			i_seq = $urandom;
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
			$dumpfile("fsm_seq_detect_moore.vcd");
			$dumpvars;
		end
	end

endmodule
