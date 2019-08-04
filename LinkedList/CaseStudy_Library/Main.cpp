/**************************************************************************************************
 * Project name	: LinkedList
 * Description	: Study the data structure of Linked-List in C++.
 * ================================================================================================
 * File name	: Main.cpp
 * Description	: This file implements the main() function for current project.
 * Creator		: Frederick Hsu
 * Creation date: Tue.	23 July 2019
 * Copyright(C)	2019	All rights reserved.
 *
 **************************************************************************************************/


#include "action.h"


int main(int argc, char* argv[])
{
	while (true)
	{
		switch (menu())
		{
		case 1:
			includeBook();
			break;
		case 2:
			checkOutBook();
			break;
		case 3:
			returnBook();
			break;
		case 4:
			status();
			break;
		case 5:
			return 0;
		default:
			cout << "Wrong option, try again: ";
			break;
		}
	}
	return 0;
}

