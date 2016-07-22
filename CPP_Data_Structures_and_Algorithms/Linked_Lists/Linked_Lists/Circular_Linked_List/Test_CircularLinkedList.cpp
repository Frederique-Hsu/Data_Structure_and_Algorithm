/*************************************************************************************************
 * File name    : Test_CircularLinkedList.cpp
 * Description  : Test and verify the structure and its oerations of Circular Linked List.
 * Creator      : Frederick Hsu
 * Creation date: Fri.  22 July, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/


#include "Test_CircularLinkedList.h"
#include "CircularLinkedList.h"

void testCase4_VerifyCircularLinkedList(void)
{
	CircularLinkedList<int> *pCLList = new CircularLinkedList<int>(1);
	pCLList->addToCircularLinkedListTail(2);
	pCLList->addToCircularLinkedListTail(3);
    pCLList->addToCircularLinkedListTail(4);
    pCLList->addToCircularLinkedListTail(5);
    pCLList->addToCircularLinkedListTail(6);
    pCLList->addToCircularLinkedListTail(7);
    pCLList->addToCircularLinkedListTail(8);
    pCLList->addToCircularLinkedListTail(9);
    pCLList->addToCircularLinkedListTail(10);
    pCLList->printCircularLinkedList();
    
    pCLList->addToCircularLinkedListHead(100);
    pCLList->printCircularLinkedList();
    std::cout<<"Currently this list has "<<pCLList->numberOfNodes()<<" nodes."<<std::endl;
    
    pCLList->insertNewNodeBeforePositionN(20, 5);
    pCLList->printCircularLinkedList();
    pCLList->insertNewNodeAfterPositionN(30, 9);
    pCLList->printCircularLinkedList();
    
    std::cout<<"Delete the head node, its element is : "<<pCLList->deleteFromHead()<<std::endl;
    std::cout<<"Delete the tail node, its element is : "<<pCLList->deleteFromTail()<<std::endl;
    pCLList->printCircularLinkedList();
    
    std::cout<<"Currently this list has "<<pCLList->numberOfNodes()<<" nodes."<<std::endl;
    std::cout<<"Delete the 3rd node, its element is : "<<pCLList->deleteNodeOfPositionN(3)<<std::endl;
    std::cout<<"Delete the 8th node, its element is : "<<pCLList->deleteNodeOfPositionN(8)<<std::endl;
    pCLList->printCircularLinkedList();

    std::cout<<"Change the 9th node with element -100"<<std::endl;
    pCLList->setElementOfPositionN(-100, 9);
    std::cout<<"Check the element of 9th node, its element is "<<pCLList->getElementOfPositionN(9)<<std::endl;
    pCLList->printCircularLinkedList();

    CircularLinkedListNode<int> *pNode = pCLList->getNodeOfPositionN(3);
    pNode->printNodeChain();
    
    std::cout<<"Exchange between position 2 and position 7"<<std::endl;
    pCLList->exchangeBetween2Nodes(2, 7);
    pCLList->printCircularLinkedList();
    
    pCLList->insertNewNodeAfterPositionN(5, 5);
    pCLList->insertNewNodeAfterPositionN(5, 8);
    pCLList->insertNewNodeAfterPositionN(5, 10);
    pCLList->addToCircularLinkedListHead(5);
    pCLList->addToCircularLinkedListTail(5);
    pCLList->printCircularLinkedList();

    CircularLinkedListNode<int>* nodesWithIdenticalElem[50] = {0};
    int numWithIdenticalElem = 0;
    int positionsWithIdenticalElem[50] = {0};
    pCLList->getPositionOfSpecificElem(5, positionsWithIdenticalElem, &numWithIdenticalElem);
    pCLList->getNodesOfSpecificElem(5, nodesWithIdenticalElem, &numWithIdenticalElem);
    std::cout<<"For the element '5', there are "<<pCLList->doStatDuplicateElemCount(5)<<" duplicates."<<std::endl;
    std::cout<<" Node addr          | Position      "<<std::endl;
    std::cout<<"---------------------------------------------------------"<<std::endl;
    for (int i=0; i<numWithIdenticalElem; i++)
    {
        std::printf(" 0x%016lX  | %d    \n", nodesWithIdenticalElem[i], positionsWithIdenticalElem[i]);
        std::cout<<"---------------------------------------------------------"<<std::endl;
    }

    delete pCLList;
}

void testCase4_VerifySpecializedCircularLinkedList(void)
{
    CircularLinkedList<const char*> *pCCList = new CircularLinkedList<const char*>("A");
    pCCList->addToCircularLinkedListHead("B");
    pCCList->addToCircularLinkedListTail("C");
    pCCList->printCircularLinkedList();
    
    pCCList->addToCircularLinkedListTail("Hello");
    pCCList->addToCircularLinkedListTail("C++ data structure");
    pCCList->addToCircularLinkedListTail("and algorithm");
    pCCList->printCircularLinkedList();
    
    std::string str = "I love you!";
    CircularLinkedList<std::string> *pCCList_String = new CircularLinkedList<std::string>(str);
    pCCList_String->addToCircularLinkedListTail("Do you love me?");
    pCCList_String->addToCircularLinkedListHead("Yes, I love you too.");
    pCCList_String->printCircularLinkedList();
    
    delete pCCList;
    delete pCCList_String;
}
