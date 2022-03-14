#include "test.h"

void testAll() {
    // Format: Function Name, &Function, Extected, Input, ...
    // IF
    cout << endl << "Testing IF stage: " << endl;
    test_triple_input("MUX", &Mux, "input00", "input00", "input01","0");
    // ID
    cout << endl << "Testing ID stage: " << endl;
    test_single_input("Control Unit", &controlUnit, "0000000100", extend_reverse("00001"));
    test_double_input("Instructon Type", &instructionType, "XOR", extend("100110"), "1001000010");

    // EXE
    cout << endl << "Testing EXE stage: " << endl;
    test_single_input("Left Shift 2", &left_shift_2, extend("100000"), extend("1000"));
    test_double_input("ALU Add", &alu_add, extend("10"), extend("1"), extend("1"));
    test_double_input("ALU Sub", &alu_sub, extend("1"), extend("10"), extend("1"));
    test_double_input("ALU And", &alu_and, extend("1"), extend("1"), extend("1"));
    test_double_input("ALU Or", &alu_or, extend("1"), extend("0"), extend("1"));
    test_double_input("ALU Slt", &alu_slt, extend("1"), extend("1"), extend("11"));
    test_double_input("ALU Control", &alu_control,  "110", "0000001001", "000000");
    test_triple_input("ALU", &alu, extend("0"), extend("11"), extend("1"), "111");
    
    // MEM
    // cout << endl << "Testing MEM stage: " << endl;

    // WB
    // cout << endl << "Testing WB stage: " << endl;
}

void test_no_input(string functionName, string (*function)(), string expected){
    string actual = function();
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
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

void test_quadruple_input(string functionName, string (*function)(string, string, string, string), string expected, string input, string input_2, string input_3, string input_4) {
    string actual = function(input, input_2, input_3, input_4);
    cout << functionName << " : ";
    if (expected == actual) {
        cout << "Pass";
    } else {
        cout << "Fail";
    }
    cout << endl;
}
