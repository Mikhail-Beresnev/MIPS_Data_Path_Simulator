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
void overall(); // change name to test later
void test_single_input(string functionName, string (*function)(string), string expected, string input);
void test_double_input(string functionName, string (*function)(string, string), string expected, string input, string input_2);
void test_triple_input(string functionName, string (*function)(string, string, string), string expected, string input, string input_2, string input_3);

int main() {
    // string input = userInput();
    overall();
    // idStage(input);
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

void test_single_input(string functionName, string (*function)(string), string expected, string input) {
    string actual = function(input);
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
}

void test_double_input(string functionName, string (*function)(string, string), string expected, string input, string input_2) {
    string actual = function(input, input_2);
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
}

void test_triple_input(string functionName, string (*function)(string, string, string), string expected, string input, string input_2, string input_3) {
    string actual = function(input, input_2, input_3);
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
}

void overall() {
    // Format: Function Name, &Function, Extected, Input, ...
    // IF
    cout << "Testing IF stage: " << endl;
    // ID
    cout << endl << "Testing ID stage: " << endl;
    test_single_input("Control Unit", &controlUnit, "0000000100", extend_reverse("00001"));
    test_double_input("Instructon Type", &instructionType, "XOR", extend("100110"), "1001000010");

    // EXE
    cout << endl << "Testing EXE stage: " << endl;
    test_single_input("Left Shift 2", &left_shift_2, extend("100000"), extend("1000"));
    test_double_input("ALU Add", &alu_add, extend("10"), extend("1"), extend("1"));
    test_double_input("ALU Sub", &alu_sub, extend("1"), extend("10"), extend("1"));
    test_double_input("ALU And", &alu_and, "00000000000000000000000000000001", "00000000000000000000000000000001", "00000000000000000000000000000001");
    test_double_input("ALU Or", &alu_or, "00000000000000000000000000000001", "00000000000000000000000000000000", "00000000000000000000000000000001");
    test_double_input("ALU Slt", &alu_slt, "00000000000000000000000000000001", "00000000000000000000000000000001", "00000000000000000000000000000001");
    test_double_input("ALU Control", &alu_control, "00000000000000000000000000000001", "00000000000000000000000000000010", "00000000000000000000000000000001");
    test_double_input("And Gate", &and_gate, "00000000000000000000000000000001", "00000000000000000000000000000010", "00000000000000000000000000000001");
    
    // MEM
    cout << endl << "Testing MEM stage: " << endl;
    // WB
    cout << endl << "Testing WB stage: " << endl;
}



