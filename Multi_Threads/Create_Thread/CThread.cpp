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

void CThread::operator()(int number)
{
    cout << "The sum is: " << m_i + number << endl;
}

TestThread::TestThread(int value) : m_value(value)
{
    cout << "[TestThread::TestThread(int value) constructor called.]" << endl;
    cout << "current pointer = 0x" << this << endl;
    cout << "sub-thread id = " << std::this_thread::get_id() << "\n" << endl;
}

TestThread::TestThread(const TestThread& orig) : m_value(orig.m_value)
{
    cout << "[TestThread::TestThread(const TestThread& orig) copy constructor called.]" << endl;
    cout << "current pointer = 0x" << this << endl;
    cout << "sub-thread id = " << std::this_thread::get_id() << "\n" << endl;
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
    cout << "sub-thread id = " << std::this_thread::get_id() << "\n" << endl;
}

void TestThread::work(int num)
{
    cout << "I am working, the number is: " << num << endl;
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

void modify_ref_object(TestThread& thd)
{
    cout << "Here we want to change the private member, \
to check whether it reflects the original object." << endl;
    thd.m_value = 0xFF;
}

void pass_smart_ptr(unique_ptr<int> upi)
{
    cout << "current smart pointer is: " << *upi << endl;
}