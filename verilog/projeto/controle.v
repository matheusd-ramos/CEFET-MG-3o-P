module controle(instrucao, MemToReg, LeMem, EscMem, ALUOp, Jump, ALUSrc, EscReg1, EscReg2, Halt);

input [7:0] instrucao;
output reg ALUOp, Jump, LeMem, EscMem, ALUSrc, EscReg1, EscReg2, Halt;
output reg [1:0] MemToReg;

always @(instrucao) begin
    // Valores padrão
    MemToReg = 2'b00;
    LeMem = 0;
    EscMem = 0;
    ALUOp = 0;
    Jump = 0;
    ALUSrc = 0;
    EscReg1 = 0;
    EscReg2 = 0;
    Halt = 0;
    
    case (instrucao[7:5]) 
        3'b000: begin // STORE
            EscMem = 1;
        end
        
        3'b001: begin // LOAD
            LeMem = 1;
            EscReg2 = 1;
        end
        
        3'b010: begin // LOADI
            MemToReg = 2'b01;
            EscReg2 = 1;
        end
        
        3'b011: begin // JUMP
           Jump = 1;
        end

        3'b100: begin // INC ou DEC
            if (instrucao[0]) begin
                ALUOp = 0;  // INC
            end 

            else begin
                ALUOp = 1;  // DEC
            end

            MemToReg = 2'b10;
            ALUSrc = 1;
            EscReg2 = 1;
        end

        3'b101: begin // SWAP
           EscReg1 = 1;
           EscReg2 = 1;
        end

        3'b110: begin // CMP
           ALUOp = 1;
        end

        3'b111: begin // HALT
           Halt = 1;
        end

    endcase
end

endmodule

