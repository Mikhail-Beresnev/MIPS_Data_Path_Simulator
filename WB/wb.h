#ifndef WB
#define WB

#include <iostream>
#include <cstring>
#include <sstream>
#include "../ID/id.h"

using namespace std;

extern int rtIndex;
extern int rdIndex;
extern string registers[][32];

void writeback(string Instruction, string returnedValue);

#endif
