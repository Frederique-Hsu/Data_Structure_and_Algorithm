/*******************************************************************************
 * File name     : Polymorphism.h
 * Description   : Demonstrate the Polymorphism feature in C++ programming.
 * Creator       : Frederick Hsu
 * Creation date : Sat.  05 March, 2016
 * Copyright(C)  2016  All rights reserved.
 * 
 *******************************************************************************/

#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H

class Class1
{
private:
public:
    virtual void f(void);
    void g(void);
};

class Class2
{
private:
public:
    virtual void f(void);
    void g(void);
};

class Class3
{
private:
public:
    virtual void h(void);
};

#endif  /* POLYMORPHISM  */