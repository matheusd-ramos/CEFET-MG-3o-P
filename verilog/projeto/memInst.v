
module memInst(endereco, inst, CLOCK);

input CLOCK;
input [7:0] endereco;
output reg [7:0] inst;

// Declaração da memória de instruções (256 posições de 8 bits)
reg [7:0] mem [0:255];

initial begin
    mem[8]  = 8'b01000111; // LOADI r0, 7
    mem[9]  = 8'b10000011; // INC r0, 1
    mem[10] = 8'b10000100; // DEC r0, 2
    mem[11] = 8'b00000000; // STORE 0, r0
    mem[12] = 8'b00101000; // LOAD 0, r1
    mem[13] = 8'b00100010; // LOAD r3 (0), r2
    mem[14] = 8'b01101101; // JUMP cond=1, r1
    mem[15] = 8'b11100000; // HALT
    for(integer i = 16; i < 256; i++) begin
        mem[i] = 8'b00000000;
    end
end

// Lógica de leitura
always @(negedge CLOCK) begin
    inst <= mem[endereco];
end

endmodule