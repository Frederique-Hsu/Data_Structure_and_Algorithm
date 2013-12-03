/*****************************************************************************
 * File name	: Testing_SeqList.cpp
 * Description	: To carry out the testing case for Sequence List structure.
 * Creator		: XU ZAN
 * Creation date: Mon.	Dec. 02, 2013
 * Copyright(C)		2013	All rights reserved.
 *
 *****************************************************************************/

#include "Testing_SeqList.h"
#include "Linear_List.h"
#include <stdlib.h>

void General_Testing(void)
{
	TestingCase_SeqList_Structure();

	return;
}

int TestingCase_SeqList_Structure(void)
/* 測試順序表的基本操作
 */
{
	SqList L;
	Status iResult = 0;

	iResult = InitList_Sq(L);	// 初始化順序表
	if (iResult != OK)
		return iResult;

	iResult = ListInsert_Sq(L, 1, 10);	// 插入第1個元素(值為10)
	iResult = ListInsert_Sq(L, 2, 25);	// 插入第2個元素(值為25)
	iResult = ListInsert_Sq(L, 3, 8);	// 插入第3個元素(值為8)
	iResult = ListInsert_Sq(L, 4, 100);	// 插入第4個元素(值為100)

	ListDisplay_Sq(L);

	iResult = ListInsert_Sq(L, 2, 20);	// 插入第2個元素(值為20)

	ListDisplay_Sq(L);

	iResult = ListInsert_Sq(L, 4, -5);	// 插入第4個元素(值為-5)

	ListDisplay_Sq(L);		// 列印出順序表中的元素及其每個元素所對應的内存地址

	return iResult;
}