#include "ui.h"

string getOperation(){
    string operation;
    int choice = 0;    // purposely set to invalid value

    while ((choice < 1) || (choice > 16)){
        cout << "Enter instruction operation (enter associated integer from below): " << endl;
        // cout << "ADD: 1, SUB: 2, MULT: 3, DIV: 4, OR: 5, NOR: 6, XOR: 7, AND: 8, " << endl;
        // cout << "SLL: 9, SRL: 10, ADDI: 11, BNE: 12, BEQ: 13, LW: 14, SW: 15, J: 16" << endl;
        cout << "ADD: 1, SUB: 2, MULT: 3, DIV: 4, OR: 5," << endl;
        cout << "NOR: 6, AND: 7, ADDI: 8, LW: 9, SW: 10" << endl;
        // No longer implementing XOR, SLL, SRL, BNE, BEQ, or J in final code
        cin >> choice;
        if ((choice < 1) || (choice > 16)){
            cout << "You have entered an invalid instruction!" << endl;
            cout << "Please try again..." << endl;
        } 

        switch (choice){
            case 1:
            operation = "ADD";
            break;
            case 2:
            operation = "SUB";
            break;
            case 3:
            operation = "MULT";
            break;
            case 4:
            operation = "DIV";
            break;       
            case 5:
            operation = "OR";
            break;
            case 6:
            operation = "NOR";
            break;
            case 7:
            operation = "AND";
            break;
            case 8:
            operation = "ADDI";
            break;
            case 9:
            operation = "LW";
            break;
            case 10:
            operation = "SW";
            break;
            default:
            break;
        }
    }
    userInstruction = operation + " ";
    return operation;
}

string generateOpCode(string operation){
    string opCode = "0";
    if (operation == "BEQ"){
        opCode = "000100";
    } else if (operation == "BNE"){
        opCode = "000100";
    } else if (operation == "LW"){
        opCode = "100011";
    } else if (operation == "SW"){
        opCode = "101011";
    } else if (operation == "ADDI"){
        opCode = "001000";
    } else if (operation == "J"){
        opCode = "000010";
    } else {
        opCode = "000000"; // All R-TYPE instructions
    }
    return opCode; // produce op code code from operation selected
}

string generateFuncCode(string operation){
    string funcCode = "0";
    if (operation == "ADD"){
        funcCode = "100000";
    } else if (operation == "AND"){
        funcCode = "100100";
    } else if (operation == "DIV"){
        funcCode = "011010";
    } else if (operation == "MULT"){
        funcCode = "011000";
    } else if (operation == "NOR"){
        funcCode = "100111";
    } else if (operation == "OR"){
        funcCode = "100101";
    } else if (operation == "SRL"){
        funcCode = "000010";
    } else if (operation == "SUB"){
        funcCode = "100010";
    } else if (operation == "XOR"){
        funcCode = "100110";
    } else if (operation == "SLL"){
        funcCode = "000000";
    } else {
        funcCode = "111111";    // SHOULD NEVER HAPPEN
    }
    return funcCode; // produce func code for R-TYPE instructions from operation selected
}

int getRegIndex(){
    string choice = "0";
    int index = -1;

    while ((index < 4) || (index > 25)){
        cin >> choice;
        for (int i = 0; i < 32; i++){
            if(choice == registers[0][i]){
                index = i;
            }
        }
        if (((index < 4) && (index > -1)) || ((index > 25) && (index < 32))){
            cout << "You have selected a reserved register location!" << endl;
            cout << "Please try again..." << endl;
        } else if ((index < 0) || (index > 31)){
            cout << "You have entered an invalid destination register!" << endl;
            cout << "Please try again..." << endl;
        }
    }
    userInstruction = userInstruction + choice;
    return index;
}

string getImmediate(){
    int immediate = 0;
    cout << "Enter signed immediate value (integer): " << endl;
    cin >> immediate;
    string binaryVal = int_to_binary(immediate);
    userInstruction = userInstruction + binaryVal;
    return binaryVal;
}

string getAddressOffset(){
    int offset = 1;     // purposely intialized to invalid offset
    while((offset % 4) != 0){
        cout << "Enter offset value (in bits):" << endl;
        cin >> offset;
        if ((offset % 4) != 0){
            cout << "You have entered an invalid offset value! Offset must be divisible by 4 (or equal 0) to match word addressing." << endl;
            cout << "Please try again..." << endl;
        }
    } 
    string binaryOffset = int_to_binary(offset);
    userInstruction = userInstruction + binaryOffset;
    return binaryOffset;
}

string getLabel(){
    string label = "none";
    cout << "Enter label (make sure exact same spelling and case): " << endl;
    cin >> label;
    userInstruction = userInstruction + label;
    return label;
}

