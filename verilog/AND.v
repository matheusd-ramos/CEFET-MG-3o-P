

module AND(a, b, result);

input a, b;
output result;
wire aux;

NAND nand1(a, b, aux);
NAND nand2(aux, aux, result);

endmodule