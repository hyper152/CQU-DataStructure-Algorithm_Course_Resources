`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/30 21:25:15
// Design Name: 
// Module Name: pc
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module pc(
    input clk, rst, en, 
    input wire [31:0] newPC,
    output reg [31:0] pc
);

    initial begin
        pc <= 32'b00;
    end

    always @(posedge clk) begin
        if (rst) begin
            pc <= 0;
        end
        else if(en) begin
            pc <= newPC;
        end
            
    end

endmodule
