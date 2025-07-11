module processadorTB;

reg CLOCK;
integer ciclo;

// Instanciação do processador
processador uut(.CLOCK(CLOCK));

// Geração do clock
initial begin
    CLOCK = 0;
    forever #5 CLOCK = ~CLOCK;
end

// Controle de ciclos e exibição
initial begin
    ciclo = 1;
    $display("Ciclo | r0 | r1 | r2 | r3");
    $monitor("%2d | %2d | %2d | %2d | %2d", ciclo, uut.bancoRegs_modulo.r0, uut.bancoRegs_modulo.r1, uut.bancoRegs_modulo.r2, uut.bancoRegs_modulo.r3);
    
    // Roda até HALT ou 100 ciclos
    repeat (100) begin
        @(negedge CLOCK);
        ciclo = ciclo + 1;
        if (uut.Halt) begin
            // Mostra vetor ordenado
            $display("\nVetor ordenado na memória de dados:");
            $display("mem[0]=%d", uut.memDados_modulo.mem[0]);
            $display("mem[1]=%d", uut.memDados_modulo.mem[1]);
            $display("mem[2]=%d", uut.memDados_modulo.mem[2]);
            $display("mem[3]=%d", uut.memDados_modulo.mem[3]);
            $finish;
        end
    end
    // Se não parou por HALT, mostra mesmo assimj
    $display("\nVetor ordenado na memória de dados:");
    $display("mem[0]=%d", uut.memDados_modulo.mem[0]);
    $display("mem[1]=%d", uut.memDados_modulo.mem[1]);
    $display("mem[2]=%d", uut.memDados_modulo.mem[2]);
    $display("mem[3]=%d", uut.memDados_modulo.mem[3]);
    $finish;
end

endmodule