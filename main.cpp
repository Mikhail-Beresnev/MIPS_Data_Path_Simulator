#include <iostream>
#include <string>
#include <map>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./ID/id.h"
//#include "./IF/if.h"

using namespace std;

string registers[32] = {"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};
/**  Registers(all prefixed w/ $): zero (always 0), at (reserved for assembler), v0-v1 (return), a0-a3 (arguments), t0-t7 (temp), 
*    s0-s7 (save regs), t8-t9 (temp), k0-k1 (kernel), gp (global pointer), sp (stack pointer), fp (frame pointer), ra (return address)
**/
int rsIndex;
int rtIndex;
int rdIndex;
string addressOrImmediate;

int main() {
    cout << "test" << endl;

    string input = "00100001000000111000000000001111";
    idStage(input);

    return 0;
}