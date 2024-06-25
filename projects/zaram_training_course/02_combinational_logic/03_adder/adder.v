//`define DF_DATA		8	
module adder_param
#(
	parameter BW_DATA = 8
)
(
	output   [BW_DATA-1:0]   sum,
	output                   cout,
	input    [BW_DATA-1:0]   i_a,
	input    [BW_DATA-1:0]   i_b,
	input                    cin
);

	assign {cout, sum} = i_a + i_b + cin;

endmodule

module adder_def
(
	output   [`DF_DATA-1:0]   sum,
	output                    cout,
	input    [`DF_DATA-1:0]   i_a,
	input    [`DF_DATA-1:0]   i_b,
	input                     cin
);

	assign {cout, sum} = i_a + i_b + cin;

endmodule
