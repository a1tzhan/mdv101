module bitty(
    input wire run,                 // Activate Bitty (high to enable)
    input wire clk,
    input wire reset,               // Active-low reset
    input wire [15:0] d_instr,      // Instruction input
    output wire [15:0] d_out,       // ALU output
    output wire done,               // High when instruction is executed

    // UART communication ports (if handled within Bitty)
    input [7:0]  rx_data,
    input        rx_done,
    input        tx_done,
    output       tx_en,
    output[7:0]  tx_data
);

    wire [15:0] alu_out;
    wire [15:0] in_a;
    wire [15:0] mux_out;
    wire [3:0] cu_to_mux;
    wire [2:0] cu_to_alu_sel;
    wire [15:0] d_out_instruction;
    wire [15:0] reg_c_to_regs;
    wire [15:0] immediate;
    wire en_s, en_c, en_0, en_1, en_2, en_3, en_4, en_5, en_6, en_7, en_i, ls_done, sel_to_reg_c;
    wire [15:0] reg_0;
    wire [15:0] reg_1;
    wire [15:0] reg_2;
    wire [15:0] reg_3;
    wire [15:0] reg_4;
    wire [15:0] reg_5;
    wire [15:0] reg_6;
    wire [15:0] reg_7;
    wire [15:0] data_to_load;
    wire [1:0] en_ls;
    wire [15:0] mux2_out;

    register reg_inst( .clk(clk), .reset(reset), .en(en_i), .d_in(d_instr), .d_out(d_out_instruction));
    
    register reg0( .clk(clk), .reset(reset), .en(en_0), .d_in(mux2_out), .d_out(reg_0));
    register reg1( .clk(clk), .reset(reset), .en(en_1), .d_in(mux2_out), .d_out(reg_1));
    register reg2( .clk(clk), .reset(reset), .en(en_2), .d_in(mux2_out), .d_out(reg_2));
    register reg3( .clk(clk), .reset(reset), .en(en_3), .d_in(mux2_out), .d_out(reg_3));
    register reg4( .clk(clk), .reset(reset), .en(en_4), .d_in(mux2_out), .d_out(reg_4));
    register reg5( .clk(clk), .reset(reset), .en(en_5), .d_in(mux2_out), .d_out(reg_5));
    register reg6( .clk(clk), .reset(reset), .en(en_6), .d_in(mux2_out), .d_out(reg_6));
    register reg7( .clk(clk), .reset(reset), .en(en_7), .d_in(mux2_out), .d_out(reg_7));

    control_unit Control_unit(.run(run), 
                      .reset(reset), 
                      .clk(clk), 
                      .instruction(d_out_instruction), 
                      .alu_sel(cu_to_alu_sel), 
                      .mux_sel(cu_to_mux), 
                      .imm(immediate),
                      .en_ls(en_ls),
                      .ls_done(ls_done),
                      .sel_to_reg_c(sel_to_reg_c),
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

lsu LoadStoreUnit(.clk(clk), 
                  .reset(reset), 
                  .done_out(ls_done), 
                  .en_ls(en_ls), 

                  .address(mux_out[7:0]),
                  .data_to_store(in_a),
                  .data_to_load(data_to_load),

                  .rx_do(rx_done),
                  .rx_data(rx_data),
                  .tx_done(tx_done),
                  .tx_start_out(tx_en),
                  .tx_data_out(tx_data)
                  );

mux2to1 to_reg_c(.reg0(reg_c_to_regs), .reg1(data_to_load), .sel(sel_to_reg_c), .out(mux2_out));

mux Multiplexor(.reg_0(reg_0), .reg_1(reg_1), .reg_2(reg_2), .reg_3(reg_3), .reg_4(reg_4), .reg_5(reg_5), .reg_6(reg_6), .reg_7(reg_7), .imm(immediate), .sel(cu_to_mux), .out(mux_out));

register reg_s(.clk(clk), .reset(reset), .en(en_s), .d_in(mux_out), .d_out(in_a));

alu ALU( 
    .in_a(in_a), 
    .in_b(mux_out), 
    .select(cu_to_alu_sel),
    .alu_out(alu_out));

assign d_out = reg_c_to_regs;

register reg_c(.clk(clk), .reset(reset), .en(en_c), .d_in(alu_out), .d_out(reg_c_to_regs));

endmodule