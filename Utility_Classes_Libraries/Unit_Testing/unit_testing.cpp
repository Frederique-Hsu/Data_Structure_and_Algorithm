#include "unit_testing.h"
#include "../Sales_Item/Sales_item.h"

void execute_test_cases(void)
{
    instantiateObjects();
}

#include <iostream>
using namespace std;

void instantiateObjects()
{
    cout << "sizeof(string) = " << sizeof(string("")) << "bytes" << endl;
    cout << "sizeof(unsigned) = " << sizeof(unsigned) << "bytes" << endl;
    cout << "sizeof(double) = " << sizeof(double) << "bytes" << endl;
    cout << "sizeof(void*) = " << sizeof(void*) << "bytes" << endl;
    cout << "sizeof(Sales_item*) = " << sizeof(Sales_item*) << "bytes" << endl;
    Sales_item item;
    cout << "The size of object item: " << sizeof(Sales_item) << "bytes" << endl;
}
