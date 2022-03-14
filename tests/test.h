#ifndef TEST
#define TEST

#include <string>

using namespace std;

void testAll(); // change name to test later
void test_no_input(string functionName, string (*function)(), string expected);
void test_single_input(string functionName, string (*function)(string), string expected, string input);
void test_double_input(string functionName, string (*function)(string, string), string expected, string input, string input_2);
void test_triple_input(string functionName, string (*function)(string, string, string), string expected, string input, string input_2, string input_3);
void test_quadruple_input(string functionName, string (*function)(string, string, string, string), string expected, string input, string input_2, string input_3, string input_4);

#endif
