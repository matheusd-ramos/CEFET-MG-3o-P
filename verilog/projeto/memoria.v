module memoria(CLOCK, ende_inst, inst, ende_dados, escMem, leMem, escDado, saiDado);

input CLOCK;
input [7:0] ende_inst, ende_dados;
input escMem, leMem;
input [7:0] escDado;
output reg [7:0] inst, saiDado;

// Memória compartilhada
reg [7:0] mem [0:255]; // 256 posições de 8 bits cada

// Inicialização da memória com instruções e dados
initial begin
    // Instruções (primeiros endereços)
    mem[0] = 8'b00000001; // Instrução 1
    mem[1] = 8'b00000010; // Instrução 2
    mem[2] = 8'b00000011; // Instrução 3
    mem[3] = 8'b00000100; // Instrução 4
    mem[4] = 8'b00000101; // Instrução 5
    mem[5] = 8'b00000110; // Instrução 6
    mem[6] = 8'b00000111; // Instrução 7
    mem[7] = 8'b00001000; // Instrução 8
    
    // Dados (endereços seguintes)
    mem[8] = 8'b00000000; // Dado 1
    mem[9] = 8'b00000001; // Dado 2
    mem[10] = 8'b00000010; // Dado 3
    mem[11] = 8'b00000011; // Dado 4
    
    // Inicializar o resto da memória com 0
    for (integer i = 12; i < 256; i = i + 1) begin
        mem[i] = 8'b00000000;
    end
end

// Lógica de escrita e leitura
always @(posedge CLOCK) begin
    // Escrita na memória (quando escMem = 1)
    if (escMem) begin
        mem[ende_dados] <= escDado;
    end
    
    // Leitura de instruções (sempre)
    inst <= mem[ende_inst];
    
    // Leitura de dados (quando leMem = 1)
    if (leMem) begin
        saiDado <= mem[ende_dados];
    end
end

endmodule 