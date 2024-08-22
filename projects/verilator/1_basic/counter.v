module counter
#(
	parameter num = 15
)
(
	input clk,
	input rstn,
	output reg [$clog2(num + 1)-1:0] o_cnt
);
	always @ (posedge clk or negedge rstn) begin
		if(!rstn)
			o_cnt <= 0;
		else
			o_cnt <= o_cnt + 1;
	end
endmodule

