#include "helpful.h"

string add_binary(string input_1, string input_2) {
    unsigned long x = bitset<32>(input_1).to_ulong();
    unsigned long y = bitset<32>(input_2).to_ulong();

    unsigned long result = x + y;

    string output = bitset<32>(result).to_string();

    return output;
}


string sub_binary(string input_1, string input_2) {

    unsigned long x = bitset<32>(input_1).to_ulong();
    unsigned long y = bitset<32>(input_2).to_ulong();

    unsigned long result = x - y;

    string output = bitset<32>(result).to_string();

    return output;
}

unsigned long binary_to_int(string input) {
    return bitset<32>(input).to_ulong();
}

string int_to_binary(unsigned long input) {
    return bitset<32>(input).to_string();
}

string extract_bits(string input, int start, int end) {
    string bits;
    return input.substr(start, end-start);
}

string extend(string input) {
    while (input.size() != 32) {
        input = "0" + input;
    }
    return input;
}

string extend_reverse(string input) {
    while (input.size() != 32) {
        input = input + "0";
    }
    return input;
}
