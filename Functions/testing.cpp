#include "testing.h"
#include "Function_Prototype.h"

void execute_test_cases(void)
{
    invoke_functions();
    utilize_reference_parameters();
}

#include <iostream>
#include <string>
#include <sstream>

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
    swap(i, j);
#endif
    cout << "After swap(): \ti: " << i << "\tj: " << j << endl;

    int *pi = &i;
    int *pj = &j;
    cout << "Before ptrswap(): \t*pi = " << *pi << "\t*pj = " << *pj << endl;
    ptrswap(pi, pj);
    cout << "After  ptrswap(): \t*pi = " << *pi << "\t*pj = " << *pj << endl;
}

void utilize_reference_parameters(void)
{
    string line;
    getline(cin, line);
    istringstream istrstream(line);

    int num;
    vector<int> ivec;
    while (istrstream >> num)
    {
        ivec.push_back(num);
    }

    vector<int>::size_type occurrence_count = 0;
    vector<int>::const_iterator citer = find_val(ivec.begin(), ivec.end(), 42, occurrence_count);
    cout << "We have hunted the number '42' for " << occurrence_count << " times, "
         << "and its first iterator position at " << *citer << endl;
}

void pass_non_const_reference_parameter(void)
{
    short v1 = 0;
    const int v2 = 42;
    int v3; // = incr(v1);     /* error: v1 is not an int */
    // v3 = incr(v2);          /* error: v2 is const */
    // v3 = incr(0);           /* error: literals are not lvalues */
    // v3 = incr(v1 + v2);     /* error: addition doesn't yield an lvalue */
    int v4 = incr(v3);      /* OK: v3 is a non const object type int */
}

void call_function_pointer(void)
{
    cmpFcn pf1 = 0;                 /* OK: unbound pointer to function */
    cmpFcn pf2 = lengthCompare;     /* OK: pointer type matches function's type */
    pf1 = &lengthCompare;           /* OK: pointer type matches function's type */

    cmpFcn pf; // = sumLength;      /* Error: return type differs */
    // pf = cstringCompare;         /* Error: parameter types differ */
    pf = lengthCompare;             /* OK: function and pointer types match exactly */

    lengthCompare("hi", "bye");     /* direct call */
    pf("hi", "bye");                /* equivalent call: pf implicitly dereferenced */
    (*pf)("hi", "bye");             /* equivalent call: pf explicitly dereferenced */
}
