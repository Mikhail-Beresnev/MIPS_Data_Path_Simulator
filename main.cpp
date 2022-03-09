#include <iostream>
#include <string>
#include <map>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./ID/id.h"
//#include "./IF/if.h"

using namespace std;

int data_mem[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
map<string, string> data_memory;
// string controlUnit(string input);

int main() {
    cout << "test" << endl;
    string controlSignals = controlUnit("00000000000000000000000000000101"); // test
    cout << controlSignals;

    return 0;
}