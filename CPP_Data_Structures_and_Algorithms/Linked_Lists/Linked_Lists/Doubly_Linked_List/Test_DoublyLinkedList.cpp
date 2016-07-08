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

void testCase4_VerifyDoublyLinkedList(void)
{
    DoublyLinkedList<int> *pDLList = new DoublyLinkedList<int>();
    pDLList->addToDoublyLinkedListHead();
    pDLList->printDoublyLinkedList();
}
