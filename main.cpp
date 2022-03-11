#include <iostream>
#include <string>
#include <map>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./ID/id.h"
//#include "./IF/if.h"
#include "./UI/ui.h"
#include "./helpful/helpful.h"

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
    // int testVal = 5;
    cout << "test" << endl;

    cout << "Register Data: ";
        for (int i = 0; i < 32; i++){
            cout << registers[i];
            if (i != 31){
                cout << ", ";
            } else {
                cout << endl;
            }
        }

    string operation = getOperation();
    // string opCode = generateOpCode(operation);      // NOT PROGRAMMED YET
    // string funcCode = generateFuncCode(operation);  // NOT PROGRAMMED YET
    string rd = getDestinationReg();
    string rs = getStartReg();
    string rt = getSecondReg();
    string immediate = getImmediate();
    string offset = getAddressOffset();
    // string label = getLabel();                       // NOT PROGRAMMED YET
    // regPrompts();                                    // NOT PROGRAMMED YET

    // string binaryTest = int_to_binary(testVal);
    // cout << binaryTest << endl;
    // string input = "00100001000000111000000000001111";
    // idStage(input);


    return 0;
}