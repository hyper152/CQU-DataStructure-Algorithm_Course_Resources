`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/05/03 01:34:38
// Design Name: 
// Module Name: mux2
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


module mux2 #(parameter WIDTH = 32)(
    input [WIDTH-1:0] option1, option2,
    input select, rst,
    output reg [WIDTH-1:0] data
    );

    always @ (*) begin
        if (rst) begin
            data <= 0;
        end
        else begin
            if (select) begin
                data = option2;
            end
            else begin
                data = option1;
            end
        end
    end
endmodule