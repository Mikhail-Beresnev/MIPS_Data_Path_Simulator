#include <iostream>
#include <string>
#include <map>
// #include "FILENAME.H"
#include "./EXE/exe.h"
#include "./MEM/mem.h"
#include "./ID/id.h"
#include "./IF/if.h"
#include "./UI/ui.h"
#include "./helpful/helpful.h"
#include "./tests/test.h"

using namespace std;

string registers[][32] = {
{"$0","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2",
"$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"},
{extend("0"),extend("0"),extend("0"),extend("0"),extend("101111"),extend("10"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),
extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),
extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0"),extend("0")},
{extend(int_to_binary(0)), extend(int_to_binary(4)), extend(int_to_binary(8)), extend(int_to_binary(12)), extend(int_to_binary(16)),
 extend(int_to_binary(20)), extend(int_to_binary(24)), extend(int_to_binary(28)), extend(int_to_binary(32)), extend(int_to_binary(36)), 
 extend(int_to_binary(40)), extend(int_to_binary(44)), extend(int_to_binary(48)), extend(int_to_binary(52)), extend(int_to_binary(56)), 
 extend(int_to_binary(60)), extend(int_to_binary(64)), extend(int_to_binary(68)), extend(int_to_binary(72)), extend(int_to_binary(76)), 
 extend(int_to_binary(80)), extend(int_to_binary(84)), extend(int_to_binary(88)), extend(int_to_binary(92)), extend(int_to_binary(96)), 
 extend(int_to_binary(100)), extend(int_to_binary(104)), extend(int_to_binary(108)), extend(int_to_binary(112)), extend(int_to_binary(116)), 
 extend(int_to_binary(120)), extend(int_to_binary(124))}
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
string program_counter = extend("0"); // 32 bits
map<string, string> data;

int main() {
    string input;
    // testAll();
    char again = 'y';
    while (again == 'y'){
        input = userInput();
        run(input);
        cout << endl << "Would you like to input another instruction? (y/n)" << endl;
        cin >> again;
    }

    // op, rs, rt, immediate


    /*
    //op, rs, rt, rd, funct
    // 0, 5, 4, 6, add
    // "000000'00101'00100'00110'00000'100000" - add
    run("00000000101001000011000000100000");
    */

    /*
    //op, rs, rt, immediate
    // addi, 5, 4, immediate
    // "001000'00101'00100'00000'00000'001000" - addi
    run("00100000101001000000000000001000");
    */

    /*
    //op, rs, rt, rd, funct
    // 0, 5, 4, 6, add
    // "000000'00101'00100'00110'00000'100010" - sub
    run("00000000101001000011000000100010");
    */

    /* 
    // op, rs, rt, immediate
    // "101011'00101'00110'00000'00000'000000" - store word
    // "100011'00101'00110'00000'00000'000000" - load word
    // store, 5, 6, 0
    // load, 5, 6, 0
    run("10101100101001100000000000000000");
    run("10001100101001100000000000000000");
    */

    /*
    //op, rs, rt, rd, funct
    // 0, 5, 4, 6, and
    // "000000'00101'00100'00110'00000'100100" - and
    run("00000000101001000011000000100100");
    */

    /* 
    //op, rs, rt, rd, funct
    // 0, 5, 4, 6, or
    // "000000'00101'00100'00110'00000'100101" - or
    run("00000000101001000011000000100101");
    */




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
    print("alu control: " + o_alu_control);
    string o_m_mux = Mux(registers[1][rtIndex], addressOrImmediate, char_to_string(controlSignals.at(1)));
    print("middle mux: " + o_m_mux);
    // determine if we are adding a data or an address
    string o_alu = alu(registers[determine_add_type(input.substr(0,6))][rsIndex], o_m_mux, o_alu_control);
    print("alu: " + o_alu);

    string o_shift_left_2 = left_shift_2(addressOrImmediate);
    print("shift left 2: " + o_shift_left_2);
    string o_add_alu = alu_add(o_shift_left_2, program_counter);
    print("add alu: " + o_add_alu);

    string o_and_gate = and_gate(controlSignals.at(6), controlSignals.at(9));
    print("and gate: " + o_and_gate);
    string o_u_mux = Mux(program_counter, o_add_alu, o_and_gate);
    print("upper mux: " + o_u_mux);
    
    // MEM
    string o_data_memory = data_memory(registers[1][rtIndex], o_alu, char_to_string(controlSignals.at(5)),char_to_string(controlSignals.at(4)));
    print("data memory: " + o_data_memory);
    string o_r_mux = Mux(o_alu, o_data_memory, char_to_string(controlSignals.at(2)));
    print("right mux: " + o_r_mux);
    // WB
    program_counter = o_u_mux;
    print("program counter: " + program_counter);
    print("data: " + o_r_mux);
    // print("data: " + data[extend("10100")]);
}
