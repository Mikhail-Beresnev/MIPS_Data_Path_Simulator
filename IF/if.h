#ifndef IF
#define IF

#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

string binaryInput(); // Asks the User to Input an Instruction in Binary Format
string intructionMemory(string input);
string Adder(string inputA, string inputB);
string Mux(string input00, string input01, string controlSignal);

#endif

