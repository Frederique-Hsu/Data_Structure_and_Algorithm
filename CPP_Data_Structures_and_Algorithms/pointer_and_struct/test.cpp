/*********************************************************************
 * File name		: test.cpp
 * Description		: Perform the test cases.
 * Creator			: Frederick Hsu
 * Creation date	: Wed.	02 March, 2016
 * Copyright(C)		2016	All rights reserved.
 *
 *********************************************************************/

#include "test.h"
#include "Node.h"
#include <cstring>
#include <iostream>


void performTestCases(void)
{
	Node node1("Roger", 20), node2(node1);

	std::strcpy(node2.name, "Wendy");
	node2.age = 30;
	std::cout<<node1.name<<" "<<node1.age<<std::endl;
	std::cout<<node2.name<<" "<<node2.age<<std::endl;

	return;
}