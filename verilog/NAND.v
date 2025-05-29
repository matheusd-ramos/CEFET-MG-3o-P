

module NAND(a, b, result);

input a, b;
output result;

assign result = ~(a & b);

endmodule

