/*!
 *  \file       test_alternative_print.c
 *  \brief      
 *  
 */


#include "alternative_print.h"

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include <unity_fixture.h>

void printFoo()
{
    printf("Foo\n");
}

void printBar()
{
    printf("Bar\n");
}


TEST_GROUP(UTester4AlternativePrint);

FooBar* obj = NULL;

extern sem_t semaphore;

TEST_SETUP(UTester4AlternativePrint)
{
    obj = createFooBar(20);

    int success = sem_init(&semaphore, 0, 1);
    if (success == -1)
    {
        printf("sem_init failed.\n");
    }
}

TEST_TEAR_DOWN(UTester4AlternativePrint)
{
    if (sem_destroy(&semaphore) == -1)
    {
        printf("sem_destroy failed.\n");
    }

    freeFooBar(obj);
}

TEST(UTester4AlternativePrint, Check_MultiThreadAlternativePrint)
{
    printf("\n");

    pthread_t thdA, thdB;
    pthread_attr_t thdA_attr, thdB_attr;

    pthread_attr_init(&thdA_attr);
    pthread_attr_init(&thdB_attr);
    pthread_attr_setdetachstate(&thdA_attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&thdB_attr, PTHREAD_CREATE_JOINABLE);

    #if 0
        pthread_create(&thdA, &thdA_attr, (void*)&foo, (FooBar*)obj);
        pthread_create(&thdB, &thdB_attr, (void*)&bar, (FooBar*)obj);
    #else
        pthread_create(&thdA, &thdA_attr, (void*)printFooBarAlternative, obj);
        pthread_create(&thdB, &thdB_attr, (void*)printFooBarAlternative, obj);
    #endif

    sleep(1);
    pthread_join(thdA, NULL);
    pthread_join(thdB, NULL);

    printf("\n");
}

TEST_GROUP_RUNNER(UTester4AlternativePrint)
{
    RUN_TEST_CASE(UTester4AlternativePrint, Check_MultiThreadAlternativePrint);
}