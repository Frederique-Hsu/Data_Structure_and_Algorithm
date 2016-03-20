/*****************************************************************************************
 * File name		: Derived2Level1.cpp
 * Description		: Implement the class Derived2Level1.
 * Creator			: Frederick Hsu
 * Creation date	: Sun. 28 Feb., 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *****************************************************************************************/


#include "Derived2Level1.h"

#include <iostream>

using namespace std;

void Derived2Level1::f(char *s)
{
	cout<<"Function f() in Derived2Level1 called from "<<s<<endl;
	g("Derived2Level1");
	// h();	// error : BaseClass::h() is not accessible
	return;
}