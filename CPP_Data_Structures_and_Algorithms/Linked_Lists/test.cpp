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
#include "data_types.h"

void performProjectTestCases(void)
{
    perform_SLList_TestCases();
    listSizeOfAllBasicDataTypes();
}

void perform_SLList_TestCases(void)
{
    testCase4_VerifySLList();
}

void listSizeOfAllBasicDataTypes(void)
{
    checkSizeOfAllBasicDataTypes();
}

