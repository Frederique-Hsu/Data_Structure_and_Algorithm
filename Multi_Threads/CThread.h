#ifndef CTHREAD_H
#define CTHREAD_H

    #include <iostream>
    using namespace std;

    class CThread
    {
    public:
        CThread(int i);
        CThread(const CThread& orig);
        ~CThread();
        void operator()();
    private:
        int m_i;
    };

    class TestThread
    {
    public:
        explicit TestThread(int value);
        TestThread(const TestThread& orig);
        TestThread& operator=(const TestThread& orig);
        ~TestThread();
    private:
        int m_value;
    };

    void mytest(const int i, const TestThread& thd);
    void display_thread_id(const TestThread& thd);

#endif  /* CTHREAD_H */
