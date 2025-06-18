module PC (HALT, pc, pcNovo, CLOCK);

input HALT;
output [7:0] pc;
input [7:0] pcNovo;

always @(posedge CLCOCK && (!HALT)) begin
    pc <= pcNovo;
end

endmodule