/*******************************************************************************************
 * File name		: Stack_Application.c
 * Description		: Apply the stack structure to solve some application problem.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Dec. 16, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *******************************************************************************************/


#include "Stack_Application.h"

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


/* =====================================================================
 *
 * 栈的应用举例 ： 
 *
 * =====================================================================
 */
void Stack_Applications(void)
{
	printf("Decimal number converting to octal number ====>\n");
	Decimal_Convert2_Octal();

	printf("Decimal number converting to binary number ====>\n");
	Decimal_Convert2_Binary();

	printf("Decimal number converting to hex number ====>\n");
	Decimal_Convert2_Hexadecimal();
	return;
}

void Decimal_Convert2_Octal(void)
/* 对于输入的任意一个非负十进制整数，
 * 打印输出与其等值的八进制数.
 */
{
	int N = 0, iOrigin = 0;
	SElemType e = 0;

	SqStack S = {NULL, NULL, 0};
	InitStack(&S);		// 构造空棧

	printf("Please enter a deciamal number : N = ");
	scanf("%d", &N);
	iOrigin = N;
	while (N)
	{
		Push(&S, N%8);		// 將餘數壓棧
		N = N/8;
	}
	DisplayStack(S);
	printf("N = %d was converted to octal format as : ", iOrigin);
	while (!StackEmpty(S))
	{
		Pop(&S, &e);		// 將餘數退棧
		printf("%d", e);	// 逐次打印形成八進制數
	}
	DisplayStack(S);
	DestroyStack(&S);
	printf("\n\n");
	return;
}

void Decimal_Convert2_Binary(void)
/* 把十進制非負整數轉換為二進制數.
 */
{
	int N = 0, iOrigin = 0;
	SElemType e = 0;

	SqStack S = {NULL, NULL, 0};
	printf("Please enter a decimal number : N = ");
	scanf("%d", &N);
	iOrigin = N;
	while (N)
	{
		Push(&S, N%2);
		N = N/2;
	}
	DisplayStack(S);
	printf("N = %d was converted to binary format as : ", iOrigin);
	while (!StackEmpty(S))
	{
		Pop(&S, &e);
		printf("%d", e);
	}
	DisplayStack(S);
	DestroyStack(&S);
	printf("\n\n");
	return;
}


void Decimal_Convert2_Hexadecimal(void)
{
	int N = 0, iOrigin = 0;
	SElemType e = 0;

	SqStack S = {NULL, NULL, 0};
	printf("Please enter a decimal number : N = ");
	scanf("%d", &N);
	iOrigin = N;
	while (N)
	{
		Push(&S, N%16);
		N = N/16;
	}
	DisplayStack(S);
	printf("N = %d was converted to hex format as : 0x", iOrigin);
	while (!StackEmpty(S))
	{
		Pop(&S, &e);
		printf("%01X", e);
	}
	DisplayStack(S);
	DestroyStack(&S);
	printf("\n\n");
	return;
}