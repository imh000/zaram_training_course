
`define CLKFREQ		100
`define SIMCYCLE	50

`include "cnt.v"

module cnt_tb();
	parameter num = 15;
	reg clk;
	reg rstn;
	reg mode; 
	wire	 [$clog2(num + 1)-1:0] o_cnt;

	cnt
	#(
		.num				(num				)
	)
	u_cnt(
		.clk				(clk				),
		.rstn				(rstn				),
		.mode				(mode				),
		.o_cnt				(o_cnt				)
	);


always #(500/`CLKFREQ) clk = ~clk;
reg [8*32-1:0] taskState;
integer err = 0;

task init;
	begin
		taskState = "Init";
		clk = 0;
		rstn = 0;
		mode = 0;
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
			mode = $urandom;
			#(2000/`CLKFREQ);
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
			$dumpfile("cnt.vcd");
			$dumpvars;
		end
	end

endmodule

