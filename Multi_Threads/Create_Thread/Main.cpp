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

#if defined(CALLABLE_OBJECT)
    thread mythrd(thrd);
#else
    thread mythrd(thrd, 35);
#endif
    mythrd.join();
    // mythrd.detach();
#elif 0
    int myvar = 1;
    int& myvar_ref = myvar;
    char buf[] = "This is a test string";

    thread mythrd(myprint, myvar, string(buf));
    // mythrd.join();
    mythrd.detach();
#elif 0
    int myvar = 1;
    int mypar = 2;
    thread mythrd(mytest, myvar, TestThread(mypar));
    // mythrd.join();
    mythrd.detach();
#elif 0
    cout << "The thread id of current main thread is: " << this_thread::get_id() << endl;
    int myarg = 10;
    thread mythrd(display_thread_id, TestThread(myarg));
    // mythrd.join();
    mythrd.detach();
#elif 0
    cout << "The main thread id = " << this_thread::get_id() << endl;

    int number = 10;
    TestThread sub(number);
    thread mythrd(modify_ref_object, std::ref(sub));  /* pass the class object as argument */
    mythrd.join();
#elif 0
    int number = 100;
    unique_ptr<int> pnum(new int(number));

#if defined(SMART_POINTER_PASSING)
    thread mythrd(pass_smart_ptr, pnum);    /* cannot directly pass smart pointer */
#else
    thread mythrd(pass_smart_ptr, std::move(pnum));
#endif

    mythrd.join();
#else
    cout << "The main thread id = " << this_thread::get_id() << endl;
    TestThread sub(100);

    // thread mythrd(&TestThread::work, std::ref(sub), 150);
    /* &sub and std::ref(sub) are identical
     * won't call the copy constructor.
     */
    thread mythrd(&TestThread::work, &sub, 150);
    mythrd.join();
    /* If the argument object passed into the sub-thread does not call copy constructor,
     * Never use thread.detach().
     * Because the argument object could be revoked when main thread runs out,
     * but the sub-thread is still using this revoked object.
     * It will cause an unexpected disaster.
    mythrd.detach();
     */
#endif

    cout << "The main thread ends." << endl;
    return 0;
}
