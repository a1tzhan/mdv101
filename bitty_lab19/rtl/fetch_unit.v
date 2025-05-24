module fetch_unit(
    input wire clk,
    input wire reset,
    input wire done,
    input wire run,
    input wire we,
    input wire [15:0] last_alu_result,
    input wire [15:0] value_to_memory,
    output wire bitty_core_run,
    output wire [15:0] value_out,
    output wire [15:0] instruction_out
);

    wire [7:0] new_pc;
    reg [15:0] reg_instruction_out;
    reg [15:0] reg_value_out;
    wire [15:0] mem_instruction_out;
    wire [7:0] pc_out;
    wire en_pc;
    assign value_out = reg_value_out;
    assign instruction_out = reg_instruction_out;
    wire [15:0] mem_value_out;

    branch_logic Branch_logic(.run(run), .instruction(mem_instruction_out), .en_pc(en_pc), .last_alu_result(last_alu_result), .pc(pc_out), .done(done), .new_pc(new_pc), .bitty_core_run(bitty_core_run));

    register_pc PC(.clk(clk), .reset(reset), .en(en_pc), .d_in(new_pc), .d_out(pc_out));

    memory Memory(.clk(clk), .we(we), .address(pc_out), .value_in(value_to_memory), .instruction(mem_instruction_out), .value_out(mem_value_out));

    always @(*)begin
            if(reset) begin
                reg_instruction_out = 0;
                reg_value_out = 0;
            end
            else begin
                reg_instruction_out = mem_instruction_out;
                reg_value_out = mem_value_out;
            end
        end
endmodule