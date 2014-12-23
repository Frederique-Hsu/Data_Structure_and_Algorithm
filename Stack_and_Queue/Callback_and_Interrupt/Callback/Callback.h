/***************************************************************************************
 * File name		: Callback.h
 * Description		: Study the call-back mechanism, how to program the call-back in C.
 * Creator			: XU ZAN
 * Creation date	: Mon.	Dec. 22, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 ***************************************************************************************/


#ifndef CALLBACK_H
#define CALLBACK_H

	#include <stddef.h>
	/**
	 
	 什么是回调 

	 软件模块之间总是存在着一定的接口，从调用方式上，可以把他们分为三类：
	 同步调用、回调和异步调用。
	 
	 同步调用是一种阻塞式调用，调用方要等待对方执行完毕才返回，它是一种单向调用；
	 回调是一种双向调用模式，也就是说，被调用方在接口被调用时也会调用对方的接口；
	 异步调用是一种类似消息或事件的机制，不过它的调用方向刚好相反，接口的服务在
	 收到某种讯息或发生某种事件时，会主动通知客户方（即调用客户方的接口）。
	 
	 回调和异步调用的关系非常紧密，通常我们使用回调来实现异步消息的注册，
	 通过异步调用来实现消息的通知。
	 
	 同步调用是三者当中最简单的，而回调又常常是异步调用的基础.

	 通常，当我们想通过一个统一接口实现不同内容的时候，用回调函数来实现就非常合适。
	 任何时候，如果你所编写的函数必须能够在不同的时刻执行不同的类型的工作或者执行只能
	 由函数调用者定义的工作，你都可以用回调函数来实现。许多窗口系统就是使用回调函数
	 连接多个动作，如拖拽鼠标和点击按钮来指定调用用户程序中的某个特定函数。

	 */


/*=================================================================================================*/

	/* 面向過程的語言(如C語言)的回調機制.
	 *
	 *
	 * 函數指針:
	 * 回調在C語言中是通過函數指針來實現的, 通過將回調函數的地址傳給被調用函數,從而實現回調.
	 * 因此,要實現回調,必須首先定義函數指針
	 */

	void Func(char *s);		// 函數原形
	void (*pFunc)(char *);	// 函數指針

	typedef void	(*pCallBack)(char *);

	void Demo_Call_Back_Mechanism(void);
	void GetCallBack(pCallBack callback);
	void fCallback(char *s);


#if 0
	/* 參數傳遞規則
	 */
	__stdcall int callee(int);					// 被調用函數是以int為參數， 以int為返回值
	void caller(__cdecl int (*ptr)(int));		// 調用函數以函數指針為參數
	// 在p中企圖存儲被調用函數地址的非法操作
	__cdecl int (*p)(int) = callee;				// 將會出錯

	/* 指針p和callee()的類型不兼容，因爲他們有不同的調用規範 __stdcall 與 __cdecl 調用規範不同.
	 * 因此不能將被調用者的地址賦值給指針p.
	 * 儘管兩者有相同的返回值和參數列.
	 */
#endif

	/***********************************************************************************
	 *
	 * C語言的標準庫函數中很多地方就採用回調函數來讓用戶定制處理過程.
	 * 如常用的快速排序函數和二分搜索函數等
	 *
	 * 如下的兩個函數 qsort 和 bsearch 中的參數 fcmp 就是一個回調函數來作爲參數變量.
	 */
	// 快速排序法函數原型
	void qsort(void		*base,
			   size_t	nelem,
			   size_t	width,
			   int		(__cdecl *fcmp)(const void *, const void *));
	// 二分搜索法函數原型
	void *bsearch(const void	*key,
				  const void	*base,
				  size_t		nelem,
				  size_t		width,
				  int			(__cdecl *fcmp)(const void *, const void *));

	int sort_function(const void *a, const void *b);

#endif	/*  CALLBACK_H  */