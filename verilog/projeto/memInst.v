module memInst(endereco, inst, CLOCK);

input CLOCK;
input [7:0] endereco;
output reg [7:0] inst;

// Declaração da memória de instruções (256 posições de 8 bits)
reg [7:0] mem [0:255];

initial begin
    // Inicializando a memória com zeros
    for(integer i = 0; i < 256; i++) begin
        mem[i] = 8'b00000000;
    end
end

// Lógica de leitura
always @(negedge CLOCK) begin
    inst <= mem[endereco];
end

endmodule