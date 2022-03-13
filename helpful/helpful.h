#ifndef HELPFUL
#define HELPFUL

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string add_binary(string input_1, string input_2);

string sub_binary(string input_1, string input_2);

unsigned long binary_to_int(string input);

string int_to_binary(unsigned long input);

string extract_bits(string input, int start, int end);

string extend(string input);

string extend_reverse(string input);

#endif