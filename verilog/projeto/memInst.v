module memInst(endereco, inst, CLOCK);

input CLOCK;
input [7:0] endereco;
output reg [7:0] inst;

// Declaração da memória de instruções (256 posições de 8 bits)
reg [7:0] mem [0:255];

initial begin
    mem[8]  = 8'b01000111; // LOADI R1, #3
    mem[9]  = 8'b10001011; // INC R1, 1
    mem[10] = 8'b10001100; // DEC R1, 2
    mem[11] = 8'b00000001; // STORE 0, R1
    mem[12] = 8'b00100010; // LOAD 0, R2
    mem[13] = 8'b01101101; // JUMP cond=1, R1
    mem[14] = 8'b11100000; // HALT
    // Zera o resto da memória
    for(integer i = 15; i < 256; i++) begin
        mem[i] = 8'b00000000;
    end
end

// Lógica de leitura
always @(negedge CLOCK) begin
    inst <= mem[endereco];
end

endmodule