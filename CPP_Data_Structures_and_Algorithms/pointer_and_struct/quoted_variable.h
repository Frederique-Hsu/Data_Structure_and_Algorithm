/*********************************************************************
 * File name		: quoted_variable.h
 * Description		: 指針和引用變量
 * Creator			: Frederick Hsu
 * Creation date	: Thu.	03 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/


#ifndef QUOTED_VARIABLE_H
#define QUOTED_VARIABLE_H

 	void func1(int i, int* j, int& k);

 	int& func2(int a[], int i);
 	int* func3(int a[], int i);

#endif	/*  QUOTED_VARIABLE_H  */