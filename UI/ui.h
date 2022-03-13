#ifndef UI
#define UI

#include <iostream>
#include <string>
#include <stdlib.h>
#include "../helpful/helpful.h"

using namespace std;

extern int rsIndex;
extern int rtIndex;
extern int rdIndex;
extern string addressOrImmediate;
extern string registers[][32];
extern string userInstruction;

string getOperation();
string generateOpCode(string operation);
string generateFuncCode(string operation);
int getRegIndex();
string getImmediate();
string getAddressOffset();
string getLabel();
string regPrompts(string opCode, string funcCode);
string rinstructionPrompts(string funcCode);
string addiInstructionPrompts();
string lswInstructionPrompts(string opCode);
string branchInstructionPrompts(string opCode);
string jumpInstructionPrompts(string opCode);
string labelToAddress(string label, string opCode);

#endif