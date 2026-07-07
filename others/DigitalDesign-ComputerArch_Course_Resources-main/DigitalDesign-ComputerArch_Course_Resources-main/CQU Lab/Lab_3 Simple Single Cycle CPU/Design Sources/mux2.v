`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/16 20:16:20
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


module mux2(
    input [31:0] option1,
    input [31:0] option2,
    input select,
    output reg [31:0] data
    );
    
always @ (*) begin
    case (select) 
        1'b0: data = option1;
        1'b1: data = option2;
    endcase
end

endmodule