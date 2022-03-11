#include "ui.h"

string getOperation(){
    string operation;
    int choice = 0;    // purposely set to invalid value

    while ((choice < 1) || (choice > 16)){
        cout << "Enter instruction operation: " << endl;
        cout << "ADD: 1, SUB: 2, MULT: 3, DIV: 4, OR: 5, NOR: 6, XOR: 7, AND: 8, " << endl;
        cout << "SLL: 9, SRL: 10, ADDI: 11, BNE: 12, BEQ: 13, LW: 14, SW: 15, J: 16" << endl;
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
            operation = "XOR";
            break;
            case 8:
            operation = "AND";
            break;
            case 9:
            operation = "SLL";
            break;
            case 10:
            operation = "SRL";
            break;
            case 11:
            operation = "ADDI";
            break;
            case 12:
            operation = "BNE";
            break;
            case 13:
            operation = "BEQ";
            break;
            case 14:
            operation = "LW";
            break;
            case 15:
            operation = "SW";
            break;
            case 16:
            operation = "J";
            break;
            default:
            break;
        }
    }

    return operation;
}

string generateOpCode(string operation){
    return "0"; // produce op code code from operation selected
}

string generateFuncCode(string operation){
    return "0"; // produce func code for R-TYPE instructions from operation selected
}

string getDestinationReg(){
    int choice = 0;

    while ((choice < 4) || (choice > 25)){
        cout << "Enter the destination register index (rd): " << endl;
        cout << "NOTE: index 0-3 and 26-31 are reserved for the operating system." << endl;
        cin >> choice;
        if (((choice < 4) && (choice > -1)) || ((choice > 25) && (choice < 32))){
            cout << "You have selected a reserved register location!" << endl;
            cout << "Please try again..." << endl;
        } else if ((choice < 0) || (choice > 31)){
            cout << "You have entered an invalid destination register!" << endl;
            cout << "Please try again..." << endl;
        }
    }
    return int_to_binary(choice);
}

string getStartReg(){
    int choice = 0;

    while ((choice < 4) || (choice > 25)){
        cout << "Enter the starting register index (rs): " << endl;
        cout << "NOTE: index 0-3 and 26-31 are reserved for the operating system." << endl;
        cin >> choice;
        if (((choice < 4) && (choice > -1)) || ((choice > 25) && (choice < 32))){
            cout << "You have selected a reserved register location!" << endl;
            cout << "Please try again..." << endl;
        } else if ((choice < 0) || (choice > 31)){
            cout << "You have entered an invalid starting register!" << endl;
            cout << "Please try again..." << endl;
        }
    }
    return int_to_binary(choice);
}

string getSecondReg(){
    int choice = 0;

    while ((choice < 4) || (choice > 25)){
        cout << "Enter the second register index (rt): " << endl;
        cout << "NOTE: index 0-3 and 26-31 are reserved for the operating system." << endl;
        cin >> choice;
        if (((choice < 4) && (choice > -1)) || ((choice > 25) && (choice < 32))){
            cout << "You have selected a reserved register location!" << endl;
            cout << "Please try again..." << endl;
        } else if ((choice < 0) || (choice > 31)){
            cout << "You have entered an invalid second register!" << endl;
            cout << "Please try again..." << endl;
        }
    }
    return int_to_binary(choice);
}

string getImmediate(){
    int immediate = 0;
    cout << "Enter immediate value (integer): " << endl;
    cin >> immediate;
    return int_to_binary(immediate);
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
    return int_to_binary(offset);
}

string getLabel(){
    // NOT SURE HOW WE ARE GOING TO DO LABEL STUFF
    return "0";
}

void regPrompts(string operation){
    // control which prompts are shown based on operation selected
}