/********************************************************************************************
 * File name		: Test.c
 * Description		: Perform the test cases here.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Dec. 22, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ********************************************************************************************/


#include "Test.h"
#include "Callback/TestCase_Callback.h"

void General_Test_Cases(void)
{
	TestCase_CallbackMechanism();

	return;
}

void TestCase_CallbackMechanism(void)
{
	Test_Sort_Callback();
}