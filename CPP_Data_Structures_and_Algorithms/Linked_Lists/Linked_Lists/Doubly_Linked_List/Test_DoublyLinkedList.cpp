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

    DoublyLinkedListNode<int> *pMyNode = pMyList->getNodeOfPositionN(3);
    pMyNode->printNodesChain();
    pMyList->exchangePositionBetween2Nodes(5, 8);
    pMyList->printDoublyLinkedList();
    pMyList->exchangePositionBetween2Nodes(1, pMyList->numberOfNodes());
    pMyList->printDoublyLinkedList();
    pMyList->exchangePositionBetween2Nodes(pMyList->numberOfNodes(), 1);
    pMyList->printDoublyLinkedList();
    pMyList->exchangePositionBetween2Nodes(1, 4);
    pMyList->printDoublyLinkedList();
    pMyList->exchangePositionBetween2Nodes(5, pMyList->numberOfNodes());
    pMyList->printDoublyLinkedList();
    
    int specificElem = 8;
    std::cout<<"The position of element '"<<specificElem<<"' locates at "
             <<pMyList->getPositionOfSpecificElem(specificElem)<<"th node."<<std::endl;
    // std::printf("And its memory address is 0x%016lX  \n\n", (pMyList->getNodeOfSpecificElem(specificElem)));
    
    specificElem = -30;
    std::cout<<"On statistic, "<<pMyList->doStatCountsForSpecificElem(specificElem)
             <<" nodes have the identical element : "<<specificElem<<"\n\n"<<std::endl;
    
/************************************************************************************************/
    
    delete pDLList;
    delete pMyList;
    
    std::cout<<"Congratulations! The Doubly-Linked-List data structure and algorithm had finally done.\n"
             <<std::endl;
}
