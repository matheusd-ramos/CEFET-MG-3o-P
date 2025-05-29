

module majorityTB;

// Declaração das variáveis
reg a, b, c; 
wire result;

// Instanciação do módulo
majority3 majority1(a, b, c, result);

// Dados de teste
initial begin
    $display("Teste da funcao majority");
    $display("Tempo  a  b  c  Resultado");

    a=0; b=0; c=0; #1
    a=1; b=0; c=0; #1
    a=1; b=1; c=0; #1
    a=1; b=1; c=1; #1
    a=0; b=0; c=1; #1

    $finish;
end

// Monitoramento das variáveis
initial begin
    $monitor("  %0d    %b  %b  %b      %b", $time, a, b, c, result);
end

endmodule

