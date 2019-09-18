#include "testing.h"
#include "Function_Prototype.h"

void execute_test_cases(void)
{
    invoke_functions();
}

#include <iostream>

using namespace std;

void invoke_functions(void)
{
    cout << "Enter two values: \n";
    int i, j;
    cin >> i >> j;
    /* call gcd on arguments i and j, and print their greatest common divisor */
    cout << "gcd: " << gcd(i, j) << endl;

    int *p = &i;
    cout << "i: " << *p << '\n';
    reset(p);   /* changed *p but not p */
    cout << "i: " << *p << endl;

    cout << "Before swap(): \ti: " << i << "\tj: " << j << endl;
#if !defined (REFERENCE_PARAMETERS)
    swap(i, j);
#else
#endif
    cout << "After swap(): \ti: " << i << "\tj: " << j << endl;
}
