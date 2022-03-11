#include "if.h"

//  Asks the User to Input an Instruction in Binary Format and checks if it is binary
string PC() {
    bool binary; // flag if number is not binary
    do{
        string instruction;
        cout << "Enter an Intruction in 32-bit binary format: ";
        cin >> instruction; 
        // int n = instruction.length();
        const int n = 0;
        char x[n + 1];
        // copying the contents of the string to char array
        strcpy(x, instruction.c_str());
 
        for (int i = 0; i < n; i++){
            if(x[i] != 0 && x[i] != 1){
            binary = false;
            }   
        }   
    } while (true);
    // while(n!=32 || binary = false);
    return "0";
}
string intructionMemory(string input){
string a,b,c,d,e,f;
// instruction Memory function already in the ID section, 
// no point of having one except to maybe display text that this block has been used
}


string Adder(string inputA, string inputB){
// AluAdd function already in the ID section, they perform similar task,
// we could use that function inside this one and replace a varible for the constant 4,
// no point of having one except to maybe display text that this block has been used

}



string Mux(string input00, string input01, string controlSignal){
  if(controlSignal == "1001000010"){
return input00;
  }
 else { 
return input01;
  }

}