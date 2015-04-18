/*********************************************************************************************************
 * File name		: Tree.h
 * Description		: Define the tree structure and its operation-functions prototype.
 * Creator			: Frederick Hsu
 * Creation date	: Thur.	April 09, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *********************************************************************************************************/


#ifndef TREE_H
#define TREE_H

	#include "universal_definitions.h"
	#include <stdio.h>

	typedef int			TElemType;			// 樹結點的元素的數據類型

	/*********二叉樹的順序存儲表示**********/
	#define MAX_TREE_SIZE	100				// 二叉樹的最大結點數

	typedef TElemType	SqBiTree[MAX_TREE_SIZE];	// 0號單元存儲根結點

	SqBiTree bt;

#if 1
	/*********二叉樹的二叉鏈表存儲表示************/
	typedef struct BiTNode
	{
		TElemType data;
		struct BiTNode *lchild;
		struct BiTNode *rchild;
	}
	BiTNode, *BiTree;
#else
	/*********二叉樹的三叉鏈表存儲表示************/
	typedef struct BiTNode
	{
		TElemType data;
		struct BiTNode *lchild;
		struct BiTNode *rchild;
		struct BiTNode *parent;
	}
	BiTNode, *BiTree;
#endif

	int CreateBiTree(BiTree *T);
	int DisplayBiTree(BiTree T);
	int PreOrderTraverse(BiTree T, int (*visit)(TElemType e));		// 先序遍歷
	int InOrderTraverse(BiTree T, int (*visit)(TElemType e));		// 中序遍歷
	int PostOrderTraverse(BiTree T, int (*visit)(TElemType e));		// 後序遍歷
	int LevelOrderTraverse(BiTree T, int (*visit)(TElemType e));	// 層序遍歷

	int DisplayElement(TElemType e);		// 簡單的 visit 回調函數

	void BiTreeTraverse(BiTree T, void (*VisitNode)(BiTree T));
	void PrintBiTreeNode(BiTree T);

#endif	/*  TREE_H  */