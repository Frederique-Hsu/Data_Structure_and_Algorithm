/**************************************************************************************************
 * File name	: genStack.cpp
 * Description	: Implement the template class Stack.
 * Creator		: Frederick Hsu
 * Creation date: Mon.	05 Aug.	2019
 * Copyright(C)	2019	All rights reserved.
 *
 **************************************************************************************************/

#include "genStack.h"

template<class T, int capacity>
void Stack<T, capacity>::clear()
{
	pool.clear();
}