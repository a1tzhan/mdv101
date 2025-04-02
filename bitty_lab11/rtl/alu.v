module alu (
	input wire [15:0] in_a,
	input wire [15:0] in_b, 
	input wire [3:0] select,
	input wire mode,
	output wire [15:0] alu_out);

	alu_temp alu1(in_a, in_b, select, mode, alu_out);

endmodule
