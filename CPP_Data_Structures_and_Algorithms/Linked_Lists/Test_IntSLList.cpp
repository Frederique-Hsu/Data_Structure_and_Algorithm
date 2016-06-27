/*************************************************************************************************
 * File name    : Test_IntSLList.cpp
 * Description  : Design some unit test cases to verify the Singly Linked Lists.
 * Creator      : Frederick Hsu
 * Creation date: Mon.  27 June, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#include "Test_IntSLList.h"

#include "intSLList.h"
#include <iostream>

void testCase4_VerifySLList(void)
{
    std::cout<<"Verify the Singly Linked Lists"<<std::endl;

    IntSLList *pList = new IntSLList();

    pList->addToHead(10);
    pList->addToTail(8);
    pList->printListChain();

    pList->addToTail(18);
    std::cout<<"The length of current linked list is : "<<pList->lengthOfList()<<std::endl;
    pList->printListChain();

    pList->addToHead(9);
    pList->addToTail(25);
    pList->addToTail(-12);
    pList->printListChain();

    delete pList;
}
