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
extern string registers[];

string getOperation();
string generateOpCode(string operation);
string generateFuncCode(string operation);
string getDestinationReg();
string getStartReg();
string getSecondReg();
string getImmediate();
string getAddressOffset();
string getLabel();
void regPrompts(string operation);

#endif