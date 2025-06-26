module bancoDeRegsTB;

// Sinais de teste
reg CLOCK;
reg [7:0] dado;
reg escReg1, escReg2;
reg [1:0] R1, R2;
wire [7:0] S1, S2;

// Instanciação do módulo
bancoDeRegs banco(R1, R2, dado, escReg1, escReg2, S1, S2, CLOCK);

// Clock simples
initial begin
    CLOCK = 0;
    forever #5 CLOCK = ~CLOCK;
end

// Teste principal
initial begin
    // Inicialização
    dado = 8'b00000000;
    escReg1 = 0;
    escReg2 = 0;
    R1 = 2'b00;
    R2 = 2'b00;
        
    // Teste 1: Escrever valores nos registradores
    dado = 8'b00000001; R2 = 2'b00; escReg2 = 1; #10; escReg2 = 0;
    dado = 8'b00000010; R2 = 2'b01; escReg2 = 1; #10; escReg2 = 0;
    dado = 8'b00000011; R2 = 2'b10; escReg2 = 1; #10; escReg2 = 0;
    dado = 8'b00000100; R2 = 2'b11; escReg2 = 1; #10; escReg2 = 0;
    
    $display("----------------------------------------");

    $display("Lendo registradores...");

    // Teste 2: Ler registradores
    R1 = 2'b00; R2 = 2'b01; #10;
    $display("R0 =%d, R1 =%d", S1, S2);
    
    R1 = 2'b10; R2 = 2'b11; #10;
    $display("R2 =%d, R3 =%d", S1, S2);
    
    $display("----------------------------------------");
    
    // Teste 3: Tentar escrever com escReg2 desativado
    $display("Testando escrita com escReg2 desativado...");
    
    // Garantir que escReg2 está desativado
    escReg2 = 0; #5;
    
    // Tentar escrever 255 no R0
    dado = 8'b11111111; R2 = 2'b00; #10;
    
    // Verificar se R0 permanece inalterado
    R1 = 2'b00; R2 = 2'b01; #10;
    $display("Apos tentativa de escrita - R0=%d, R1=%d", S1, S2);
    
    $display("----------------------------------------");
    
    // Teste 4: Tentar troca com apenas escReg1 ativado
    $display("Testando troca com apenas escReg1 ativado...");
    R1 = 2'b00; R2 = 2'b11; escReg1 = 1; escReg2 = 0; #10;
    escReg1 = 0;
    
    // Verificar se R0 e R3 permanecem inalterados
    R1 = 2'b00; R2 = 2'b11; #10;
    $display("Apos tentativa de troca (escReg1=1, escReg2=0) - R0=%d, R3=%d", S1, S2);
    
    $display("----------------------------------------");
    
    // Teste 5: Tentar troca com apenas escReg2 ativado
    $display("Testando troca com apenas escReg2 ativado...");
    escReg2 = 1; R1 = 2'b00; R2 = 2'b11; escReg1 = 0; #10;
    
    // Verificar se R0 e R3 permanecem inalterados
    R1 = 2'b00; R2 = 2'b11; #10;
    $display("Apos tentativa de troca (escReg1=0, escReg2=0) - R0=%d, R3=%d", S1, S2);
    
    $display("----------------------------------------");
    
    // Teste 6: Trocar R0 com R3 (ambos sinais ativados)
    R1 = 2'b00; R2 = 2'b11; escReg1 = 1; escReg2 = 1; #10;
    escReg1 = 0; escReg2 = 0;
    
    $display("Trocando R0 com R3 (ambos sinais ativados)...");

    // Verificar troca
    R1 = 2'b00; R2 = 2'b11; #10;
    $display("Apos troca - R0=%d, R3=%d", S1, S2);
    
    $display("----------------------------------------");
    $display("Teste concluido!");
    
    $finish;
end

endmodule
