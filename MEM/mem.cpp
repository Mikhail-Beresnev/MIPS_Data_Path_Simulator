#include "mem.h"

string left_shift_2(string input) {
    // input is 32 bits
    return input.substr(0, 30) + "00";
} 

string alu_add(string input_1, string input_2) {
    return add_binary(input_1, input_2);
}

string alu_sub(string input_1, string input_2) {
    return sub_binary(input_1, input_2);
}

string alu_and(string input_1, string input_2) {
    string output = "";
    for (int i = 0; i < input_1.length(); i++) {
        if (input_1.at(i) == '1' && input_2.at(i) == '1') {
            output.append('1');
        } else {
            output.append('0');
        }
    }
    return output;
}

string alu_or(string input_1, string input_2) {
    string output = "";
    for (int i = 0; i < input_1.length(); i++) {
        if (input_1.at(i) == '1' || input_2.at(i) == '1') {
            output.append('1');
        } else {
            output.append('0');
        }
    }
    return output;
}

string alu_control(string aluop, string funct) {
    funct = funct.substr(2, 4);
    // load/store word
    if (aluop == "00") {
        return "010"; //add
    }
    // branch equal
    if (aluop == "01") {
        return "110"; //add
    }

    if (aluop.at(0) == '1') {
        //certain 0's
        if (funct == "0000" && aluop.at(0) == '0') {
            return "010"; //add
        }
        if (funct == "0100" && aluop.at(0) == '0') {
            return "000"; //and
        }
        if (funct == "0101" && aluop.at(0) == '0') {
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

    return "0";
}
