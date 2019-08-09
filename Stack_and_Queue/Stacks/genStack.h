/**************************************************************************************************
 * File name	: genStack.h
 * Description	: generic class for vector implementation of stack.
 * Creator		: Frederick Hsu
 * Creation date: Mon.	05 Aug.	2019
 * Copyright(C)	2019	All rights reserved.
 *
 **************************************************************************************************/

#ifndef GENSTACK_H
#define GENSTACK_H

	#include <vector>
	using namespace std;

	template<class T, int capacity = 30>
	class Stack
	{
	public:
		Stack()
		{
			pool.reserve(capacity);
		}

		void clear();
	private:
		vector<T> pool;
	};

	// #include "genStack.cpp"

#endif	/* GENSTACK_H */