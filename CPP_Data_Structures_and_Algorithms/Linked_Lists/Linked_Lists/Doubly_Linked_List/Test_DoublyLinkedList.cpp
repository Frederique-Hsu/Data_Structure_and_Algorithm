/*************************************************************************************************
 * File name    : Test_DoublyLinkedList.cpp
 * Description  : Design test cases to test the Doubly_Linked_List structure and algorithm.
 * Creator      : Frederick Hsu
 * Creation date: Mon.	6 July, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/


#include "Test_DoublyLinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>

void testCase4_VerifyDoublyLinkedList(void)
{
	int num = 0;

	DoublyLinkedList<int> *pDLList = new DoublyLinkedList<int>(num);
    num = 8;
	pDLList->addToDoublyLinkedListHead(num);
	pDLList->printDoublyLinkedList();

	num = 1;
	pDLList->addToDoublyLinkedListTail(num);
	pDLList->printDoublyLinkedList();
    
    num = 10;
    pDLList->addToDoublyLinkedListHead(num);
    pDLList->printDoublyLinkedList();
    std::cout<<"Now this Doubly-Linked-List has "<<pDLList->numberOfNodes()<<" nodes."<<std::endl;

    num = -9;
    pDLList->addToDoublyLinkedListTail(num);
    num = 95;
    pDLList->addToDoublyLinkedListHead(num);
    pDLList->printDoublyLinkedList();

    num = 25;
    pDLList->insertNewNodeAfterPositionN(num, 2);
    pDLList->printDoublyLinkedList();
    num = -30;
    pDLList->insertNewNodeAfterPositionN(num, 5);
    pDLList->insertNewNodeAfterPositionN(num, 1);
    pDLList->printDoublyLinkedList();
    num = 200;
    pDLList->insertNewNodeAfterPositionN(num, pDLList->numberOfNodes());
    pDLList->printDoublyLinkedList();

    num = 16;
    pDLList->insertNewNodeBeforePositionN(num, 4);
    pDLList->printDoublyLinkedList();
    num = -56;
    pDLList->insertNewNodeBeforePositionN(num, pDLList->numberOfNodes());
    pDLList->insertNewNodeBeforePositionN(num, 7);
    pDLList->printDoublyLinkedList();
    num = 100;
    pDLList->insertNewNodeBeforePositionN(num, 1);
    pDLList->printDoublyLinkedList();

    DoublyLinkedList<int> *pMyList = new DoublyLinkedList<int>(*pDLList);
    pMyList->printDoublyLinkedList();
    
/************************************************************************************************/
    
    pMyList->deleteNodeOfPositionN(5);
    pMyList->printDoublyLinkedList();
    pMyList->deleteNodeOfPositionN(1);
    pMyList->deleteNodeOfPositionN(pMyList->numberOfNodes());
    pMyList->printDoublyLinkedList();
    
/************************************************************************************************/
    
    delete pDLList;
    delete pMyList;
}
