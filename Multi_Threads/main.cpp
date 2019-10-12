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
    cout << "This is the main thread running..." << endl;

    thread myth(myprint);
    if (myth.joinable())
    {
        cout << "1:joinable() == true" << endl;
    }
    else
    {
        cout << "1:joinable() == false" << endl;
    }
    // myth.join();
    myth.detach();
    if (myth.joinable())
    {
        cout << "1:joinable() == true" << endl;
    }
    else
    {
        cout << "1:joinable() == false" << endl;
    }

    cout << "main thread goes step 1" << endl;
    cout << "main thread goes step 2" << endl;
    cout << "main thread goes step 3" << endl;
    cout << "main thread goes step 4" << endl;
    cout << "main thread goes step 5" << endl;

    cout << "Main thread quits safely." << endl;
    // getchar();
    return 0;
}

void myprint()
{
    cout << "my thread starts now." << endl;

    cout << "running step 1" << endl;
    cout << "running step 2" << endl;
    cout << "running step 3" << endl;
    cout << "running step 4" << endl;
    cout << "running step 5" << endl;
    cout << "running step 6" << endl;
    cout << "running step 7" << endl;
    cout << "running step 8" << endl;
    cout << "running step 9" << endl;
    cout << "running step 10" << endl;

    cout << "my thread ends here." << endl;
}
