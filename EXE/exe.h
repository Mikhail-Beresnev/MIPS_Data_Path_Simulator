#ifndef EXE
#define EXE

#include <iostream>
#include <string>
#include "../helpful/helpful.h"

using namespace std;

string left_shift_2(string input);

string alu(string input_1, string input_2, string contol);

string alu_add(string input_1, string input_2);

string alu_sub(string input_1, string input_2);

string alu_and(string input_1, string input_2);

string alu_or(string input_1, string input_2);

string alu_slt(string input_1, string input_2);

string alu_control(string aluop, string funct);

string and_gate(char input_1, char input_2);

#endif

