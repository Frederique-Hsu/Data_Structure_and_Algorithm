/*!
 *  \file       alternative_print.cpp
 *  \brief      交替打印FooBar
 *  
 */


#include <gtest/gtest.h>

#include "foo_bar.hpp"

#include <iostream>
#include <thread>

/*!
 *  \details
 *  
 *  给你一个类：
 *
 *  class FooBar {
 *    public void foo() {
 *      for (int i = 0; i < n; i++) {
 *        print("foo");
 *      }
 *    }
 *  
 *    public void bar() {
 *      for (int i = 0; i < n; i++) {
 *        print("bar");
 *      }
 *    }
 *  }
 *  两个不同的线程将会共用一个 FooBar 实例：
 *  
 *  线程 A 将会调用 foo() 方法，而
 *  线程 B 将会调用 bar() 方法
 *  请设计修改程序，以确保 "foobar" 被输出 n 次。
 *  
 *   
 *  
 *  示例 1：
 *  
 *  输入：n = 1
 *  输出："foobar"
 *  解释：这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
 *  示例 2：
 *  
 *  输入：n = 2
 *  输出："foobarfoobar"
 *  解释："foobar" 将被输出两次。
 * 
 * 
 */

 
void printFoo()
{
    std::cout << "foo" << std::endl;
}

void printBar()
{
    std::cout << "bar" << std::endl;
}

void printAlternative()
{
    const int CNT = 10;
    FooBar foobarObj(CNT);

    std::thread thdA(&FooBar::foo, &foobarObj, printFoo);
    std::thread thdB(&FooBar::bar, &foobarObj, printBar);

    thdA.join();
    thdB.join();
}


TEST(UTest4AlternativePrint, CheckFunction_printAlternative)
{
    printAlternative();
}