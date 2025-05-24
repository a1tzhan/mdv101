module fetch_unit(
    input wire clk,
    input wire reset,
    input wire done,
    input wire run,
    input wire [15:0] last_alu_result,
    output wire bitty_core_run,
    output wire [15:0] out
);

    wire [7:0] new_pc;
    reg [15:0] reg_out;
    wire [15:0] mem_out;
    wire [7:0] pc_out;
    wire en_pc;
    assign out = reg_out;

    branch_logic bl(.run(run), .instruction(mem_out), .en_pc(en_pc), .last_alu_result(last_alu_result), .pc(pc_out), .done(done), .new_pc(new_pc), .bitty_core_run(bitty_core_run));

    register_pc pc01(.clk(clk), .reset(reset), .en(en_pc), .d_in(new_pc), .d_out(pc_out));

    memory memory01(.addr(pc_out), .out(mem_out));

    always @(*)begin
            if(reset) reg_out = 0;
            else reg_out = mem_out;
        end
endmodule