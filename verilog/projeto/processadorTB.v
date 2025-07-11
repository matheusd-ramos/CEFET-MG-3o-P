module processadorTB;

reg CLOCK;
integer ciclo;

// Instanciação do processador
processador proc(.CLOCK(CLOCK));

// Geração do clock
initial begin
    CLOCK = 0;
    forever #5 CLOCK = ~CLOCK;
end

// Controle de ciclos e exibição
initial begin
    ciclo = 1;
    $monitor("r0=%0d r1=%0d r2=%0d r3=%0d", proc.bancoRegs_modulo.r0, proc.bancoRegs_modulo.r1, proc.bancoRegs_modulo.r2, proc.bancoRegs_modulo.r3);

    // Roda até HALT ou 100 ciclos
    repeat (100) begin
        @(negedge CLOCK);
        ciclo = ciclo + 1;
        if (proc.Halt) begin
            $display("\nmem[0]=%0d mem[1]=%0d mem[2]=%0d mem[3]=%0d", proc.memDados_modulo.mem[0], proc.memDados_modulo.mem[1], proc.memDados_modulo.mem[2], proc.memDados_modulo.mem[3]);
            $finish;
        end
    end
    $display("\nmem[0]=%0d mem[1]=%0d mem[2]=%0d mem[3]=%0d", proc.memDados_modulo.mem[0], proc.memDados_modulo.mem[1], proc.memDados_modulo.mem[2], proc.memDados_modulo.mem[3]);
    $finish;
end

endmodule