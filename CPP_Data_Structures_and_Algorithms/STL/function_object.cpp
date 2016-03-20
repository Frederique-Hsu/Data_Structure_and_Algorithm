/*****************************************************************************
 * File name	: function_object.cpp
 * Description	: Investigate the usage of function object.
 * Creator		: Frederick Hsu
 * Creation date: Monday,	14 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *****************************************************************************/

#include "function_object.h"


classf::classf(void)
{
	// Insert your code here.
	// Now it is empty.
}


double classf::operator()(double x)
{
	return 2*x;
}


double sum2(classf func, int n, int m)
{
	double result = 0;
	for (int i = n; i <= m; i++)
	{
		result += func(i);
	}
	return result;
}

classf2::classf2(void)
{
	// Empty
}

double classf2::run(double x)
{
	return 2*x;
}

double sum3(classf2 obj, int n, int m)
{
	double result = 0.00;
	for (int i = n; i <= m; i++)
	{
		result += obj.run(i);
	}
	return result;
}



