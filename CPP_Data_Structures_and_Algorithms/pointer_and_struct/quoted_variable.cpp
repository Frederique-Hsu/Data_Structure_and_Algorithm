/*********************************************************************
 * File name		: quoted_variable.cpp
 * Description		: 指針和引用變量
 * Creator			: Frederick Hsu
 * Creation date	: Thu.	03 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/


#include "quoted_variable.h"

void func1(int i, int* j, int& k)
{
	i = 1;
	*j = 2;
	k = 3;
}

int& func2(int a[], int i)
{
	return a[i];
}

int* func3(int a[], int i)
{
	return &a[i];
}