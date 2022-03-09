#ifndef ID
#define ID

//#include "../MEM/mem.h"  // shift left 2 used here again
#include <iostream>
#include <string>

using namespace std;

extern string registers[];
extern int rsIndex;
extern int rtIndex;
extern int rdIndex;
extern int address;

string controlUnit (string input);  // determines control signals from binary input
void registerFile (string input, string controlSignals);    // defines rd, rs, rt from binary input
string rInstruction (string input); // reads func field of r-type instruction to determine operation

#endif
