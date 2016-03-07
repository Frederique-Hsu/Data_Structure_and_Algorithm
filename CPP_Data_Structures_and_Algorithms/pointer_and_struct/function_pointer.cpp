/*********************************************************************
 * File name		: function_pointer.cpp
 * Description		: 函數指針的用法
 * Creator			: Frederick Hsu
 * Creation date	: Fri.	04 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/

#include "function_pointer.h"
#include <cmath>

double sum(double (*f)(double), int n, int m)
{
	double result = 0;
	for (int i = n; i < m; i++)
	{
		result = result + f(i);
	}
	return result;
}

double root(double (*f)(double), double a, double b, double epsilon)
{
	double middle = (a+b)/2;
	while ((f(middle) != 0) && (std::fabs(a-b) > epsilon))
	{
		if (f(a) * f(middle) < 0)	// If f(a) and f(middle) have opposite signs.
		{
			b = middle;
		}
		else
		{
			a = middle;
		}
		middle = (a+b)/2;
	}
	return middle;
}

double mathFunc_x(double x)
{
	return x*x - 5*x + 6;
}