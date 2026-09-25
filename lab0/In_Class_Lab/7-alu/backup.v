module alu #(
    parameter DATA_WIDTH = 32,
    parameter INST_WIDTH = 4
)(
    input                   i_clk,
    input                   i_rst_n,
    input  [DATA_WIDTH-1:0] i_data_a,
    input  [DATA_WIDTH-1:0] i_data_b,
    input  [INST_WIDTH-1:0] i_inst,
    input                   i_valid,
    output [DATA_WIDTH-1:0] o_data,
    output                  o_overflow,
    output                  o_valid
);

    // TODO: Implement the ALU module
    reg [DATA_WIDTH-1:0] result;

    always @(posedge i_clk) begin
        if (i_rst_n) begin
        end

        // i_data_a + i_data_b (signed)
        if (i_inst == 4'd0) begin
            result = i_data_a + i_data_b;
        end

        // i_data_a - i_data_b (signed)
        if (i_inst == 4'd1) begin
        end

        // i_data_a * i_data_b (signed)
        if (i_inst == 4'd2) begin
        end

        // max(i_data_a, i_data_b) (signed)
        if (i_inst == 4'd3) begin
        end

        // min(i_data_a, i_data_b) (signed)
        if (i_inst == 4'd4) begin
        end

        // i_data_a + i_data_b (unsigned)
        if (i_inst == 4'd5) begin
            result = i_data_a + i_data_b;
        end

        // i_data_a - i_data_b (unsigned)
        if (i_inst == 4'd6) begin
            result = i_data_a - i_data_b;
        end

        // i_data_a * i_data_b (unsigned)
        if (i_inst == 4'd7) begin
            result = i_data_a * i_data_b;
        end

        // max(i_data_a, i_data_b) (unsigned)
        if (i_inst == 4'd8) begin
            result = (i_data_a > i_data_b) ? i_data_a : i_data_b;
        end

        // min(i_data_a, i_data_b) (unsigned)
        if (i_inst == 4'd9) begin
            result = (i_data_a > i_data_b) ? i_data_b : i_data_a;
        end

        // 	i_data_a & i_data_b
        if (i_inst == 4'd10) begin
            result <= i_data_a & i_data_b;
        end

        // i_data_a | i_data_b
        if (i_inst == 4'd11) begin
            result <= i_data_a | i_data_b;
        end

        // i_data_a ^ i_data_b
        if (i_inst == 4'd12) begin
            result <= i_data_a ^ i_data_b;
        end

        // ~ i_data_a
        if (i_inst == 4'd13) begin
            result <= ~i_data_a;
        end

        // 	Bit reverse i_data_a
        if (i_inst == 4'd14) begin
        end
    end

    assign o_data <= result;
    
    

endmodule