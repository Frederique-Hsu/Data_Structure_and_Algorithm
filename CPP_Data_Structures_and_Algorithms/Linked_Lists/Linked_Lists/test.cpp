/*************************************************************************************************
 * File name    : test.cpp
 * Description  : Perform the test cases here.
 * Creator      : Frederick Hsu
 * Creation date: Sun.  26 June, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#include "test.h"
#include "Singly_Linked_List/Test_IntSLList.h"
#include "Doubly_Linked_List/Test_DoublyLinkedList.h"
#include "data_types.h"

#include <cstdio>
#include <iostream>

void performProjectTestCases(void)
{
    perform_SLList_TestCases();
    perform_DLList_TestCases();


    // listSizeOfAllBasicDataTypes();
}

void perform_SLList_TestCases(void)
{
	std::cout<<"\n\n"<<"Verify the Singly Linked Lists : \n"<<std::endl;
    testCase4_VerifySLList();
}

void perform_DLList_TestCases(void)
{
	std::cout<<"\n\n"<<"Verify the Doubly Linked Lists : \n"<<std::endl;
	testCase4_VerifyDoublyLinkedList();
}

void listSizeOfAllBasicDataTypes(void)
{
    checkSizeOfAllBasicDataTypes();
}

