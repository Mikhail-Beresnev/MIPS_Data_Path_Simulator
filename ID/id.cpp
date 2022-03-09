#include "id.h"
//#include mem.h

string controlUnit (string input) {
    string controlSignals; // RegDst, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, Jump, ALUOp1, ALUOp0
    // ALUOp1 & 0 are one signal with two bits output
    int data = stoi(input.substr(0, 6));  // instruction bits 31-26

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
    default:                         // Op Code: 000000
    controlSignals = "1001000010";   // all R-Format instructions, specified with func field
    break;
    }
    return controlSignals;
}

void registerFile (string input, string controlSignals){
    string type;

    if (controlSignals == "1001000010"){            // R-TYPE Instruction
        rsIndex = stoi(input.substr(6, 5), 0, 2);   // binary instruction bits 6-10 converted to decimal index
        rtIndex = stoi(input.substr(11, 5), 0, 2);  // binary instruction bits 11-15 converted to decimal index
        rdIndex = stoi(input.substr(16, 5), 0, 2);  // binary instruction bits 16-20 converted to decimal index
    } else if ((controlSignals == "0000001001") || (controlSignals == "0111100000") || (controlSignals == "0100010000") || (controlSignals == "0101000000")){ // I-TYPE Instruction (LW, SW, ADDI, BRANCH)
        rsIndex = stoi(input.substr(6, 5), 0, 2);   // binary instruction bits 6-10 converted to decimal index
        rtIndex = stoi(input.substr(11, 5), 0, 2);  // binary instruction bits 11-15 converted to decimal index
        addressOrImmediate = input.substr(16, 16);        // address (to label)convert string to binary bits 16-31
        signExtend();
    } else if (controlSignals == "0000000100"){     // J-Type Instruction
        addressOrImmediate = input.substr(6,26);          // address to jump to convert string to binary bits 6-31
    }
}

string instructionType (string input, string controlSignals) {
    string instructionType;

    if (controlSignals == "1001000010"){
    int func = stoi(input.substr(26,6));
    addressOrImmediate = "-1";    // clear address/immediate var for R-TYPE instructions
    switch (func){
        case 100000:
        instructionType = "ADD";
        break;
        case 100100:
        instructionType = "AND";
        break;
        case 11010:         // 011010
        instructionType = "DIV";
        break;
        case 11000:         // 011000
        instructionType = "MULT";
        break;
        case 100111:
        instructionType = "NOR";
        break;
        case 100101:
        instructionType = "OR";
        break;
        case 10:            // 000010
        instructionType = "SRL";
        break;
        case 100010:
        instructionType = "SUB";
        break;
        case 100110:
        instructionType = "XOR";
        break;
        default:
        instructionType = "SLL";    // SLL has func code of 0
        break;
    }
    } else if (controlSignals == "0000001001"){ // BRANCHING
        int branch = stoi(input.substr(0, 6));
        if (branch == 100){
            instructionType == "BEQ";
        } else if (branch == 101){
            instructionType == "BNE";
        }
    } else if (controlSignals == "0111100000"){
        instructionType = "LW";
    } else if (controlSignals == "0100010000"){
        instructionType = "SW";
    } else if (controlSignals == "0101000000"){
        instructionType = "ADDI";
    } else if (controlSignals == "0000000100"){
        instructionType == "J";
    }
    return instructionType;
}

void signExtend (){
    int significantBit = stoi(addressOrImmediate.substr(0,1));
    string extendBits;
    if (significantBit == 1){
        extendBits = "1111111111111111";
    } else if (significantBit == 0){
        extendBits = "0000000000000000";
    }
    addressOrImmediate = extendBits + addressOrImmediate;
}

 void idStage (string input){
    string controlSignals = controlUnit(input);
    registerFile(input, controlSignals);
    string instructionCall = instructionType(input, controlSignals);

    cout << "Instruction: " << instructionCall << endl;
    if (controlSignals != "0000000100"){    // rs and rt fields for all except J-TYPE instructions
        cout << "rs Index: " << rsIndex << ", rt Index: " << rtIndex;
    }
    if (controlSignals == "1001000010"){    // rd field only for R-TYPE instructions
        cout << ", rd Index: " << rdIndex << endl;
    } else if (controlSignals == "0000000100"){
        cout << "jump address: " << addressOrImmediate << endl;
    } else if (controlSignals != "0000001001"){
        cout << ", immediate: " << addressOrImmediate << endl;
    } else {
        cout << ", branch offset: " << addressOrImmediate << endl;
    }
 }
 