#include "if.h"

//  Asks the User to Input an Instruction in Binary Format and checks if it is binary
string binaryInput() {
    bool binary = true; // flag if number is not binary
    int n = 1;
    string instruction;
    do{
        // string instruction;
        cout << "Enter an Intruction in 32-bit binary format: ";
        cin >> instruction; 
        n = instruction.length();
        // const int n = 0;
        char x[n];
        // copying the contents of the string to char array
        strcpy(x, instruction.c_str());
 
        for (int i = 0; i < n; i++){
            if(x[i] != '0' && x[i] != '1'){
            binary = false;
            }   
        }   
        if (n != 32){
          cout << "NOT 32 BITS!" << endl;
        }
        if (binary == false){
          cout << "NOT BINARY!" << endl;
        }
    } while((n != 32) || (binary == false));
    return instruction;
}
string intructionMemory(string input){
string a,b,c,d,e,f;
// instruction Memory function already in the ID section, 
// no point of having one except to maybe display text that this block has been used
return "0"; // TEMPORARY SO NO COMPILE ERRORS
}

string Adder(string inputA, string inputB){
// AluAdd function already in the ID section, they perform similar task,
// we could use that function inside this one and replace a varible for the constant 4,
// no point of having one except to maybe display text that this block has been used
return "0"; // TEMPORARY SO NO COMPILE ERRORS
}



string Mux(string input00, string input01, string controlSignal){
  if(controlSignal == "0"){
return input00;
  }
 else { 
return input01;
  }

}