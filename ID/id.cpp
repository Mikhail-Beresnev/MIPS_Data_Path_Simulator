#include "id.h"
//#include mem.h

string controlUnit (string input) {
    string controlSignals; // RegDst, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, Jump, ALUOp1, ALUOp0
    // ALUOp1 & 0 are one signal with two bits output
    string input2 = input.substr(26,6);
    // input2.insert(0, "0.");
    cout << input2 << endl;
    int data = stoi(input2);
    // int data = stoi(input.substr(26, 6));  // instruction bits 31-26
    cout << data << endl;
    switch (data){
    case 100:  // BEQ (000100)
    controlSignals = "0000001001";
    break;
    case 101:  // BNE (000101)
    controlSignals = "0000001001";   // X0X0001001
    break;
    case 100011:  // LW (100011)
    controlSignals = "0111100000";   // 0111100000
    break;
    case 101011:  // SW (101011)
    controlSignals = "0100010000";   // X1X0010000
    break;
    case 1000:  // ADDI (001000)
    controlSignals = "0101000000";   // 0101000000
    break;  
    case 10:  // J (000010)
    controlSignals = "0000000100";   // XXX00001XX
    break;
    default:
    controlSignals = "1001000010";   // all R-Format instructions (all critical)
    break;
    }
    return controlSignals;
}

