/*!
 *  \file       alternative_print.c
 *  \brief      
 *  
 */


#include "alternative_print.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

FooBar* createFooBar(int n)
{
    FooBar* obj = (FooBar*)malloc(sizeof(FooBar));

    obj->n = n;
    return obj;
}

void freeFooBar(FooBar* obj)
{
    free(obj);
}


sem_t semaphore;

enum Flag
{
    None = 0,
    Foo_Busy,
    Foo_Free,
    Bar_Busy,
    Bar_Free
};

enum Flag flag = Bar_Free;

// #define BY_VIRTUE_OF_FLAG

void foo(FooBar* obj)
{
#if 0
    int i = 0;
    while (i < obj->n)
    {
        if (flag == Bar_Free)
        {
            printFoo();
            flag = Foo_Free;
            i++;
        }
    }
#else
    for (int i = 0; i < obj->n; ++i)
    {
        if (sem_post(&semaphore) == 0)
        {
            #if defined (BY_VIRTUE_OF_FLAG)
            if (flag == Bar_Free)
            { 
                printFoo();
                flag = Foo_Free;
            }
            #else
            printFoo();
            #endif
        }
    }
#endif
}

void bar(FooBar* obj)
{
#if 0
    int i = 0;
    while (i < obj->n)
    {
        if (flag == Foo_Free)
        {
            printBar();
            flag = Bar_Free;
            i++;
        }
    }
#else
    for (int i = 0; i < obj->n; ++i)
    {
        if (sem_wait(&semaphore) == 0)
        {
            #if defined (BY_VIRTUE_OF_FLAG)
            if (flag == Foo_Free)
            {
                printBar();
                flag = Bar_Free;
            }
            #else
            printBar();
            #endif
        }
    }
#endif
}

void printFooBarAlternative(FooBar* obj)
{
    int i = 0;
    for (i = 0; i < (obj->n / 2); ++i)
    {
        if (sem_wait(&semaphore) == 0)
        {
            printFoo();
        }
        if (sem_post(&semaphore) == 0)
        {
            printBar();
        }
    }
}