string regPrompts(string opCode, string funcCode){
    string instruction = "0";
    if (opCode == "000000"){    // R-TYPE instructions
        instruction = rinstructionPrompts(funcCode);
    } else if (opCode == "001000"){
        instruction = addiInstructionPrompts();
    } else if ((opCode == "100011") || (opCode == "101011")){
        instruction = lswInstructionPrompts(opCode);
    } else if ((opCode == "000100") || (opCode == "000101")){
        branchInstructionPrompts(opCode);
    } else if (opCode == "000010"){
        jumpInstructionPrompts(opCode);
    }
    return instruction; // return converted instruction in binary
}

string rinstructionPrompts (string funcCode){
    string instruction;
    cout << "Enter the destination register (rd): " << endl;
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rd = getRegIndex();
    userInstruction = userInstruction + ", ";
    cout << endl << "Enter the starting register (rs): " << endl;
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rs = getRegIndex();
    userInstruction = userInstruction + ", ";
    cout << endl << "Enter the second register (rt): " << endl;
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rt = getRegIndex();

    return "000000" + int_to_binary(rs).substr(27,5) + int_to_binary(rt).substr(27,5) + int_to_binary(rd).substr(27,5) + "00000" + funcCode;
}

string addiInstructionPrompts(){
    cout << "Enter the destination register (rt): " << endl;
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rt = getRegIndex();
    userInstruction = userInstruction + ", ";
    cout << endl << "Enter the first register (rs): " << endl;
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rs = getRegIndex();
    userInstruction = userInstruction + ", ";
    cout << endl;
    string immediate = getImmediate();
    return "001000" + int_to_binary(rs).substr(27,5) + int_to_binary(rt).substr(27,5) + immediate.substr(16,16);
}

string lswInstructionPrompts(string opCode){
    if (opCode == "100011"){
        cout << "Enter the destination register (rt): " << endl;
    } else if (opCode == "101011"){
        cout << "Enter the register being stored (rt): " << endl;
    }
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rt = getRegIndex();
    userInstruction = userInstruction + ", ";
    cout << endl;
    string offset = getAddressOffset();
    userInstruction = userInstruction + "(";
    cout << endl << "Enter reference register for addressing: " << endl;
    int rs = getRegIndex();
    userInstruction = userInstruction + ")";
    return opCode + int_to_binary(rs).substr(27,5) + int_to_binary(rt).substr(27,5) + offset.substr(16,16);
}

string branchInstructionPrompts(string opCode){
    cout << "Enter the starting register (rs): " << endl;
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rs = getRegIndex();
    userInstruction = userInstruction + ", ";
    cout << endl << "Enter the second register (rt): " << endl;
    cout << "NOTE: registers $0-$v1 and $k0-$ra are reserved for the operating system." << endl;
    int rt = getRegIndex();
    userInstruction = userInstruction + ", ";
    cout << endl;
    string label = getLabel();
    string labelAddress = labelToAddress(opCode);
    return opCode + int_to_binary(rs).substr(27,5) + int_to_binary(rt).substr(27,5) + labelAddress;
}

string jumpInstructionPrompts(string opCode){
    string label = getLabel();
    string labelAddress = labelToAddress(opCode);
    return opCode + labelAddress;
}

string labelToAddress(string opCode){
    int randomAddress = 1;

    while ((randomAddress % 4) != 0){
        randomAddress = rand();
    }
    if ((opCode == "000100") || (opCode == "000101")){
        return int_to_binary(randomAddress).substr(16,16);  // 16 bit address for branching
    } else if (opCode == "000010"){
        return int_to_binary(randomAddress).substr(6,26);   // 26 bit address for jumping
    }
    return "0";
}

string userInput() {
    string input;
    string funcCode = "0";
    int instructionInputType = -1;
    cout << "Would you like to enter a 32-bit binary instruction or in MIPS format?" << endl;
    while ((instructionInputType < 0) || (instructionInputType > 1)){
        cout << "(0 for binary, 1 for MIPS)" << endl;
        cin >> instructionInputType;
        if ((instructionInputType < 0) || (instructionInputType > 1)){
            cout << "You have entered an invalid input!" << endl << "Please try again..." << endl;
        }
    }

    cout << endl << "Unreserved Register Data: " << endl;
    for (int i = 0; i < 22; i++){
        cout << registers[0][i+4] << " = " << registers[1][i+4] << endl;
    }
    cout << "Reserved Register Data: " << endl;
    for (int j = 0; j < 32; j++){
        if ((j < 4) || (j > 25)){
            cout << registers[0][j] << " = " << registers[1][j] << endl;
        }
    }
    cout << endl;

    if (instructionInputType == 0){
        input = binaryInput();
    } else if (instructionInputType == 1){
        string operation = getOperation();
        string opCode = generateOpCode(operation);
        if (opCode == "000000"){
            funcCode = generateFuncCode(operation);
        }
        input = regPrompts(opCode, funcCode);
        cout << endl << "Your instruction: " << userInstruction << endl;
        cout << "Binary Form: " << input << endl;
    }
    return input;
}
