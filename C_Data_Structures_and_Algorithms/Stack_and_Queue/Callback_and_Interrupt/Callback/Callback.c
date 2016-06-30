/***************************************************************************************
 * File name		: Callback.c
 * Description		: Study the call-back mechanism, how to program the call-back in C.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Dec. 22, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ***************************************************************************************/

#include "Callback.h"

#include <stdio.h>

void GetCallBack(pCallBack callback)
{
	printf("This function is a caller.\n");
}

void Demo_Call_Back_Mechanism(void)
{
	printf("Demonstrate how to implement the call-back functions.\n");
	GetCallBack(fCallback);
}

void fCallback(char *s)
{
	printf("This function is a callee which is defined by user.\n");
}

int sort_function(const void *a, const void *b)
{
	return *((int *)a)-*((int *)b);
}