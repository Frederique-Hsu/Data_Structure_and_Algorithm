/*!
 *  \file       foo_bar.cpp
 *  \brief      
 *  
 */


#include "foo_bar.hpp"


FooBar::FooBar(int n)
{
    this->n = n;
    flag = Flag::Bfree;
}

void FooBar::foo(std::function<void()> printFoo)
{
    int i = 0;
    while (i < n)
    {
        if (flag == Flag::Bfree)
        {
            printFoo();
            flag = Flag::Afree;
            i++;
        }
    }
}

void FooBar::bar(std::function<void()> printBar)
{
    int i = 0;
    while (i < n)
    {
        if (flag == Flag::Afree)
        {
            printBar();
            flag = Flag::Bfree;
            i++;
        }
    }
}