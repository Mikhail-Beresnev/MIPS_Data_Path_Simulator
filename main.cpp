#include <iostream>
#include <string>
#include <map>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./ID/id.h"
//#include "./IF/if.h"

using namespace std;

<<<<<<< HEAD
int registers[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/**  Registers(all prefixed w/ $): zero (always 0), at (reserved for assembler), v0-v1 (return), a0-a3 (arguments), t0-t7 (temp), 
*    s0-s7 (save regs), t8-t9 (temp), k0-k1 (kernel), gp (global pointer), sp (stack pointer), fp (frame pointer), ra (return address)
**/
int rsIndex;
int rtIndex;
int rdIndex;
int address;
=======
int data_mem[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
map<string, string> data_memory;
// string controlUnit(string input);
>>>>>>> 89bd8fbfbc4233666652eec48a38f6056fa5f171

int main() {
    cout << "test" << endl;
    // cout << controlUnit("00000000000000000000000000000100") << endl; // test BEQ
    // cout << controlUnit("00000000000000000000000000000101") << endl; // test BNE
    // cout << controlUnit("00000000000000000000000000100011") << endl; // test LW
    // cout << controlUnit("00000000000000000000000000101011") << endl; // test SW
    // cout << controlUnit("00000000000000000000000000001000") << endl; // test ADDI
    // cout << controlUnit("00000000000000000000000000000010") << endl; // test J
    // cout << controlUnit("00000000000000000000000000000000") << endl; // test ALL R-TYPE
    // cout << rreturnReg("00000000000000000010100000000000") << endl;  // rd test
    registerFile("00000011100001000010100000000000","1001000010");
    cout << "rs Index: " << rsIndex << ", rt Index: " << rtIndex << ", rd Index: " << rdIndex << endl;
    cout << "r instruction: " << rInstruction("00000000000000000010100000000000") << endl;
    return 0;
}