/******************************************************************************************
 * File name		: Test_Tree.c
 * Description		: Test the tree structure and its algorithm.
 * Creator			: Frederick Hsu
 * Creation date	: Mon.	April 13, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 ******************************************************************************************/

#include "Test_Tree.h"
#include "Tree.h"


void TestCase4_TreeManipulate(void)
{
	BiTree btree = NULL;
	CreateBiTree(&btree);

	DisplayBiTree(btree);
}