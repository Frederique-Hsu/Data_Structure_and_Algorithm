/*********************************************************************************************************
 * File name		: Tree.c
 * Description		: Implement tree's operation-functions prototype.
 * Creator			: Frederick Hsu
 * Creation date	: Thur.	April 09, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *********************************************************************************************************/


#include "Tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int PreOrderTraverse(BiTree T, int (*visit)(TElemType e))
/* 採用二叉鏈表存儲結構, visit是對數据元素操作的應用函數.
 * 先序遍歷二叉樹T的遞歸算法,對每個數據元素調用函數visit.
 */
{
	if (T)
	{
		if (visit(T->data))
		{
			if (PreOrderTraverse(T->lchild, visit))
			{
				if (PreOrderTraverse(T->rchild, visit))
				{
					return OK;
				}
			}
		}
		return ERROR;
	}
	else
	{
		return OK;
	}
}

int DisplayElement(TElemType e)
{
	printf("%d\t\n", e);
	return OK;
}

int CreateBiTree(BiTree *T)
/* 按先序次序輸入二叉樹中結點的值，構造二叉鏈表表示的二叉樹T.
 */
{
	int n;
	char sNum[16] = {0};
	printf("Please enter a number for one tree node (null to terminate): ");
	scanf("%s", sNum);
	if (!strcmp(sNum, "null"))
	{
		(*T) = NULL;
	}
	else
	{
		n = atoi(sNum);
		if (NULL == ((*T) = (BiTree)calloc(1, sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = n;
		CreateBiTree(&((*T)->lchild));
		CreateBiTree(&((*T)->rchild));
	}
	return OK;
}

int DisplayBiTree(BiTree T)
{
	printf(" Current	| Data	| L_Child	| R_Child	|\n");
	printf("-------------------------------------------------------------------------\n");
	BiTreeTraverse(T, PrintBiTreeNode);
	return OK;
}

void BiTreeTraverse(BiTree T, void (*VisitNode)(BiTree T))
{
	if (T)
	{
		VisitNode(T);
		BiTreeTraverse(T->lchild, VisitNode);
		BiTreeTraverse(T->rchild, VisitNode);
	}
}

void PrintBiTreeNode(BiTree T)
{
	printf(" 0x%08X	| %d	| 0x%08X	| 0x%08X	|\n", 
		   T, (T->data), (T->lchild), (T->rchild));
	printf("-------------------------------------------------------------------------\n");
	return;
}