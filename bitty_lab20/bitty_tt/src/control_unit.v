module control_unit(
    input wire run,
    input wire reset,
    input wire clk,
    input wire ls_done,
    input wire [15:0] instruction,
    output wire [2:0] alu_sel,
    output wire [3:0] mux_sel,
    output wire [15:0] imm,
    output wire [1:0] en_ls,
    output wire sel_to_reg_c,
    output wire en_s,
    output wire en_c,
    output wire en_0,
    output wire en_1,
    output wire en_2,
    output wire en_3,
    output wire en_4,
    output wire en_5,
    output wire en_6,
    output wire en_7,
    output wire en_i,
    output wire done
);
    // State encoding
    parameter S0 = 2'b00;
    parameter S1 = 2'b01;
    parameter S2 = 2'b10;

    reg [1:0] reg_en_ls;
    reg [15:0] reg_imm;
    reg [1:0] current_state, next_state;
    reg [2:0] reg_alu_sel; 
    reg [3:0] reg_mux_sel; 
    reg reg_sel_reg_c, reg_en_c, reg_en_0, reg_en_1, reg_en_2, reg_en_3, reg_en_4, reg_en_5, reg_en_6, reg_en_7, reg_en_i, reg_en_s, reg_done;

    assign sel_to_reg_c = reg_sel_reg_c;
    assign en_ls = reg_en_ls;
    assign en_c    = reg_en_c;
    assign en_0    = reg_en_0;
    assign en_1    = reg_en_1;
    assign en_2    = reg_en_2;
    assign en_3    = reg_en_3;
    assign en_4    = reg_en_4;
    assign en_5    = reg_en_5;
    assign en_6    = reg_en_6;
    assign en_7    = reg_en_7;
    assign en_i    = reg_en_i;
    assign en_s    = reg_en_s;
    assign alu_sel = reg_alu_sel;
    assign mux_sel = reg_mux_sel;
    assign done    = reg_done;
    assign imm     = reg_imm;

    // Model state register (sequential logic)
    always @(posedge clk) begin
        if (!reset) begin
            current_state <= S0;
        end else begin
            current_state <= next_state;
        end
    end

    always @(*) begin

        reg_en_s = 1'b0;
        reg_en_c = 1'b0;
        reg_en_0 = 1'b0;
        reg_en_1 = 1'b0;
        reg_en_2 = 1'b0;
        reg_en_3 = 1'b0;
        reg_en_4 = 1'b0;
        reg_en_5 = 1'b0;
        reg_en_6 = 1'b0;
        reg_en_7 = 1'b0;
        reg_en_i = 1'b1;
        reg_done = 1'b0;
        reg_alu_sel = 3'b000;
        reg_mux_sel = 4'b0000;
        reg_sel_reg_c = 1'b0;
        reg_en_ls = 2'b00;
        reg_imm = {8'h00, instruction[12:5]};

        case (current_state)
            S0: begin
                if(instruction[1:0]!=2'b10) begin
                    reg_mux_sel = {1'b0, instruction[15:13]};
                    reg_en_s = 1;
                end else begin
                reg_alu_sel = 3'b0;
                reg_mux_sel = 4'b1001;
                end
                reg_done = 0;
                reg_en_i = 1'b1;
                reg_sel_reg_c = 1'b0;
            end
            S1: begin
                if(instruction[1:0] != 2'b10) begin 
                    if (instruction[1:0] == 2'b01) begin
                        reg_imm = {8'h00, instruction[12:5]};
                        reg_mux_sel = 4'h8;
                    end
                    else if(instruction[1:0] == 2'b00) begin
                        reg_mux_sel = {1'b0, instruction[12:10]};
                    end
                    else if(instruction[1:0] == 2'b11) begin
                        reg_mux_sel = {1'b0, instruction[12:10]};
                        reg_en_ls = (instruction[2] == 0) ? 2'b01 : 2'b10;
                        reg_sel_reg_c = 1'b1;
                end
                reg_alu_sel = instruction[4:2];
                end else begin
                    reg_alu_sel = 3'b000;
                    reg_mux_sel = 4'b1001;
                end
                reg_en_c = 1;
                reg_done = 0;
                reg_en_i = 0;
            end
            S2: begin
                if(instruction[1:0] == 2'b11) reg_sel_reg_c = 1'b1;
                if(~(instruction[1:0] == 2'b11 && instruction[2] == 1'b1)) begin
                    if(~(instruction[1:0] == 2'b10)) begin
                    case(instruction[15:13])
                        3'b000: reg_en_0 = 1'b1;
                        3'b001: reg_en_1 = 1'b1;
                        3'b010: reg_en_2 = 1'b1;
                        3'b011: reg_en_3 = 1'b1;
                        3'b100: reg_en_4 = 1'b1;
                        3'b101: reg_en_5 = 1'b1;
                        3'b110: reg_en_6 = 1'b1;
                        3'b111: reg_en_7 = 1'b1;
                    endcase
                    end
                end
                reg_done = 1;
                reg_en_i = 1'b1;
            end
            default: begin
                reg_en_s = 1'b0;
                reg_en_c = 1'b0;
                reg_en_0 = 1'b0;
                reg_en_1 = 1'b0;
                reg_en_2 = 1'b0;
                reg_en_3 = 1'b0;
                reg_en_4 = 1'b0;
                reg_en_5 = 1'b0;
                reg_en_6 = 1'b0;
                reg_en_7 = 1'b0;
                reg_done = 1'b0;
                reg_alu_sel = 3'b000;
                reg_mux_sel = 4'b1001;
                reg_en_ls = 2'b00;
                reg_imm = 16'h0000; 
            end
        endcase
        end

    // Model next state decode logic (combinational logic)
    always @(*) begin
        case (current_state)
            S0: begin
                if(run==1) begin
                    if(instruction[1:0]==2'b10) begin
                        next_state = S2;
                    end
                    else begin
                        next_state = S1;
                    end
                end
                else begin
                    next_state = S0;
                end
            end
            S1: begin
                if(instruction[1:0] == 2'b11) begin
                    next_state = (ls_done==1) ? S2 : S1;
                    //$display(ls_done);
                end
                else begin
                    next_state = (en_c==1) ? S2 : S1;
                end
            end
            S2: next_state = (done == 1) ? S0 : S2;
            default: next_state = S0;
        endcase
        end
endmodule