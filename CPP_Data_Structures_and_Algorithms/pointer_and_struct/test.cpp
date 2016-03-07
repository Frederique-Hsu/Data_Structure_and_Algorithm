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
#include "quoted_variable.h"
#include "RefClass.h"
#include "function_pointer.h"

#include <cstring>
#include <iostream>
#include <cmath>

void performTestCases(void)
{
	performStructTestCases();
	performQuotedVariable();
	destroyEncapsulationbByQuotedVariable();
	testFunctionPointer();
}

void performStructTestCases(void)
{
	Node node1("Roger", 20), node2(node1), node3;

	std::strcpy(node2.name, "Wendy");
	node2.age = 30;
	std::cout<<node1.name<<" "<<node1.age<<std::endl;
	std::cout<<node2.name<<" "<<node2.age<<std::endl;

	node3 = node1;
	std::cout<<node3.name<<" "<<node3.age<<std::endl;

	return;
}

void performQuotedVariable(void)
{
	int n1 = 4, n2 = 5, n3 = 6;
	func1(n1, &n2, n3);
	std::cout<<"n1 = "<<n1<<"\n"
			 <<"n2 = "<<n2<<"\n"
			 <<"n3 = "<<n3<<std::endl;

/********************************************************/

	int a[] = {1, 2, 3, 4, 5, 8, -10, 0, 25}, n = 0;
	n = func2(a, 2);
	std::cout<<"n = "<<n<<std::endl;
	func2(a, 4) = 6;
	std::cout<<"a[4] = "<<a[4]<<std::endl;

	*func3(a, 7) = 100;
	std::cout<<"a[7] = "<<a[7]<<std::endl;

/********************************************************/
	return;
}

void destroyEncapsulationbByQuotedVariable(void)
{
	RefClass obj;
	int& k = obj.getRefN();
	std::cout<<"k = "<<k<<std::endl;

	k = 7;
	std::cout<<"Currently the private member n = "<<obj.getN()<<std::endl;

	obj.getRefN() = 16;
	std::cout<<"The private member had been changed to n = "<<obj.getN()<<std::endl;
}

void testFunctionPointer(void)
{
	std::cout<<std::endl;
	std::cout<<"Test cases for the function pointer : "<<std::endl;

	std::cout<<"Sum(sin(3) ... sin(10)) = "<<sum(std::sin, 3, 7)<<std::endl;

	std::cout<<"Find the root of an equation : f(x) = x^2 -5x +6 = 0 "<<std::endl;
	std::cout<<"The root is : "<<root(mathFunc_x, 2.1, 9.9, 0.00001)<<std::endl;
	return;
}
