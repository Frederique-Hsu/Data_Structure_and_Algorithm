/*!
 *  \file       alternative_print.h
 *  \brief      
 *  
 */


#pragma once


typedef struct {
    int n;
} FooBar;


void printFoo();
void printBar();


FooBar* createFooBar(int n);
void foo(FooBar* obj);
void bar(FooBar* obj);
void freeFooBar(FooBar* obj);

void printFooBarAlternative(FooBar* obj);