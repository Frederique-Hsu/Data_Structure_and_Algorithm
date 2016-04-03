/*************************************************************************************************
 * File name	: test.cpp
 * Description	: Design and perform test cases.
 * Creator		: Fredericks Hsu
 * Creation date: Tue.	29 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *************************************************************************************************/


#include "test.h"
#include "database.h"
#include "personal.h"
#include "student.h"

void performProjectTestCases(void)
{
	testCase4RandomAccessFile();
	return;
}

void testCase4RandomAccessFile(void)
{
	Database<Personal>().run();
	// test.run();

	// Database<Student>().run();

	return;
}