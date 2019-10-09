/**************************************************************************************************
 * Project      : Multi_Threads
 * Description  : Delve the multi-threads subject of standard C++ 11 in-depth
 * Creator      : Frederique Hsu
 * Creation date: Thu.  10 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>

using namespace std;

void myprint();

int main(int argc, char* argv[])
{
    thread myth(myprint);
    myth.join();

    cout << "This is the main thread running..." << endl;
    getchar();
    return 0;
}

void myprint()
{
    cout << "my thread starts now." << endl;

    cout << "my thread ends here." << endl;
}
