/*********************************************************************
 * File name		: Node.h
 * Description		: 研究C++的指针与复制构造函数
 * Creator			: Frederick Hsu
 * Creation date	: Wed.	02 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/

#ifndef NODE_H
#define NODE_H

 	struct Node
 	{
 		char *name;
 		int age;
 		Node(char *n = " ", int a = 0);
 		Node(const Node& n);
 		~Node(void);

 		Node& operator=(const Node& n);
 	};

#endif	/*  NODE_H  */