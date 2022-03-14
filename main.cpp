#include <iostream>
#include <string>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./ID/id.h"
#include "./IF/if.h"
#include "./UI/ui.h"
#include "./helpful/helpful.h"
#include "./tests/test.h"

using namespace std;

string registers[][32] = {
{"$0","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"},
{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"}
};

/**  Registers(all prefixed w/ $): zero (always 0), at (reserved for assembler), v0-v1 (return), a0-a3 (arguments), t0-t7 (temp), 
*    s0-s7 (save regs), t8-t9 (temp), k0-k1 (kernel), gp (global pointer), sp (stack pointer), fp (frame pointer), ra (return address)
**/

void run(string input);

string userInstruction;
int rsIndex;
int rtIndex;
int rdIndex;
string addressOrImmediate = "000000";
string program_counter = extend("0"); // 4 bits

int main() {
    string input;
    // testAll();
    
    // input = userInput();
    run("00000000101001100011100000100000");
    return 0;
}

void run(string input) {
    // IF
    program_counter  = alu_add(program_counter, extend("100"));

    // ID

    string controlSignals = controlUnit(input);
    registerFile(input, controlSignals);
    string instructionCall = instructionType(input, controlSignals);
    signExtend();
    

    // EXE

    string o_alu_control = alu_control(controlSignals, input.substr(26,6));
    string o_m_mux = Mux(registers[1][rtIndex], addressOrImmediate, char_to_string(controlSignals.at(1)));
    string o_alu = alu(registers[1][rsIndex], o_m_mux, o_alu_control);

    string o_shift_left_2 = left_shift_2(addressOrImmediate);
    string o_add_alu = alu_add(o_shift_left_2, program_counter);

    string o_and_gate = and_gate(controlSignals.at(6), controlSignals.at(9));
    string o_u_mux = Mux(program_counter, o_add_alu, o_and_gate);
    
    // MEM
    string o_data_memory = data_memory(registers[1][rtIndex], o_alu, char_to_string(controlSignals.at(5)),char_to_string(controlSignals.at(4)));
    string o_l_mux = Mux(o_alu, o_data_memory, char_to_string(controlSignals.at(5)));
    // WB
    program_counter = o_u_mux;

}
