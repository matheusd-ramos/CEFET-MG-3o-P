module memInst(endereco, inst, CLOCK);

input CLOCK;
input [7:0] endereco;
output reg [7:0] inst;

// Declaração da memória de instruções (256 posições de 8 bits)
reg [7:0] mem [0:255];

initial begin
    // Bubble Sort para vetor de 4 elementos em memDados[0-3]
    // Vetor inicial: [3, 1, 4, 2]
    // Registradores: r0=i, r1=j, r2=tmp, r3=tmp2
    mem[8]  = 8'b01000000; // LOADI r0, 0
    mem[9]  = 8'b01001000; // LOADI r1, 0
    mem[10] = 8'b00110000; // LOAD r2, r1
    mem[11] = 8'b10001001; // INC r1, 1
    mem[12] = 8'b00111000; // LOAD r3, r1
    mem[13] = 8'b10001000; // DEC r1, 1
    mem[14] = 8'b10110001; // CMP r2, r3
    mem[15] = 8'b01110010; // JUMP menor, 18
    mem[16] = 8'b00011000; // STORE r3, r1
    mem[17] = 8'b10001001; // INC r1, 1
    mem[18] = 8'b00010000; // STORE r2, r1
    mem[19] = 8'b10001000; // DEC r1, 1
    mem[20] = 8'b10001001; // INC r1, 1
    mem[21] = 8'b10101010; // CMP r1, 2
    mem[22] = 8'b01101010; // JUMP menor, 10
    mem[23] = 8'b10000001; // INC r0, 1
    mem[24] = 8'b10100010; // CMP r0, 2
    mem[25] = 8'b01101001; // JUMP menor, 9
    mem[26] = 8'b11100000; // HALT
    // Zera o resto da memória
    for(integer i = 27; i < 256; i++) begin
        mem[i] = 8'b00000000;
    end
end

// Lógica de leitura
always @(negedge CLOCK) begin
    inst <= mem[endereco];
end

endmodule