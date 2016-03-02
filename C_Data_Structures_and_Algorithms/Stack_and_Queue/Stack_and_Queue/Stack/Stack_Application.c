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
#include "Maze/Test_Maze.h"

#include "Test_Hanoi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* =====================================================================
 *
 * 栈的应用举例 ： 
 *
 * =====================================================================
 */
void Stack_Applications(void)
{
	/*
	printf("Decimal number converting to octal number ====>\n");
	Decimal_Convert2_Octal();

	printf("Decimal number converting to binary number ====>\n");
	Decimal_Convert2_Binary();

	printf("Decimal number converting to hex number ====>\n");
	Decimal_Convert2_Hexadecimal();
	 */

	// Maze_Problem();

	Hanoi_Tower_Problem();
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


/*======================================================================================================*/
int Init_Char_Stack(PtrCharStack pCStack)
{
	pCStack->char_stack_base = (char *)calloc(CHAR_STACK_INIT_SIZE, sizeof(char));
	if (pCStack->char_stack_base == NULL)
	{
		return ERROR;
	}
	pCStack->char_stack_top = pCStack->char_stack_base;
	pCStack->char_stack_size = CHAR_STACK_INIT_SIZE;
	pCStack->actual_stack_length = 1;
	return OK;
}

int Char_Stack_Pop(PtrCharStack pCStack, char *celem)
{
	if (pCStack->char_stack_base == pCStack->char_stack_top)
	{
		*celem = *(pCStack->char_stack_top);
		pCStack->actual_stack_length--;
		return OK;
	}
	*celem = *(pCStack->char_stack_top);
	pCStack->char_stack_top--;
	pCStack->actual_stack_length--;
	return OK;
}

int Char_Stack_Push(PtrCharStack pCStack, char celem)
{
	int iCurrentLen = pCStack->actual_stack_length, 
		iSize = pCStack->char_stack_size;
	if (iCurrentLen > iSize)
	{
		pCStack->char_stack_base = (char *)realloc(pCStack->char_stack_base,
												   sizeof(char)*(iSize + CHAR_STACK_INCREMENT));
		if (pCStack->char_stack_base)
			return OVERFLOW;
		pCStack->char_stack_size += CHAR_STACK_INCREMENT;
	}
	pCStack->char_stack_top = pCStack->char_stack_base + iCurrentLen;
	*(pCStack->char_stack_top) = celem;
	pCStack->actual_stack_length++;
	return OK;
}

void Display_Char_Stack(CharStack CStack)
{
	int i = 0;
	printf("\n\n    Character stack :\n");
	printf("Position		| Address		| Character	\n");
	printf("--------------------------------------------------------------------------\n");
	for (i=0; i<CStack.actual_stack_length; i++)
	{
		if (CStack.char_stack_top-i == CStack.char_stack_top)
		{
			printf("Top				| 0x%08X		| %c	\n", CStack.char_stack_top-i, *(CStack.char_stack_top-i));
			printf("--------------------------------------------------------------------------\n");
		}
		else if (CStack.char_stack_top-i == CStack.char_stack_base)
		{
			printf("Base			| 0x%08X		| %c	\n", CStack.char_stack_top-i, *(CStack.char_stack_top-i));
			printf("--------------------------------------------------------------------------\n");
		}
		else
		{
			printf("****			| 0x%08X		| %c	\n", CStack.char_stack_top-i, *(CStack.char_stack_top-i));
			printf("--------------------------------------------------------------------------\n");
		}
		if (CStack.char_stack_base == CStack.char_stack_top)
		{
			printf("Character stack is empty.\n");
			break;
		}
	}
	printf("Stack length		|  %d characters	\n", CStack.actual_stack_length);
	printf("--------------------------------------------------------------------------\n");
	printf("Stack space size	| %d * %d = %d bytes	\n",
           CStack.char_stack_size,
           sizeof(char),
           (CStack.char_stack_size)*sizeof(char));
	printf("--------------------------------------------------------------------------\n");
	return;
}

int Clear_Char_Stack(PtrCharStack pCStack)
{
	pCStack->actual_stack_length = 0;
	memset(pCStack->char_stack_base, 0, pCStack->char_stack_size);
	pCStack->char_stack_top = pCStack->char_stack_base;

	return OK;
}

int Destroy_Char_Stack(PtrCharStack pCStack)
{
	pCStack->actual_stack_length = 0;
	pCStack->char_stack_size = 0;
	pCStack->char_stack_top = NULL;
	free(pCStack->char_stack_base);
	pCStack->char_stack_base = NULL;
	return OK;
}

void LineEdit(void)
/* 利用字符棧CS, 從終端接收一行並傳送至調用過程的數據區.
 * 規定 ： 當用戶發現剛剛鍵入的一個字符是錯的時， 可以補進一個退格符 '#', 以表示前一個字符無效；
 *		   如果發現當前鍵入的行内差錯較多或難以補救，則可以鍵入一個退行符 '@', 以表示當前行中的字符均無效。
 *
 * 流水不腐， 戶樞不蠹。  流水不腐，户枢不蠹。
 */
{
	char ch;
	CharStack CS = {NULL, NULL, 0, 0};
	Init_Char_Stack(&CS);	// 构造一个空的字符栈CS
	ch = getchar();			// 从终端接收第一个字符
	while (ch != EOF)		// EOF : End of File  (全文結束符)
	{
		while ( (ch != EOF) && (ch != '\n') )
		{
			switch (ch)
			{
			case '#':
				Char_Stack_Pop(&CS, &ch);	// 行内有單個字符錯誤，退棧出此錯誤字符。
				break;
			case '@':
				Clear_Char_Stack(&CS);		// 整行字符錯誤，則重置為空棧
				break;
			default:
				Char_Stack_Push(&CS, ch);	// 有效字符壓入棧内.
				break;
			}
			ch = getchar();
		}
		Display_Char_Stack(CS);		/* 將從棧底到棧頂的棧内字符傳送至調用過程的數據區
									 * 在此用打印出棧的内容來代替。
									 */
		Clear_Char_Stack(&CS);		// 重置為空棧
		if (ch != EOF)
			ch = getchar();
	}
	Destroy_Char_Stack(&CS);	// 全文編輯完成，摧毀此字符棧.
	return;
}


/*=========================================================================================*/
void Maze_Problem(void)
/* “迷宮”問題求解
 */
{
	Test_Maze_Problem();
	return;
}

void Hanoi_Tower_Problem(void)
{
	Demonstrate_Hanoi_Tower();
}