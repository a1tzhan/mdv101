module top_module(
    input wire clk,
    input wire run,
    input wire reset
);
wire done;
wire [15:0] last_alu_result;
wire bitty_core_run;
wire [15:0] instruction;
wire [15:0] value_to_core;
wire [15:0] value_to_mem;
wire we;
fetch_unit fetch1 (.clk(clk), 
                   .reset(reset), 
                   .done(done), 
                   .last_alu_result(last_alu_result), 
                   .run(run), 
                   .we(we),
                   .bitty_core_run(bitty_core_run), 
                   .instruction_out(instruction), 
                   .value_out(value_to_core),
                   .value_to_memory(value_to_mem));

bitty_core bitty1 (.clk(clk), 
                   .reset(reset),
                   .done(done),
                   .last_alu_result(last_alu_result), 
                   .run(bitty_core_run),
                   .we(we),
                   .instruction(instruction), 
                   .value(value_to_core), 
                   .value_to_memory(value_to_mem));

endmodule