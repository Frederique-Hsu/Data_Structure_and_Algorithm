/****************************************************************************
 * File name		: Node.h
 * Description		: 定義一個廣義鏈表, 與數據成員的類型無關. 
 *					  用回調函數實現通用的鏈表查找.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Dec. 22, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ****************************************************************************/


#ifndef NODE_H
#define NODE_H

	typedef struct List
	{
		void *data_addr;
		struct List *next;
	}
	Node,	*PNode;

	PNode Search_List(PNode			pList, 
					  int			(*compare)(void const *, void const *),
					  void const	*desired_value);

	int CompareIntValue(void const *a, void const *b);
	int CompareStrValue(void const *Src, void const *Target);


#endif	/*  NODE_H  */