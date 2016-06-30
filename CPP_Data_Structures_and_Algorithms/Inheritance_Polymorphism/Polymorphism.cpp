/*******************************************************************************
 * File name   : Polymorphism.cpp
 * Description : Implement the polymorphism classes.
 * Creator       : Frederick Hsu
 * Creation date : Sat.  05 March, 2016
 * Copyright(C)  2016 All rights reserved.
 * 
 *******************************************************************************/


#include "Polymorphism.h"
#include <iostream>

void Class1::f(void)
{
    std::cout<<"Function f() in Class1."<<std::endl;
    return;
}

void Class1::g(void)
{
    std::cout<<"Function g() in Class1"<<std::endl;
    return;
}

void Class2::f(void)
{
    std::cout<<"Function f() in Class2"<<std::endl;
    return;
}

void Class2::g(void)
{
    std::cout<<"Function g() in Class2"<<std::endl;
    return;
}

void Class3::h(void)
{
    std::cout<<"Function h() in Class3"<<std::endl;
    return;
}