#include "StringContainer.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

void execute_test_cases(void)
{
    access_string_iterator();
}

void access_string_iterator(void)
{
    string s("Hiya");
    string::iterator iter = s.begin();
    while (iter != s.end())
    {
        cout << *iter++ << endl;        /* postfix increment: print old value */
        // cout << *++iter << endl;     /* at this scenario, cannot use prefix */
    }
}