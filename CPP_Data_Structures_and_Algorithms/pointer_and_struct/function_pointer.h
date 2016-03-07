/*********************************************************************
 * File name		: function_pointer.h
 * Description		: 函數指針的用法
 * Creator			: Frederick Hsu
 * Creation date	: Fri.	04 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/

#ifndef FUNCTION_POINTER_H
#define FUNCTION_POINTER_H

 	double sum(double (*f)(double), int n, int m);
 	double root(double (*f)(double), double a, double b, double epsilon);

 	double mathFunc_x(double x);

#endif	/*  FUNCTION_POINTER_H  */