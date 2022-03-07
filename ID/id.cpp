#include id.h
#include mem.h

string controlUnit (string input) {
    string controlSignals; // RegDst, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, Jump, ALUOp1, ALUOp0
    // ALUOp1 & 0 are one signal with two bits output
    string data = input.substr(26, 5);  // instruction bits 31-26
    switch data:
    case "000100":  // BEQ
    case "000101":  // BNE
    controlSignals = "0000001001";   // X0X0001001
    break;
    case "100011":  // LW
    controlSignals = "0111100000";   // 0111100000
    break;
    case "101011":  // SW
    controlSignals = "0100010000";   // X1X0010000
    break;
    case "001000":  // ADDI
    controlSignals = "0101000000"    // 0101000000
    break;  
    case "000010":  // J
    controlSignals = "0000000100";   // XXX00001XX
    break;
    default:
    controlSignals = "1001000010";   // all R-Format instructions
    break;

    return controlSignals;
}
