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

//  Asks the User to Input an Instruction in Binary Format
string intructionMemory(string input){
    return "0";

}

// Asks the User to Input an Instruction in Binary Format
string Adder(string inputA, string inputB){
    return "0";


}

// Asks the User to Input an Instruction in Binary Format
string Mux(string input){
    return "0";

}