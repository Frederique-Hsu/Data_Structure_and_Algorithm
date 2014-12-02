/**************************************************************
 * File name		: Link_Node.c
 * Description		: 链表
 * Creator			: XU ZAN
 * Creation date	: Thu.	Nov. 20, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 **************************************************************/

#include "Link_Node.h"

#include <stdio.h>
#include <stdlib.h>

Status	InitList(LinkList *L)
/* 构造一个空的线性链表L
 */
{
	Link pLinkNode = NULL;
	pLinkNode = (Link)calloc(1, sizeof(LNode));		/* If you use calloc() function,
													 * every member of struct will be initialized to 0 (pointer member was assigned NULL).
													 * But if you use malloc() or realloc() function, you should assign the member manually.
													 */
	if (pLinkNode == NULL)	// Allocating memory failed.
		return ERROR;
	pLinkNode->next = NULL;

	L->head = pLinkNode;
	L->tail = pLinkNode->next;	// Actually tail node is NULL.
	L->len = 1;
	return OK;
}

/**************************************************************/
Status	DestroyList(LinkList *L)
/* 销毁线性链表L，L不再存在
 */
{
	Link pLNode = L->head,	// To get the head node of link-node.
		 pHeadNode = L->head,	// Stage the head node.
		 pTailNode = L->tail;	// Stage the tail node
	void *pTemp = NULL;

	if (pLNode == NULL)
	{
		printf("The link list is already empty.\n");
		return OK;
	}
	
	while (pLNode != NULL)
	{
		pTemp = pLNode->next;
		free(pLNode);
		pLNode = pTemp;
	}
	L->head = pLNode;
	L->tail = pLNode;
	L->len = 0;

	return OK;
}

/**************************************************************/
Status	MakeNode(Link *p, ElemType e)
/* 分配由p指向的值为e的结点
 * 若分配成功，返回OK; 分配失败，则返回ERROR
 */
{
	Link pNode = (Link)calloc(1, sizeof(LNode));
	if (pNode == NULL)
	{
		printf("Created a new node failed. Allocation error.\n");
		return ERROR;
	}
	pNode->data = e;

	*p = pNode;
	return OK;
}

/**************************************************************/
void	FreeNode(Link *p)
/* 释放p所指结点
 */
{
	Link pNode = *p;

	pNode->next = NULL;
	free(pNode);
	pNode = NULL;
	return;
}

/**************************************************************/
Status	ClearList(LinkList *L)
/* 将线性链表L重置为空表，并释放原链表的结点空间
 */
{
	Link pNode	= L->head;
	void *pTemp = NULL;

	while (pNode != NULL)
	{
		pTemp = pNode->next;
		free(pNode);
		L->len--;
		pNode = pTemp;
	}
	L->head = NULL;
	L->tail = NULL;

	return OK;
}

void	DisplayList(Link L)
{
	int iCnt = 1;
	printf("#	| Current		| Data		| Next		\n");
	printf("----------------------------------------------------------------------\n");
	while (L != NULL)
	{
		printf("%d	| 0x%08X		| %d		| 0x%08X		\n",
			   iCnt, L, L->data, L->next);
		printf("----------------------------------------------------------------------\n");
		L = L->next;
		iCnt++;
	}
	printf("\n\n");
	return;
}

void	DisplayLinkList(LinkList List)
{
	int iCnt = 1;
	Link pNode = List.head;
	printf("Link List structure :\n");
	printf("Node	| #		| Current		| Data		| Next		\n");
	printf("-------------------------------------------------------------------------------\n");
	while (pNode != NULL)
	{
		if (pNode == List.head)
		{
			printf("Head	| %d	| 0x%08X	| %d	| 0x%08X	\n",
				   iCnt, pNode, pNode->data, pNode->next);
		}
		else if (pNode == List.tail)
		{
			printf("Tail	| %d	| 0x%08X	| %d	| 0x%08X	\n",
				   iCnt, pNode, pNode->data, pNode->next);
		}
		else
		{
			printf("		| %d	| 0x%08X	| %d	| 0x%08X	\n",
				   iCnt, pNode, pNode->data, pNode->next);
		}
		printf("-------------------------------------------------------------------------------\n");
		pNode = pNode->next;
		iCnt++;
	}
	printf("Length	| total %d nodes	\n", List.len);
	printf("-------------------------------------------------------------------------------\n");
	printf("\n\n");
	return;
}

Status	InsFirst(Link h, Link s)
/* 已知h指向线性链表的头结点, 将s所指结点插入都在第一个结点之前.
 */
{
	Link pHead = h;
	s->next = h;
	pHead = s;
	h = pHead;

	return OK;
}

Status	DelFirst(Link h, Link *q)
/* 已知h指向线性链表的头节点, 删除链表中的第一个结点
 * 并以q返回.
 */
{
	Link pNode = h->next,	// point to the next node of head node.
		 pHead = h;

	*q = pHead;
	free(pHead);

	h = pNode;
	return OK;
}

Status	Append(LinkList *L, Link s)
/* 将指针s所指(彼此以指针相连)的一串结点链接在线性链表L的最后一个结点之后,
 * 并改变链表L的尾指针指向新的尾结点.
 */
{
	int iLen = GetLinkNodeLength(s);
	Link pNode = NULL, pLinkNode = L->head;
	ElemType e = 0;
	
	while (pLinkNode != NULL)		// Move to the end of link node "L->head"
	{
		pLinkNode = pLinkNode->next;
	}
	pLinkNode = s;

	GetSpecifiedNode(s, iLen, &pNode, &e);
	L->tail = pNode;
	L->len = L->len + iLen;
	return OK;
}

int GetLinkNodeLength(Link s)
/* 获取链表的结点个数,即链表长度
 */
{
	int nCnt = 0;
	while (s != NULL)
	{
		nCnt++;
		s = s->next;
	}
	return nCnt;
}

Status GetSpecifiedNode(Link		s, 
						int			n, 
						Position	*PosOfNode, 
						ElemType	*e)
/* 获取第n个结点的指针, 并返回其数据成员.
 */
{
	Position pNodePos = s;
	int iLen = GetLinkNodeLength(s), iCnt = 0;

	if ((n<=0) || (n>=(iLen+1)))
	{
		return ERROR;
	}
	while ((iCnt<=n) && (pNodePos))
	{
		iCnt++;
		pNodePos = pNodePos->next;
	}
	*PosOfNode = pNodePos;
	*e = pNodePos->data;

	return OK;
}

Status	Remove(LinkList *L, Link *q)
/* 删除线性链表L中的尾结点并以q返回,
 * 改变链表L的尾指针指向新的尾结点.
 */
{
	Link pNode = L->head, pTemp = NULL;
	while (pNode->next != L->tail)		// Move to the previous node of tail node
	{
		pNode = pNode->next;
	}
	*q = pNode->next;		// Current pNode->next is exactly the tail node.
	/* Stage the tail node, 
	 * but currently pNode is still remained the previous node of tail node
	 */
	pTemp = pNode->next;
	free(pTemp);			// Then free the tail node.
	/* At this moment, pNode was changed-over as the tail node.
	 */
	L->tail = pNode;	// Assign the tail node pointer to L's tail member.
	pNode->next = NULL;	// Meanwhile must assign the next of tail node to be NULL.

	return OK;
}