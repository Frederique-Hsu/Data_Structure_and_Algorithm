/*************************************************************************************************************
 * File name		: Hanoi_Tower_Problem.c
 * Description		: Solve the "Hanoi Tower Problem" by using the recursion algorithm.
 * Creator			: Frederick Hsu
 * Creation date	: Fri.	April 03, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *************************************************************************************************************/

#include "Hanoi.h"
#include <stdio.h>


unsigned long long int gTotalRecursiveSteps = 1;

void Hanoi(int				nDisks, 
		   Hanoi_Disk_Stack	*source_tower,		// x
		   Hanoi_Disk_Stack *aux_tower,			// y
		   Hanoi_Disk_Stack *target_tower)		// z
{
	gTotalRecursiveSteps++;
	if (nDisks == 1)
	{
		move(source_tower, 1, target_tower);
		Trigger2RefreshDisplay(*source_tower, *aux_tower, *target_tower);
	}
	else
	{
		Hanoi(nDisks-1, source_tower, target_tower, aux_tower);
		Trigger2RefreshDisplay(*source_tower, *aux_tower, *target_tower);
		move(source_tower, nDisks, target_tower);
		
		Trigger2RefreshDisplay(*source_tower, *aux_tower, *target_tower);
		
		Hanoi(nDisks-1, aux_tower, source_tower, target_tower);
		Trigger2RefreshDisplay(*aux_tower, *source_tower, *target_tower);
	}
	Trigger2RefreshDisplay(*source_tower, *aux_tower, *target_tower);
}

void Trigger2RefreshDisplay(Hanoi_Disk_Stack source_tower,
							Hanoi_Disk_Stack aux_tower,
							Hanoi_Disk_Stack target_tower)
{
	Display_3ParallelHanoiTowers(source_tower, aux_tower, target_tower);
	printf("Next step");
	getchar();
}

void PrintHanoiTowerTotalRecursionSteps(int n)
{
	printf("\n\n");
	printf("Hanoi tower (%d disks) had executed %llu recursion steps.\n", n, gTotalRecursiveSteps);
	gTotalRecursiveSteps = 1;	// Restore to initial value.
}