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

string getOperation();
string getDestinationReg();
string getStartReg();
string getSecondReg();
string getImmediate();
string getAddress();
string getLabel();
void regPrompts(string operation);

#endif