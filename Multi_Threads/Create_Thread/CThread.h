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
        void operator()(int number);
    private:
        int m_i;
    };

    class TestThread
    {
        friend void modify_ref_object(TestThread& thd);
    public:
        explicit TestThread(int value);
        TestThread(const TestThread& orig);
        TestThread& operator=(const TestThread& orig);
        ~TestThread();
    private:
        int m_value;
    public:
        void work(int num);
    };

    void mytest(const int i, const TestThread& thd);
    void display_thread_id(const TestThread& thd);
    void modify_ref_object(TestThread& thd);
    void pass_smart_ptr(unique_ptr<int> upi);

#endif  /* CTHREAD_H */
