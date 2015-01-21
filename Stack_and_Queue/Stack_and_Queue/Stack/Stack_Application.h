/*******************************************************************************************
 * File name		: Stack_Application.h
 * Description		: Apply the stack structure to solve some application problem.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Dec. 16, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *******************************************************************************************/


#ifndef STACK_APPLICATION_H
#define STACK_APPLICATION_H

	void Stack_Applications(void);


	/*
	 * 数制转换
	 */
	void Decimal_Convert2_Octal(void);
	void Decimal_Convert2_Binary(void);
	void Decimal_Convert2_Hexadecimal(void);

	/* 
	 * 括号匹配的检验
	 * 
	 * 用“期待的急迫程度”来描述
	 */

/*======================================================================================================*/
	/* 
	 * 行編輯程序
	 *
	 * 用字符棧來實現對用戶輸入的字符行進行查錯糾正。
	 */
	#define CHAR_STACK_INIT_SIZE	20
	#define CHAR_STACK_INCREMENT	5

	typedef struct CharStack
	{
		char *char_stack_top;
		char *char_stack_base;
		int char_stack_size;
		int actual_stack_length;
	}
	CharStack,	*PtrCharStack;

	int Init_Char_Stack(PtrCharStack pCStack);
	int Char_Stack_Pop(PtrCharStack pCStack, char *celem);
	int Char_Stack_Push(PtrCharStack pCStack, char celem);
	void Display_Char_Stack(CharStack CStack);
	int Clear_Char_Stack(PtrCharStack pCStack);
	int Destroy_Char_Stack(PtrCharStack pCStack);

	void LineEdit(void);

	void Maze_Problem(void);

#endif	/*  STACK_APPLICATION_H  */