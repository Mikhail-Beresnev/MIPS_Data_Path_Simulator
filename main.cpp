#include <iostream>
#include <string>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./ID/id.h"
//#include "./IF/if.h"
#include "./UI/ui.h"
#include "./helpful/helpful.h"

using namespace std;

string registers[][32] = {
{"$0","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"},
{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"}
};

/**  Registers(all prefixed w/ $): zero (always 0), at (reserved for assembler), v0-v1 (return), a0-a3 (arguments), t0-t7 (temp), 
*    s0-s7 (save regs), t8-t9 (temp), k0-k1 (kernel), gp (global pointer), sp (stack pointer), fp (frame pointer), ra (return address)
**/

string userInstruction;
int rsIndex;
int rtIndex;
int rdIndex;
string addressOrImmediate;

int main() {
    string input;
    string funcCode = "0";
    string operation = getOperation();
    string opCode = generateOpCode(operation);
    if (opCode == "000000"){
        funcCode = generateFuncCode(operation);
    }
    input = regPrompts(opCode, funcCode);
    cout << endl << "Your instruction: " << userInstruction << endl;
    cout << "Binary Form: " << input << endl;
    // string label = getLabel();                       // NOT PROGRAMMED YET
    // regPrompts();                                    // NOT PROGRAMMED YET

    return 0;
}