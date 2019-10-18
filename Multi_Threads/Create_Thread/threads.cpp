#include "threads.h"
#include <iostream>
using namespace std;

void myprint(const int& i, char* pbuf)  // NOT RECOMMEND to use reference and pointer.
{
    cout << i << endl;
    cout << pbuf << endl;
    return;
}

void myprint(const int i, const string& pbuf)
{
    cout << i << endl;
    cout << pbuf << endl;
}
