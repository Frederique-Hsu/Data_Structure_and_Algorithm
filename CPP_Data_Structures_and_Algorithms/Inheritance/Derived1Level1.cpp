/*****************************************************************************************
 * File name		: Derived1Level1.h
 * Description		: Implement the class Derived1Level1.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/


#include "Derived1Level1.h"
#include <iostream>

using namespace std;

void Derived1Level1::f(char *s)
{
	cout<<"Function f() in Derived1Level1 called from "<<s<<endl;
	g("Derived1Level1");
	h("Derived1Level1");
	return;
}

void Derived1Level1::h(char *s)
{
	cout<<"Function h() in Derived1Level1 called from "<<s<<endl;

	return;
}