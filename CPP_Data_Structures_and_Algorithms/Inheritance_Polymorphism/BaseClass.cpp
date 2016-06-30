/*****************************************************************************************
 * File name		: BaseClass.cpp
 * Description		: Implement the class BaseClass.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/

#include "BaseClass.h"
#include <iostream>

 using namespace std;

BaseClass::BaseClass(void)
{
	// Empty
}

void BaseClass::f(char *s)
{
	cout<<"Function f() in BaseClass called from "<<s<<endl;
	return;
}

void BaseClass::g(char *s)
{
	cout<<"Function g() in BaseClass called from "<<s<<endl;
	return;
}

void BaseClass::h(void)
{
	cout<<"Function h() in BaseClass"<<endl;
	return;
}