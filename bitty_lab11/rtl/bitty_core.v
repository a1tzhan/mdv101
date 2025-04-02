module bitty_core(
    input wire reset,
    input wire clk,
    input wire [15:0] instruction, 
    input wire run,
    input wire [15:0] reg_00,
    input wire [15:0] reg_01,
    input wire [15:0] reg_02,
    input wire [15:0] reg_03,
    input wire [15:0] reg_04,
    input wire [15:0] reg_05,
    input wire [15:0] reg_06,
    input wire [15:0] reg_07,
    output wire done,
    output wire [15:0] reg_0,
    output wire [15:0] reg_1,
    output wire [15:0] reg_2,
    output wire [15:0] reg_3,
    output wire [15:0] reg_4,
    output wire [15:0] reg_5,
    output wire [15:0] reg_6,
    output wire [15:0] reg_7
);
    wire [15:0] alu_out;
    wire [15:0] in_a;
    wire [15:0] mux_out;
    wire [2:0] mux_sel;
    wire [3:0] alu_sel;
    wire [15:0] d_out_instruction;
    wire [15:0] reg_c_to_regs;

    wire en_s, en_c, en_0, en_1, en_2, en_3, en_4, en_5, en_6, en_7, en_i, alu_mode;

    register reg_inst( .clk(clk), .reset(reset), .en(en_i), .d_in(instruction), .d_out(d_out_instruction));
    
    register reg0( .clk(clk), .reset(reset), .en(en_0), .d_in(reg_c_to_regs), .d_out(reg_0));
    register reg1( .clk(clk), .reset(reset), .en(en_1), .d_in(reg_c_to_regs), .d_out(reg_1));
    register reg2( .clk(clk), .reset(reset), .en(en_2), .d_in(reg_c_to_regs), .d_out(reg_2));
    register reg3( .clk(clk), .reset(reset), .en(en_3), .d_in(reg_c_to_regs), .d_out(reg_3));
    register reg4( .clk(clk), .reset(reset), .en(en_4), .d_in(reg_c_to_regs), .d_out(reg_4));
    register reg5( .clk(clk), .reset(reset), .en(en_5), .d_in(reg_c_to_regs), .d_out(reg_5));
    register reg6( .clk(clk), .reset(reset), .en(en_6), .d_in(reg_c_to_regs), .d_out(reg_6));
    register reg7( .clk(clk), .reset(reset), .en(en_7), .d_in(reg_c_to_regs), .d_out(reg_7));

    control_unit cu01(.run(run), 
    .reset(reset), 
    .clk(clk), 
    .instruction(d_out_instruction), 
    .alu_sel(alu_sel), 
    .mux_sel(mux_sel), 
    .alu_mode(alu_mode),
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

mux mux01(.reg_0(reg_00), .reg_1(reg_01), .reg_2(reg_02), .reg_3(reg_03), .reg_4(reg_04), .reg_5(reg_05), .reg_6(reg_06), .reg_7(reg_07), .sel(mux_sel), .out(mux_out));

register reg_s(.clk(clk), .reset(reset), .en(en_s), .d_in(mux_out), .d_out(in_a));

    alu alu01( 
    .in_a(in_a), 
    .in_b(mux_out), 
    .select(alu_sel), 
    .mode(alu_mode),  
    .alu_out(alu_out));

    register reg_c(.clk(clk), .reset(reset), .en(en_c), .d_in(alu_out), .d_out(reg_c_to_regs));

endmodule