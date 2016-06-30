/*******************************************************************************
 * File name    : Person.cpp
 * Description  : Define a class Person.
 * Creator      : Frederick Hsu
 * Creation date: Tue.  22 March, 2016
 * Copyright(C) 2016    All rights reserved.
 * 
 *******************************************************************************/

#include "Person.h"
#include <cstring>
#include <cstdlib>

Person::Person(char *n, int a)
{
    name = strdup(n);
    age = a;
}

Person::~Person(void)
{
    std::free(name);
}

bool Person::operator==(const Person& p) const
{
    return ((std::strcmp(name, p.name) == 0) && (age == p.age));
}

bool Person::operator<(const Person& p) const
{
    return (std::strcmp(name, p.name) < 0);
}

bool Person::operator>(const Person& p) const
{
    return (!(*this == p) && !(*this < p));
}

#if 1
    bool lesserAge(const Person& p1, const Person& p2)
    {
        return (p1.age < p2.age);
    }
#endif