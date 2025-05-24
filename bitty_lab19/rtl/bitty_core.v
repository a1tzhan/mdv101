module bitty_core(
    input wire clk,
    input wire reset,
    input wire run,
    input wire [15:0] instruction, 
    input wire [15:0] value,
    output wire done,
    output wire [15:0] value_to_memory,
    output wire [15:0] last_alu_result,
    output wire we
);

    wire [15:0] alu_out;
    wire [15:0] in_a;
    wire [15:0] mux_out;
    wire [3:0] cu_to_mux;
    wire [2:0] cu_to_alu_sel;
    wire [15:0] d_out_instruction;
    wire [15:0] reg_c_to_regs;
    wire [15:0] immediate;
    wire en_s, en_c, en_0, en_1, en_2, en_3, en_4, en_5, en_6, en_7, en_i;
    wire [15:0] reg_0;
    wire [15:0] reg_1;
    wire [15:0] reg_2;
    wire [15:0] reg_3;
    wire [15:0] reg_4;
    wire [15:0] reg_5;
    wire [15:0] reg_6;
    wire [15:0] reg_7;
    wire [15:0] regs_input;

    register reg_inst( .clk(clk), .reset(reset), .en(en_i), .d_in(instruction), .d_out(d_out_instruction));
    
    register reg0( .clk(clk), .reset(reset), .en(en_0), .d_in(regs_input), .d_out(reg_0));
    register reg1( .clk(clk), .reset(reset), .en(en_1), .d_in(regs_input), .d_out(reg_1));
    register reg2( .clk(clk), .reset(reset), .en(en_2), .d_in(regs_input), .d_out(reg_2));
    register reg3( .clk(clk), .reset(reset), .en(en_3), .d_in(regs_input), .d_out(reg_3));
    register reg4( .clk(clk), .reset(reset), .en(en_4), .d_in(regs_input), .d_out(reg_4));
    register reg5( .clk(clk), .reset(reset), .en(en_5), .d_in(regs_input), .d_out(reg_5));
    register reg6( .clk(clk), .reset(reset), .en(en_6), .d_in(regs_input), .d_out(reg_6));
    register reg7( .clk(clk), .reset(reset), .en(en_7), .d_in(regs_input), .d_out(reg_7));

    control_unit Control_unit(.run(run), 
                      .reset(reset), 
                      .clk(clk), 
                      .instruction(d_out_instruction), 
                      .alu_sel(cu_to_alu_sel), 
                      .mux_sel(cu_to_mux), 
                      .imm(immediate),
                      .en_s(en_s),
                      .en_c(en_c),
                      .en_0(en_0),
                      .en_1(en_1),
                      .en_2(en_2),
                      .en_3(en_3),
                      .en_4(en_4),
                      .en_5(en_5),
                      .en_6(en_6),
                      .en_7(en_7),
                      .en_i(en_i),
                      .done(done)
                    );

mux Multiplexor(.reg_0(reg_0), .reg_1(reg_1), .reg_2(reg_2), .reg_3(reg_3), .reg_4(reg_4), .reg_5(reg_5), .reg_6(reg_6), .reg_7(reg_7), .imm(immediate), .sel(cu_to_mux), .out(mux_out));

register reg_s(.clk(clk), .reset(reset), .en(en_s), .d_in(mux_out), .d_out(in_a));

alu ALU( 
    .in_a(in_a), 
    .in_b(mux_out), 
    .select(cu_to_alu_sel),
    .alu_out(alu_out));

assign last_alu_result = reg_c_to_regs;

core_memory_access_logic Memory_access_core(.instruction(d_out_instruction), .memory_value(value), .alu_value(reg_c_to_regs), .reg_s_to_alu(in_a), .value_to_regs(regs_input), .value_to_memory(value_to_memory), .we(we));

register reg_c(.clk(clk), .reset(reset), .en(en_c), .d_in(alu_out), .d_out(reg_c_to_regs));

monitor Monitor(.clk(clk), .done(done), .instruction(d_out_instruction), .reg_0(reg_0), .reg_1(reg_1), .reg_2(reg_2), .reg_3(reg_3), .reg_4(reg_4), .reg_5(reg_5), .reg_6(reg_6), .reg_7(reg_7));

endmodule