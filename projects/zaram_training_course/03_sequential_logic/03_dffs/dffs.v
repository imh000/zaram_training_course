module dff_sync
(
	input clk, 
	input d,
	input rstn,
	output reg q
);
	always @ (posedge clk) begin
		if(!rstn)
			q <= 0;
		else
			q <= d;
	end
	endmodule
	
module dff_async
(
	input clk, 
	input d,
	input rstn,
	output reg q
);
	always @ (posedge clk or negedge rstn) begin
		if(!rstn)
			q <= 0;
		else
			q <= d;
	end
	endmodule
