#include "Threads_Portal.h"
#include <iostream>

using namespace std;

void task(int number)
{
    cout << "current task number: " << number << endl;
    cout << "start to execute current task.\n" << endl;
}