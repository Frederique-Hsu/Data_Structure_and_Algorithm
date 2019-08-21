#include "Vector.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Fibonacci.h"

void execute_test_cases(void)
{
    // instantiate_vector_objects();
    // add_element_into_vector();
    access_elements_through_iterator();
}

void instantiate_vector_objects(void)
{
    vector<int> ivec;   /* ivec holds objects of type int */
    vector<string> svec(10, "hi");  /* 10 strings, each initialized to "hi". */
    vector<string>::size_type len = svec.size();
    cout << "There are " << len << " elements in this vector." << endl;
}

void add_element_into_vector(void)
{
    string line;
    vector<string> text;    /* empty vector */
    while (getline(cin, line))
    {
        text.push_back(line);   /* append word to text */
    }
    cout << "The vector text contains : " << endl;
    for (vector<string>::size_type index = 0; index != text.size(); ++index)
    {
        cout << text[index] << endl;
    }
}

void access_elements_through_iterator(void)
{
    unsigned amount = 30;
    vector<unsigned long> fibonacciSeries = Fibonacci::getFibonacciSeries(amount);
    
    unsigned index = 1;
    for (vector<unsigned long>::iterator iter = fibonacciSeries.begin(); 
        iter != fibonacciSeries.end(); 
        ++iter)
    {
        cout << "fib(" << index++ << ") = " << *iter << endl;
    }
}