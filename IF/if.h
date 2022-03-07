#ifndef IF
#define IF

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

string instruction;

string PC(); // Asks the User to Input an Instruction in Binary Format
string intructionMemory(string input);
string Adder(string inputA, string inputB);
string Mux(string input);

#endif

