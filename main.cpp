#include <iostream>
#include <string>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./ID/id.h"
#include "./IF/if.h"
#include "./UI/ui.h"
#include "./helpful/helpful.h"

using namespace std;

string registers[][32] = {
{"$0","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"},
{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"}
};

/**  Registers(all prefixed w/ $): zero (always 0), at (reserved for assembler), v0-v1 (return), a0-a3 (arguments), t0-t7 (temp), 
*    s0-s7 (save regs), t8-t9 (temp), k0-k1 (kernel), gp (global pointer), sp (stack pointer), fp (frame pointer), ra (return address)
**/

string userInstruction;
int rsIndex;
int rtIndex;
int rdIndex;
string addressOrImmediate;

string userInput();
void test();
void single_input_test(string functionName, string function, string expected, string input);
void double_input_test(string functionName, string function, string expected, string input, string input_2);
void triple_input_test(string functionName, string function, string expected, string input, string input_2, string input_3);

int main() {
    string input = userInput();

    idStage(input);
    // string label = getLabel();                       // NOT PROGRAMMED YET
    // regPrompts();                                    // NOT PROGRAMMED YET

    return 0;
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

void single_input_test(string functionName, string function, string expected, string input) {
    string acutal = function(input);
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
}

void double_input_test(string functionName, string function, string expected, string input, string input_2) {
    string acutal = function(input, input_2);
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
}

void triple_input_test(string functionName, string function, string expected, string input, string input_2, string input_3) {
    string acutal = function(input, input_2, input_3);
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
}

void test() {

}



