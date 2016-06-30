/*****************************************************************************
 * File name	: test_function_object.cpp
 * Description	: Test the function object and its usages.
 * Creator		: Frederick Hsu
 * Creation date: Tuesday,	15 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *****************************************************************************/

#include "test_function_object.h"
#include "function_object.h"

#include <iostream>


void callFunctionObject(void)
{
	classf cf;
	std::cout<<"Sum2 = "<<sum2(cf, 2, 5)<<std::endl;
	std::cout<<"The sum is : "<<sum2(classf(), 1, 5)<<std::endl;
	std::cout<<"Sum3 = "<<sum3(classf2(), 2, 5)<<std::endl;

	return;
}