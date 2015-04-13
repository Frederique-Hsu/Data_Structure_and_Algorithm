/*******************************************************************************************************
 * File name		: Stack.c
 * Description		: Implement the stack of binary tree traversing each node.
 * Creator			: Frederick Hsu
 * Creation date	: Fri.	April 10, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *******************************************************************************************************/


#include "Stack.h"
#include <stdlib.h>

int Init_BiTreeTraverseStack(BiTreeTraverseStack *bitree_stack)
{
	bitree_stack->bottom = (BiTree *)calloc(1, sizeof(BiTNode));
	if (bitree_stack->bottom == NULL)
	{
		return OVERFLOW;
	}
	bitree_stack->top = bitree_stack->bottom;
	bitree_stack->actual_length = 1;
	bitree_stack->stack_size = 1;

	return OK;
}

int Destroy_BiTreeTraverseStack(BiTreeTraverseStack *bitree_stack)
{
	free(bitree_stack->bottom);
	bitree_stack->bottom = NULL;
	bitree_stack->top = NULL;

	bitree_stack->actual_length = 0;
	bitree_stack->stack_size = 0;
	return OK;
}

int Push_BiTreeTraverseStack(BiTreeTraverseStack	*bitree_stack,
							 BiTree					tree_node)
{
	return OK;
}