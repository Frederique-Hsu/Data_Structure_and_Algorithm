/***************************************************************************************************
 * File name		: TestCase_Callback.c
 * Description		: 设计测试用例來測試回調函數.
 * Creator			: XU ZAN
 * Creation date	: Tue.	Dec. 23, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ***************************************************************************************************/

#include "TestCase_Callback.h"
#include "Callback.h"

#include <stdio.h>

void Test_Sort_Callback(void)
/* 測試快速排序法 :
 * 
 * 通過回調用戶自定義的外部函數來實現快速排序.
 *
 * 演示和驗證回調函數的使用.
 */
{
	int list[5] = {54, 21, 11, 67, 22};
	int i = 0;

	printf("Test the quick-sort through call-back function user defined...\n");
	printf("The original sort is : \n");
	for (i=0; i<5; i++)
	{
		printf("%d\n", list[i]);
	}
	printf("Perform the quick sorting ... \n");
	qsort((void *)list, 5, sizeof(list[0]), sort_function);
	printf("After the quick-sort, the new sort is :\n");
	for (i=0; i<5; i++)
	{
		printf("%d\n", list[i]);
	}
	return;
}