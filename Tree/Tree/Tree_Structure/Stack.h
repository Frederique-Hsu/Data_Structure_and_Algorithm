/*******************************************************************************************************
 * File name		: Stack.h
 * Description		: Define the stack of binary tree traversing each node.
 * Creator			: Frederick Hsu
 * Creation date	: Fri.	April 10, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *******************************************************************************************************/


#ifndef STACK_H
#define STACK_H

	#include "Tree.h"

	typedef struct BiTreeTraverseStack
	{
		BiTree *top;
		BiTree *bottom;
		int actual_length;
		int stack_size;
	}
	BiTreeTraverseStack, *PtrBiTreeTraverseStack;

	int Init_BiTreeTraverseStack(BiTreeTraverseStack *bitree_stack);
	
	int Destroy_BiTreeTraverseStack(BiTreeTraverseStack *bitree_stack);
	
	int Push_BiTreeTraverseStack(BiTreeTraverseStack *bitree_stack,
								 BiTree tree_node);
	
	int Pop_BiTreeTraverseStack(BiTreeTraverseStack *bitree_stack,
								BiTree *tree_node);

/*******************************************************************************************************/
	#define USER_INT			1
	#define USER_FLOAT			2
	#define USER_CHAR			3
	#define USER_LONG			4
	#define USER_VOID			5
	#define USER_SELF_DEFINE	6
	#define USER_VOID_POINTER	7

	#define USER_ELEM_TYPE		USER_VOID_POINTER

	typedef 
	#if (USER_ELEM_TYPE == USER_INT)
		int	
	#elif (USER_ELEM_TYPE == USER_FLOAT)
		float
	#elif (USER_ELEM_TYPE == USER_CHAR)
		char
	#elif (USER_ELEM_TYPE == USER_LONG)
		long
	#elif (USER_ELEM_TYPE == USER_VOID)
		void
	#elif (USER_ELEM_TYPE == USER_VOID_POINTER)
		void *
	#elif (USER_ELEM_TYPE == USER_SELF_DEFINE)
		// User self-defined data type
	#else
		int
	#endif
		StackElemType;

	typedef struct UniversalStack
	{
		StackElemType *top;
		StackElemType *bottom;
		int actual_length;
		int stack_size;
	}
	UniversalStack, *PtrUniversalStack;

	int InitStack(UniversalStack *stack);
	int DestroyStack(UniversalStack *stack);
	int PushStack(UniversalStack *stack, StackElemType *e);
	int PopStack(UniversalStack *stack, StackElemType *e);

#endif	/*  STACK_H  */