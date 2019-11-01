/**************************************************************************************************
 * Project      : Pass_Arguments_To_Threads
 * Description  : Study how to pass arguments to the thread callback functions.
 * ================================================================================================
 * File name    : Main.cpp
 * Description  : This file will implement the main() entry function for current project.
 * Creator      : Frederick Hsu
 * Creation date: Sat.  02 Nov. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>
#include <thread>
#include <string>

using namespace std;

#if 0
    void threadCallBack(int x, string str)
    {
        cout << "Passed number x = " << x << endl;
        cout << "Passed string str = " << str << endl;
    }
    /* Passing simple arguments to a std::thread in C++11
     * By default, all arguments are copied into the internal storage of new thread.
     */
    int main(int argc, char* argv[])
    {
        int number = 10;
        string mesg = "Sample string";

        std::thread thrdObj(threadCallBack, number, mesg);
        thrdObj.join();

        return 0;
    }
#elif 1
    /* Do not pass addresses of variables from local stack to thread's callback function.
     * Because it might be possible that local variable in main thread goes out of scope,
     * but the child thread is still trying to access it through its address.
     * In such scenario accessing invalid addresses can cause unexpected behaviour.
     */
    void newThreadCallback(int* ptr)
    {
        cout << "Inside thread: "" : ptr = " << ptr << endl;
        std::chrono::milliseconds dura(1000);
        std::this_thread::sleep_for(dura);
        *ptr = 2019;
    }

    void startNewThread()
    {
        int i = 10;
        cout << "Inside main thread : "" : i = " << i << endl;
        std::thread childThread(newThreadCallback, &i);
        childThread.detach();

        cout << "Inside main thread : "" : i = " << i << endl;
    }

    int main(int argc, char* argv[])
    {
        startNewThread();
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        return 0;
    }
#endif
