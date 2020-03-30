/**************************************************************************************************
 * Project      : Threads_Batch
 * Description  :
 * ================================================================================================
 * File name    : Main.cpp
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

#include "Threads_Portal.h"

int main(int argc, char argv[])
{
#if 0
    vector<thread> threads_vec;

    for (int index = 0; index < 10; ++index)
    {
        /* create a batch of threads, and they start to run. */
        threads_vec.push_back(thread(task, index));     
    }
    for (auto iter = threads_vec.begin(); iter != threads_vec.end(); ++iter)
    {
        iter->join();   /* wait for the completion of all threads. */
    }
#else
#endif
    cout << "Main thread id = " << this_thread::get_id() << endl;
    cout << "The main thread ends up." << endl;

    // getchar();
    return 0;
}