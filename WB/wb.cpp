#include "wb.h"

void writeback(string Instruction, string returnedValue){
string controlSignal, finalRegister;

controlSignal = controlUnit(Instruction);
if(controlSignal == "1001000010"){
registers[1][rdIndex] = returnedValue;
}
else if(controlSignal == "0101000000" || controlSignal == "0111100000"){
registers[1][rtIndex] = returnedValue;
}
}