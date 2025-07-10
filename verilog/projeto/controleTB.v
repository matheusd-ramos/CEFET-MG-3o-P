module controleTB;

// Sinais de teste
reg [7:0] instrucao;
wire [1:0] MemToReg;
wire LeMem, EscMem, ALUOp, Jump, ALUSrc, EscReg1, EscReg2, Halt;

// Instância do módulo controle
controle ctrl(instrucao, MemToReg, LeMem, EscMem, ALUOp, Jump, ALUSrc, EscReg1, EscReg2, Halt);

// Geração de formas de onda
initial begin
    $dumpfile("controleTB.vcd");
    $dumpvars(0, controleTB);
    
    // STORE (000)
    instrucao = 8'b00000000;
    #10;
    $display("STORE (000):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // LOAD (001)
    instrucao = 8'b00100000;
    #10;
    $display("LOAD (001):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // LOADI (010)
    instrucao = 8'b01000000;
    #10;
    $display("LOADI (010):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // JUMP (011)
    instrucao = 8'b01100000;
    #10;
    $display("JUMP (011):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // DEC (100 com bit 0 = 0)
    instrucao = 8'b10000000;
    #10;
    $display("DEC (100, funct = 0):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // INC (100 com bit 0 = 1)
    instrucao = 8'b10000001;
    #10;
    $display("INC (100, funct = 1):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // SWAP (101)
    instrucao = 8'b10100000;
    #10;
    $display("SWAP (101):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // CMP (110)
    instrucao = 8'b11000000;
    #10;
    $display("CMP (110):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    // HALT (111)
    instrucao = 8'b11100000;
    #10;
    $display("HALT (111):");
    $display("  MemToReg: %b, LeMem: %b, EscMem: %b", MemToReg, LeMem, EscMem);
    $display("  ALUOp: %b, Jump: %b, ALUSrc: %b", ALUOp, Jump, ALUSrc);
    $display("  EscReg1: %b, EscReg2: %b, Halt: %b", EscReg1, EscReg2, Halt);
    $display("");
    
    $finish;
end

endmodule 