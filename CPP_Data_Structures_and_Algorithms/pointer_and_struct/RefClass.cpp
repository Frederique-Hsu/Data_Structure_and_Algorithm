/*********************************************************************
 * File name		: RefClass.cpp
 * Description		: 引用類可直接訪問私有成員變量
 * Creator			: Frederick Hsu
 * Creation date	: Thu.	03 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/

#include "RefClass.h"


RefClass::RefClass(void)
{
	n = 0;
}

int& RefClass::getRefN(void)
{
	return n;
}

int RefClass::getN(void)
{
	return n;
}