/*****************************************************************************************************
 * File name        : Test_Queue.c
 * Description      : Implement these test cases functions.
 * Creator          : Frederick Hsu
 * Creation date    : Sat.  April 18, 2015
 * Copyright(C)     2015    All rights reserved.
 *
 *****************************************************************************************************/


#include "Test_Queue.h"
#include "Queue.h"

#include <stdio.h>

void TestCase4_ManipulateQueue(void)
{
    LinkQueue *Queue = NULL;
    int iLenOfQueue = 8;
    
    InitQueue(Queue);
    
    CreateQueue(Queue, iLenOfQueue);
    DisplayQueue(*Queue);
}