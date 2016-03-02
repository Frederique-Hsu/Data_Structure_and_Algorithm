/*******************************************************************************************
 * File name		: Test_Hanoi.c
 * Description		: Demonstrate and validate the Hanoi tower disk stack.
 * Creator			: Frederick Hsu
 * Creation date	: Thur.	April 02, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *******************************************************************************************/

#include "Hanoi.h"
#include <stdio.h>
#include <stdlib.h>

void Demonstrate_Hanoi_Tower(void)
{
	int n = 3;

	Hanoi_Disk_Stack source_tower	= {NULL, NULL, 0, 0},
					 aux_tower		= {NULL, NULL, 0, 0},
					 target_tower	= {NULL, NULL, 0, 0};
	int status = 0;

	status = Create_HanoiTowerDiskStack(n, &source_tower);
	// Display_HanoiTowerDiskStack(source_tower);

#if 1
	Create_EmptyHanoiTowerDiskStack(n, &aux_tower);
	Create_EmptyHanoiTowerDiskStack(n, &target_tower);
#else
	Create_HanoiTowerDiskStack(n, &aux_tower);
	Create_HanoiTowerDiskStack(n, &target_tower);
#endif

	Trigger2RefreshDisplay(source_tower, aux_tower, target_tower);
	Hanoi(n, &source_tower, &aux_tower, &target_tower);
	PrintHanoiTowerTotalRecursionSteps(n);
}