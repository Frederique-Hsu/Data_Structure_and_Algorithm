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
#include <cstdio>

void testCase4_VerifySLList(void)
{
    IntSLList *pList = new IntSLList();
    
    pList->addToHead(10);
    pList->addToTail(8);
    pList->addToHead(37);
    pList->addToTail(100);
    pList->printListChain();
    
    pList->insertBeforeNode(5, 4);
    pList->printListChain();
    pList->addToTail(18);
    std::cout<<"The length of current linked list is : "<<pList->lengthOfList()<<std::endl;
    pList->printListChain();
    
    pList->addToHead(9);
    pList->addToTail(25);
    pList->addToTail(-12);
    pList->printListChain();
    pList->insertAfterNode(40, 6);
    pList->printListChain();
    
    pList->deleteFromHead();
    pList->printListChain();
    
    pList->deleteFromTail();
    pList->printListChain();
    
    pList->insertBeforeNode(100, 3);
    pList->printListChain();

    pList->deleteNode(100);
    pList->printListChain();
    std::printf("Element 100 is inside the list : %d (1 = Yes, 0 = No)\n", pList->isInList(100));
    
    pList->deleteNthNode(5);
    pList->printListChain();
    
    std::printf("Return the 2nd node, address = 0x%016lX\n", pList->locatePosition(2));
    
    pList->insertAfterNode(10, 7);
    pList->printListChain();
    pList->changeElementOfPositionN(6, 99);
    pList->printListChain();
    pList->replaceSameOldElements(10, -20);
    pList->printListChain();
    
    delete pList;
    std::printf("\n\n");
}
