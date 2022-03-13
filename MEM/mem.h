#ifndef MEM
#define MEM

#include <iostream>
#include <string>
#include <map>
#include "../helpful/helpful.h"

using namespace std;

map<string, string> data;

string data_memory(string write_data, string address, string mem_write, string mem_read);

#endif

