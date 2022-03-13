#ifndef UI
#define UI

#include <iostream>
#include <string>
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
string regPrompts(string opCode);
void rinstructionPrompts(int rd, int rs, int rt);
void addiInstructionPrompts(int rt, int rs, string immediate);
void lswInstructionPrompts(int rt, string offset, int rs, string opCode);
void branchInstructionPrompts(int rs, int rt, string label);
void jumpInstructionPrompts();

#endif