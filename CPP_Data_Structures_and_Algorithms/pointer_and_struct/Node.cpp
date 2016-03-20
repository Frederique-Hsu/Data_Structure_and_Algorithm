/*********************************************************************
 * File name		: Node.cpp
 * Description		: 研究C++的指针与复制构造函数
 * Creator			: Frederick Hsu
 * Creation date	: Wed.	02 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/

#include "Node.h"
#include <string>
#include <cstdlib>

using namespace std;

Node::Node(char *n, int a)
{
	name = strdup(n);
	age = a;
}

Node::Node(const Node& n)
{
	name = strdup(n.name);
	age = n.age;
}

Node& Node::operator=(const Node& n)
{
	if (this != &n)
	{
		if (name != NULL)
		{
			free(name);
		}
		name = strdup(n.name);
		age = n.age;
	}
	return *this;
}

Node::~Node(void)
{
	if (name != NULL)
		free(name);
}

