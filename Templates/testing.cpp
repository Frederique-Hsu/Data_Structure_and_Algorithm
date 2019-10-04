#include "testing.h"
#include "function_template.h"

#include <iostream>
#include <string>
using namespace std;

void execute_test_cases()
{
    instantiate_function_templates();
}

void instantiate_function_templates()
{
    cout << compare(1, 0) << endl;

    string s1 = "hi", s2 = "world";
    cout << compare(s1, s2) << endl;

    int frequencies[42];
    array_init(frequencies);    /* instantiate array_init(int(&)[42]) */
    double loss_in_dB[10];
    array_init(loss_in_dB);     /* instantiate array_init(double(&)[10]) */
}