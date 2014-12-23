/****************************************************************************
 * File name		: Node.c
 * Description		: 定義一個廣義鏈表, 與數據成員的類型無關. 
 *					  用回調函數實現通用的鏈表查找.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Dec. 22, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ****************************************************************************/

#include "Node.h"

#include <stdlib.h>
#include <string.h>


/*==========================================================================
 * 統一的接口
 */
PNode Search_List(PNode			pList, 
				  int			(*compare)(void const *, void const *),
				  void const	*desired_value)
/* 用回調函數 compare 實現對廣義鏈表的數據成員進行比較,
 * 返回查找到鏈表結點.
 */
{
	PNode pMyNode = pList;
	while (pMyNode != NULL)
	{
		if (0 == compare(pMyNode->data_addr, desired_value))
		{
			break;
		}
		pMyNode = pMyNode->next;
	}
	return pMyNode;
}

/*==========================================================================
 * 調用者編寫的不同的回調函數
 */
int CompareIntValue(void const *a, void const *b)
{
	if (*((int *)a) == *((int *)b))		// 注意強制類型轉換
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int CompareStrValue(void const *Src, void const *Target)
{
	return strcmp((char *)Src, (char *)Target);
}
