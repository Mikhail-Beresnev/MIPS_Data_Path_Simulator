#ifndef MEM
#define MEM

#include <iostream>
#include <string>
#include <map>
#include "../helpful/helpful.h"

using namespace std;

extern map<string, string> dataX;
string data_memory(string write_data, string address, string mem_write, string mem_read);

#endif

