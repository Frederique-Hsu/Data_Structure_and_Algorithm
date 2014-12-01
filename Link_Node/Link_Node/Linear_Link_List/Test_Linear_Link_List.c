/**********************************************************************
 * File name		: Test_Linear_Link_List.c
 * Description		: Design the test case to verify the 
 *					  "Linear_Link_List" structure.
 * Creator			: XU ZAN
 * Creation date	: Fri.	Oct. 31, 2014
 * Copyright(C)		All rights reserved.
 *
 **********************************************************************/

#include <stdio.h>

#include "Test_Linear_Link_List.h"
#include "Linear_Link_List.h"

void TestCase_LinearLinkNode(void)
{
	ElemType e = 0;
	PtrLinkList pMyLinkNode = NULL, pDucplicateLinkNode = NULL;
	// ListCreate_L(pMyLinkNode, 5);
	ListCreate_LinkNode(&pMyLinkNode, 5);
	ListDisplay_LinkNode(pMyLinkNode);

	ListInsert_LinkNode(&pMyLinkNode, 3, 9);
	ListDisplay_LinkNode(pMyLinkNode);

	ListInsert_LinkNode(&pMyLinkNode, 5, 35);
	ListDisplay_LinkNode(pMyLinkNode);

	ListDelete_LinkNode(&pMyLinkNode, 3, &e);
	ListDisplay_LinkNode(pMyLinkNode);

	ListGetElem_LinkNode(pMyLinkNode, 4, &e);
	printf("The element of %dth node is : %d.\n", 4, e);

	ListDuplicate_LinkList(pMyLinkNode, &pDucplicateLinkNode);
	ListDisplay_LinkNode(pDucplicateLinkNode);

	ListDestroy_LinkNode(&pMyLinkNode);
	ListDisplay_LinkNode(pMyLinkNode);

	ListDestroy_LinkNode(&pDucplicateLinkNode);
	ListDisplay_LinkNode(pDucplicateLinkNode);

	pMyLinkNode = NULL;
}

void TestCase_MergeLinkNode(void)
{
	PtrLinkList pLa = NULL, pLb = NULL, pLc = NULL;

	ListCreate_LinkNode(&pLa, 3);
	printf("Original La = \n");
	ListDisplay_LinkNode(pLa);

	ListCreate_LinkNode(&pLb, 5);
	printf("Original Lb = \n");
	ListDisplay_LinkNode(pLb);

	ListMerge_LinkNode(pLa, pLb, &pLc);
	printf("After merging action, Current La = \n");
	ListDisplay_LinkNode(pLa);
	printf("After merging action, Current Lb = \n");
	ListDisplay_LinkNode(pLb);
	printf("After merging action, Current Lc = \n");
	ListDisplay_LinkNode(pLc);

	// ListDestroy_LinkNode(&pLa);
	// ListDestroy_LinkNode(&pLb);
	ListDestroy_LinkNode(&pLc);		// 在摧毁pLc的同时也摧毁了pLb和pLc.
	ListDisplay_LinkNode(pLc);
	// ListDisplay_LinkNode(pLa);	// 所以，pLa和pLb已经不存在了，不能打印出链表了. 
	// ListDisplay_LinkNode(pLb);
}

void TestCase_LinkNodeSort(void)
{
	ElemType iMaxValue = 0;
	char sError[256] = {0};
	PtrLinkList L = NULL;

	ListCreate_LinkNode(&L, 10);
	ListDisplay_LinkNode(L);
	iMaxValue = MaxElem_LinkNode(L, sError);

	printf("The max value among this link node is : %d\n", iMaxValue);
	ListDestroy_LinkNode(&L);
	return;
}

void TestCase_LinkNodeStatistics(void)
{
	int iNodeCnts = 0, iTargetNodeCounts = 0;
	ElemType elementUserEntered = 0;

	PtrLinkList pMyLinkList = NULL;

	printf("How many nodes do you want to create : ");
	scanf("%d", &iNodeCnts);
	ListCreate_LinkNode(&pMyLinkList, iNodeCnts);
	ListDisplay_LinkNode(pMyLinkList);

	printf("Please enter the target data which you want to do statistics : ");
	scanf("%d", &elementUserEntered);
	iTargetNodeCounts = ListStatistics_LinkNode(pMyLinkList, elementUserEntered);
	printf("\n\nTotal %d nodes have the same element as %d.\n", iTargetNodeCounts, elementUserEntered);

	ListDestroy_LinkNode(&pMyLinkList);
	return;
}

void TestCase_Merge2LinkNodes(void)
{
	PtrLinkList pLa = NULL, pLb = NULL, pLc = NULL;

	ListCreate_LinkNode(&pLa, 5);
	ListDisplay_LinkNode(pLa);
	ListCreate_LinkNode(&pLb, 8);
	ListDisplay_LinkNode(pLb);


	ListMerge_2LinkNodes(&pLa, &pLb, &pLc);
	printf("After merging step, the updated link nodes are : \n");
	printf("Link node La :\n");
	ListDisplay_LinkNode(pLa);
	printf("Link node Lb :\n");
	ListDisplay_LinkNode(pLb);
	printf("Link node Lc :\n");
	ListDisplay_LinkNode(pLc);

	ListDestroy_LinkNode(&pLc);
	return;
}