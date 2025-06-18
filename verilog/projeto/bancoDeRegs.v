module bancoDeRegs(R1, R2, dado, escReg1, escReg2, S1, S2, CLOCK);

input CLOCK;
input [7:0] dado;
input escReg1, escReg2;
input reg [1:0] R1, R2;
output reg [7:0] S1, S2;

reg [7:0] r0, r1, r2, r3;
reg [7:0] aux1, aux2;

// Borda de subida para escrita
always@(posedge CLOCK) begin

    if(escReg2) begin
        case (R2)
            00: r0 = dado;
            01: r1 = dado;
            10: r2 = dado;
            11: r3 = dado;
        endcase
    end

    else if(escReg1 && escReg2) begin
        case (R1)
            00: aux1 = r0;
            01: aux1 = r1;
            10: aux1 = r2;
            11: aux1 = r3;
        endcase

        case (R2)
            00: aux2 = r0;
            01: aux2 = r1;
            10: aux2 = r2;
            11: aux2 = r3;
        endcase

        case (R1)
            00: r0 = aux2;
            01: r1 = aux2;
            10: r2 = aux2;
            11: r3 = aux2;
        endcase

        case (R2)
            00: r0 = aux1;
            01: r1 = aux1;
            10: r2 = aux1;
            11: r3 = aux1;
        endcase
    end
    
end

// Borda de descida para leitura    
always@(negedge CLOCK) begin
    S1 <= R1;
    S2 <= R2;
end

endmodule;