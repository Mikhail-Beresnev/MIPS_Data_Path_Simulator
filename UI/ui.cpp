#include "ui.h"

string getOperation(){
    string operation;
    int choice = 0;
    // bool confirm = false;

    // while ((choice < 0) || (choice > 16) || (confirm == false)){
    while ((choice < 0) || (choice > 16)){
    cout << "Enter instruction operation: " << endl;
    cout << "ADD: 1, SUB: 2, MULT: 3, DIV: 4, OR: 5, NOR: 6, XOR: 7, AND: 8, " << endl;
    cout << "SLL: 9, SRL: 10, ADDI: 11, BNE: 12, BEQ: 13, LW: 14, SW: 15, J: 16" << endl;
    cin >> choice;
    if ((choice < 0) || (choice > 16)){
        cout << "You have entered an invalid instruction! Please try again..." << endl;
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

    // cout << "Are you sure you want to run operation " << operation << "? (y - 1/n - 0)" << endl;
    // cin >> confirm;
    // cout << endl;
    }

    return operation;
}

string getDestinationReg(){
    int choice = 0;

    while ((choice < 4) || (choice > 25)){
        cout << "Enter the destination register index (rd): " << endl;
        cout << "NOTE: rd index 0-3 and 26-31 are reserved for the operating system." << endl;
        cin >> choice;
        if ((choice < 0) || (choice > 31)) {
            if ((choice < 4) || (choice > 25)){
                cout << "You have selected a reserved register location! Please try again..." << endl;
            } else {
                cout << "You have entered an invalid destination register! Please try again..." << endl;
            }
        }
    }
    rdIndex = choice;

    return "1";
}

string getStartReg(){
    return "0";
}

string getSecondReg(){
    return "0";
}

string getImmediate(){
    return "0";
}

string getAddress(){
    return "0";
}

string getLabel(){
    return "0";
}

void regPrompts(string operation){
    cout << "HI" << endl;
}