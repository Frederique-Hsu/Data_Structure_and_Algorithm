#include "testing.h"
#include "function_template.h"
#include "class_template.h"
#include "Screen.h"
#include "../Utility_Classes_Libraries/Sales_Item/Sales_item.h"

#include <iostream>
#include <string>
using namespace std;

void execute_test_cases()
{
    // instantiate_function_templates();
    // instantiate_class_templates();
    access_template_members();
}

void instantiate_function_templates()
{
    short si = 56;
#if 0
    /* Error: cannot instantiate compare(short, int)
     * must be compare(short, short) or compare(int, int)
     */
    compare(si, 1024);
#endif
    cout << compare(1, 0) << endl;

    string s1 = "hi", s2 = "world";
    cout << compare(s1, s2) << endl;

    int frequencies[42];
    array_init(frequencies);    /* instantiate array_init(int(&)[42]) */
    double loss_in_dB[10];
    array_init(loss_in_dB);     /* instantiate array_init(double(&)[10]) */

    /*
    Sales_item item1, item2;
    cout << compare(item1, item2) << endl;  // Error: no operator< inside Sales_item
     */
#if 0
    /* Error: cannot find the specific instantiation of
     * int* compare(const int&, const int&)
     *
    fnct(compare);
     */
    fnct(compare<int>);     /* MUST explicitly specify which version of compare */
#endif
    int i = 89;
    long lng = 5604L;
    /* OK: T1 explicitly specified;
     *     T2 and T3 inferred from argument types.
     */
    long value = sum<long>(i, lng);
    cout << value << endl;

    /* MUST explicitly specify the 3 arguments type respectively */
    long val = alternative_sum<int, short, long>(si, i);
    cout << val << endl;
}

void instantiate_class_templates()
{
    Queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    cout << "The front element of queue is: " << que.front() << endl;
    cout << que << endl;

    que.push(88);
    que.pop();
    cout << "The front element of queue is: " << que.front() << endl;
    cout << que << endl;

    cin >> que;
    cout << que << endl;

    Screen<24, 80> hp2621;
}

void access_template_members()
{
    unsigned fibonacci[20];
    generate_fibonacci(fibonacci);

    Queue<unsigned long long> fib_queue(fibonacci, fibonacci+8);
    cout << fib_queue << endl;

    vector<size_t> fib_vec;
    generate_fibonacci<50>(fib_vec);
    fib_queue.assign(fib_vec.begin(), fib_vec.end());
    cout << fib_queue << endl;
}
