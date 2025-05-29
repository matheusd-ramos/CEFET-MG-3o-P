

module ANDTB;

// Declaração das variáveis
reg a, b;
wire result_and, result_nand;

// Dados de teste
initial begin
    $display("Teste do AND e NAND");
    $display("Tempo  a  b  AND  NAND");
    a=0; b=0; #1
    a=0; b=1; #1
    a=1; b=0; #1
    a=1; b=1; #1

    $finish;
end

// Instanciação dos módulos
AND and1(a, b, result_and);
NAND nand1(a, b, result_nand);

// Monitoramento das variáveis
initial begin
    $monitor("  %0d    %b  %b   %b     %b", $time, a, b, result_and, result_nand);
end

endmodule