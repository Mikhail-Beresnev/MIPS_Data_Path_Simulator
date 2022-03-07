#include "mem.h"

string left_shift_2(string input) {
    // input is 32 bits

    return input.substr(0, 29) + "00";
}