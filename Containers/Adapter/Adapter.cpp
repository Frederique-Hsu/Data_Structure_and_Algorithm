#include "Adapter.h"

#include <iostream>
#include <stack>        /* stack adapter */
#include <queue>        /* both queue and priority_queue adapters */
#include <vector>

#include <cmath>

using namespace std;

void execute_test_cases(void)
{
    // initialize_adapters();
    access_stack_adapters();
}

void initialize_adapters(void)
{
    deque<int> deq;
    for (int idx = 0; idx <= 10; ++idx)
    {
        deq.push_back(pow<int>(idx, 3));
    }
    for (deque<int>::const_iterator cit = deq.begin(); cit != deq.end(); ++cit)
    {
        cout << *cit << endl;
    }
    string companies[] = { "Apple", "Intel", "Huawei", "Google", "Facebook", "Lenovo", "Chanel", "Qualcomm",
        "Amazon", "Ferrari", "Microsoft", "Alibaba", "BMW", "Sony", "Tencent" };
    vector<string> svec(companies, companies+15);

    stack<int> stk(deq);    /* copy elements from deq into stk */

    /* empty stack, implemented on top of vector */
    stack< string, vector<string> > str_stk;
    /* str_stk2 is implemented on top of vector and holds a copy of svec. */
    stack< string, vector<string> > str_stk2(svec);
}

void access_stack_adapters(void)
{
    /* number of elements we will put in our stack */
    const stack<int>::size_type stk_size = 10;
    stack<int> intStack;    /* empty stack */
    /* fill up the stack */
    int idx = 0;
    while (intStack.size() != stk_size)
    {
        /* use postfix increment; want to push old value onto intStack */
        intStack.push(idx++);       /* intStack holds 0...9 inclusive */
    }
    int error_cnt = 0;
    /* look at each value and pop it off the stack */
    while (intStack.empty() == false)
    {
        int value = intStack.top();     /* read the top element of the stack */
        if (value != --idx)
        {
            cerr << "Ooops! expected " << idx << " received " << value << endl;
            ++error_cnt;
        }
        intStack.pop();     /* pop the top element, and repeat */
    }
    cout << "Our program ran with " << error_cnt << " errors!" << endl;
}