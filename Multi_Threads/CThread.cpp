#include "CThread.h"

#include <thread>
using namespace std;

CThread::CThread(int i) : m_i(i)
{
    cout << "CThread::CThread() constructor called." << endl;
}

CThread::CThread(const CThread& orig) : m_i(orig.m_i)
{
    cout << "CThread::CThread(const CThread& orig) copy constructor called." << endl;
}

CThread::~CThread()
{
    cout << "CThread::~CThread() destructor called." << endl;
}

void CThread::operator()()
{
#if 0
    cout << "my thread starts to run now." << endl;

    cout << "my thread runs step 1" << endl;

    cout << "my thread ends here." << endl;
#else
    cout << "1) m_i = " << m_i << endl;
    cout << "2) m_i = " << m_i << endl;
    cout << "3) m_i = " << m_i << endl;
    cout << "4) m_i = " << m_i << endl;
    cout << "5) m_i = " << m_i << endl;
    cout << "6) m_i = " << m_i << endl;
#endif
}

TestThread::TestThread(int value) : m_value(value)
{
    cout << "[TestThread::TestThread(int value) constructor called.]" << endl;
    cout << "current pointer = 0x" << this << endl;
    cout << "current thread id = " << std::this_thread::get_id() << "\n" << endl;
}

TestThread::TestThread(const TestThread& orig) : m_value(orig.m_value)
{
    cout << "[TestThread::TestThread(const TestThread& orig) copy constructor called.]" << endl;
    cout << "current pointer = 0x" << this <<  endl;
    cout << "current thread id = " << std::this_thread::get_id() << "\n" << endl;
}

TestThread& TestThread::operator=(const TestThread& orig)
{
    m_value = orig.m_value;
    cout << "[TestThread::operator=(const TestThread& orig) assign construcotr called.]" << endl;
    return *this;
}

TestThread::~TestThread()
{
    cout << "current pointer = 0x" << this << endl;
    cout << "[TestThread::~TestThread() destructor called.]" << endl;
    cout << "current thread id = " << std::this_thread::get_id() << "\n" << endl;
}

void mytest(const int i, const TestThread& thd)
{
    cout << "i = " << i << endl;
    cout << "The address of thd is: 0x" << &thd << "\n" << endl;
}

void display_thread_id(const TestThread& thd)
{
    cout << "In this child-thread, the address of argument object is: " << &thd << endl;
    cout << "The thread id of current child-thread is: " << this_thread::get_id() << endl;
}
