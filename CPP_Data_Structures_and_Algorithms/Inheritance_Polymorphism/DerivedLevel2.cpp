/*****************************************************************************************
 * File name		: DerivedLevel2.cpp
 * Description		: Implement the class DerivedLevel2.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/


#include "DerivedLevel2.h"
#include <iostream>

using namespace std;


void DerivedLevel2::f(char *s)
{
	cout<<"Function f() in DerivedLevel2 called from "<<s<<endl;
	g("DerivedLevel2");
	Derived1Level1::h("DerivedLevel2");
	BaseClass::f("DerivedLevel2");
	return;
}