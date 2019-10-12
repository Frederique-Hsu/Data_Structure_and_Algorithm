/**************************************************************************************************
 * File name    : source.cpp
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
using namespace std;

#include "CThread.h"
#include "threads.h"

int main(int argc, char* argv[])
{
#if 0
    int myi = 6;
    CThread thrd(myi);

    thread mythrd(thrd);
    // mythrd.join();
    mythrd.detach();
#elif 0
    int myvar = 1;
    int& myvar_ref = myvar;
    char buf[] = "This is a test string";

    thread mythrd(myprint, myvar, string(buf));
    // mythrd.join();
    mythrd.detach();
#else
    int myvar = 1;
    int mypar = 2;
    thread mythrd(mytest, myvar, TestThread(mypar));
    // mythrd.join();
    mythrd.detach();
#endif

    cout << "The main thread ends." << endl;
    return 0;
}
