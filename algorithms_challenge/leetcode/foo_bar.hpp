/*!
 *  \file   foo_bar.hpp
 *  \brief  
 *  
 */


#pragma once

#include <functional>

class FooBar 
{
private:
    int n;

    enum class Flag
    {
        None = 0,
        Abusy,
        Afree,
        Bbusy,
        Bfree
    };

    Flag flag;

public:
    FooBar(int n);

    void foo(std::function<void()> printFoo);

    void bar(std::function<void()> printBar);
};

 