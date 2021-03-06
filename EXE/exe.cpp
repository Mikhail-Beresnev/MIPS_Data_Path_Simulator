#include "exe.h"

string left_shift_2(string input) {
    // input is 32 bits
    return input.substr(2, 30) + "00";
} 

string alu(string input_1, string input_2, string control) {
    string output;
    if (control == "010") {
        // add
        output = alu_add(input_1, input_2);
    } else if (control == "110") {
        // sub
        output = alu_sub(input_1, input_2);
    } else if (control == "000") {
        // and
        output = alu_and(input_1, input_2);
    } else if (control == "001") {
        // or
        output = alu_or(input_1, input_2);
    } else if (control == "111") {
        // slt
        output = alu_slt(input_1, input_2);
    } else if (control == "100") {
        output = alu_mult(input_1, input_2);
    } else if (control == "101") {
        output = alu_div(input_1, input_2);
    }
    return output;
}

string alu_add(string input_1, string input_2) {
    return add_binary(input_1, input_2);
}

string alu_sub(string input_1, string input_2) {
    return sub_binary(input_1, input_2);
}

string alu_mult(string input_1, string input_2) {
    return mult_binary(input_1, input_2);
}

string alu_div(string input_1, string input_2) {
    return div_binary(input_1, input_2);
}

string alu_and(string input_1, string input_2) {
    string output = "";
    for (int i = 0; i < input_1.length(); i++) {
        if (input_1.at(i) == '1' && input_2.at(i) == '1') {
            output.append("1");
        } else {
            output.append("0");
        }
    }
    return output;
}

string alu_or(string input_1, string input_2) {
    string output = "";
    for (int i = 0; i < input_1.length(); i++) {
        if (input_1.at(i) == '1' || input_2.at(i) == '1') {
            output.append("1");
        } else {
            output.append("0");
        }
    }
    return output;
}

string alu_slt(string input_1, string input_2) {
    unsigned long x = binary_to_int(input_1);
    unsigned long y = binary_to_int(input_2);
    
    if (x < y) {
        return int_to_binary(1);
    } else {
        return int_to_binary(0);
    }
}

string alu_control(string aluop, string funct) {
    aluop = aluop.substr(8,2);
    // load/store word
    if (aluop == "00") {
        return "010"; //add
    }
    // branch equal
    if (aluop == "01") {
        return "110"; //sub
    }
    if (aluop.at(0) == '1') {
        if (funct == "011000" && aluop.at(1) == '0') {
            return "100"; // multiply
        }
        if (funct == "011010" && aluop.at(1) == '0') {
            return "101"; // divide
        }

        funct = funct.substr(2, 4);
        //certain 0's
        if (funct == "0000" && aluop.at(1) == '0') {
            return "010"; //add
        }
        if (funct == "0100" && aluop.at(1) == '0') {
            return "000"; //and
        }
        if (funct == "0101" && aluop.at(1) == '0') {
            return "001"; //or
        }

        // unknown
        if (funct == "0010") {
            return "110"; // subtract
        }
        if (funct == "1010") {
            return "111"; // set on less than
        }
    }

    return "ERROR";
}

string and_gate(char input_1, char input_2) {
    string output = "";
    if (input_1 == '1' && input_2 == '1') {
        output = '1';
    } else {
        output = '0';
    }
    return output;
}

int determine_add_type(string input) {
    if (input == "100011" || input == "101011") {
        return 2;
    } else {
        return 1;
    }
}


// multiply, divide
// mult: 011000, 10
// div: 011010, 10
// xor: 100110

// 
