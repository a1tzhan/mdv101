module top_module(
    input wire clk,
    input wire run,
    input wire reset
);
wire done;
wire [15:0] last_alu_result;
wire bitty_core_run;
wire [15:0] instruction;

fetch_unit fetch1 (.clk(clk), .reset(reset), .done(done), .last_alu_result(last_alu_result), .run(run), .bitty_core_run(bitty_core_run), .out(instruction));

bitty_core bitty1 (.reset(reset), .clk(clk), .instruction(instruction), .run(bitty_core_run), .last_alu_result(last_alu_result), .done(done));

endmodule