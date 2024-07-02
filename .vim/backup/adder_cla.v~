module adder_cla
(
	input  [31:0] a,
	input  [31:0] b,
	input         cin,
	output        cout,
	output [31:0] sum
);

	wire [6:0] co;

	adder_cla_4bit
	u_adder_cla_4bit0(
		.a					(a[3:0]				),
		.b					(b[3:0]				),
		.cin				(cin				),
		.cout				(co[0]				),
		.sum				(sum[3:0]			)
	);

	genvar i;
	generate
		for(i=1; i<7; i=i+1) begin : adder_cla_loop
			adder_cla_4bit
			u_adder_cla_4bit(
				.a					(a[4*i+3:4*i]		),
				.b					(b[4*i+3:4*i]		),
				.cin				(co[i-1]			),
				.cout				(co[i]				),
				.sum				(sum[4*i+3:4*i]		)
			);
		end
	endgenerate

	adder_cla_4bit
	u_adder_cla_4bit7(
		.a					(a[31:28]			),
		.b					(b[31:28]			),
		.cin				(co[6]				),
		.cout				(cout				),
		.sum				(sum[31:28]			)
	);


endmodule
	
module adder_cla_4bit
(
	input  [3:0] a,
	input  [3:0] b,
	input        cin,
	output       cout,
	output [3:0] sum
);

	wire [3:0] P, G, C;

	// bitwise PG Logic
	assign P = a ^ b;
	assign G = a & b;

	// Group PG Logic
	assign C[0] = cin;
	assign C[1] = G[0] | (P[0] & C[0]);
	assign C[2] = G[1] | (P[1] & C[1]);
	assign C[3] = G[2] | (P[2] & C[2]);

	// Sum LogiC
	assign cout = G[3] | (P[3] & C[3]);
	assign sum = P ^ C;

endmodule

