module control_unit(
    input wire run,
    input wire reset,
    input wire clk,
    input wire [15:0] instruction,
    output wire [2:0] alu_sel,
    output wire [3:0] mux_sel,
    output wire [15:0] imm,
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
    parameter S3 = 2'b11;

    reg [15:0] reg_imm;
    reg [1:0] current_state, next_state;
    reg [2:0] reg_alu_sel; 
    reg [3:0] reg_mux_sel; 
    reg reg_en_c, reg_en_0, reg_en_1, reg_en_2, reg_en_3, reg_en_4, reg_en_5, reg_en_6, reg_en_7, reg_en_i, reg_en_s, reg_done;

    
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
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            current_state <= S0;
        end else if(run) begin
            current_state <= next_state;
        end
    end

    // Model next state decode logic (combinational logic)
    always @(*) begin
        next_state = current_state;
        if(!reset && run) begin
        case (current_state)
            S0: next_state = S1;
            S1: next_state = S2;
            S2: next_state = S3;
            S3: next_state = S0;
            default: next_state = S0;
        endcase
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
        reg_en_i = 1'b0;
        reg_done = 1'b0;
        reg_alu_sel = 3'b000;
        reg_mux_sel = 4'b0000;
        reg_imm = 16'h0000;

        if(!reset && run) begin
        case (current_state)
            S0: reg_en_i = 1;
            S1: begin
                reg_mux_sel = {1'b0, instruction[15:13]};
                reg_en_s = 1;
            end
            S2: begin
                if(instruction[1:0] == 2'b00) reg_mux_sel = {1'b0, instruction[12:10]};
                else if (instruction[1:0] == 2'b01) begin
                    reg_imm = {8'h00, instruction[12:5]};
                    reg_mux_sel = 4'h8;
                end
                reg_en_c = 1;
                reg_alu_sel = instruction[4:2];
            end
            S3: begin
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
                reg_done = 1;
            end
        endcase
        end
    end
endmodule