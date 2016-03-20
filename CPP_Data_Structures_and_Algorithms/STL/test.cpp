/*****************************************************************************
 * File name	: test.cpp
 * Description	: Design and perform the test cases here.
 * Creator		: Frederick Hsu
 * Creation date: Monday,	14 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *****************************************************************************/


#include "test.h"
#include "test_function_object.h"
#include "vector_function_handling.h"


void performTestCases(void)
{
	testCases4FunctionObject();
	testCase4VectorFunctionHandling();
}

void testCases4FunctionObject(void)
{
	callFunctionObject();
}

void testCase4VectorFunctionHandling(void)
{
    performTesting4VectorFcnt();
}
