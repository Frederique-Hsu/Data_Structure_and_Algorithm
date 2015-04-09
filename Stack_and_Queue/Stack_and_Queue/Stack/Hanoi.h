/*******************************************************************************************
 * File name		: Hanoi.h
 * Description		: Study the Hanoi Tower problem, demonstrate the running process of 
 *					  disk movement in Hanoi tower.
 * Creator			: Frederick Hsu
 * Creation date	: Wed.	April 01, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *******************************************************************************************/


#ifndef HANOI_H
#define HANOI_H

	typedef struct Hanoi_Disk_Stack
	{
		int *top;
		int *bottom;
		int stacksize;
		int actual_length;
	}
	Hanoi_Disk_Stack, *PtrHanoi_Disk_Stack;

	int Create_HanoiTowerDiskStack(int n, Hanoi_Disk_Stack *disk_stack);
	
	int Create_EmptyHanoiTowerDiskStack(int n, Hanoi_Disk_Stack *empty_disk_stack);

	void Destroy_HanoiTowerDiskStack(Hanoi_Disk_Stack *disk_stack);
	
	void Display_HanoiTowerDiskStack(Hanoi_Disk_Stack disk_stack);
	
	void Display_3ParallelHanoiTowers(Hanoi_Disk_Stack	source, 
									  Hanoi_Disk_Stack	auxiliary,
									  Hanoi_Disk_Stack	target);

	int Push_HanoiTowerDiskStack(Hanoi_Disk_Stack *disk_stack, int elem);
	int Pop_HanoiTowerDiskStack(Hanoi_Disk_Stack *disk_stack, int *elem);
	
	int Check_HanoiTowerDiskOverlapRule(Hanoi_Disk_Stack disk_stack);

	void Hanoi(int				nDisks, 
			   Hanoi_Disk_Stack	*source_tower, 
			   Hanoi_Disk_Stack *aux_tower, 
			   Hanoi_Disk_Stack *target_tower);

	void move(Hanoi_Disk_Stack	*source_tower, 
			  int				disk_n, 
			  Hanoi_Disk_Stack	*target_tower);

	void Trigger2RefreshDisplay(Hanoi_Disk_Stack source_tower,
								Hanoi_Disk_Stack aux_tower,
								Hanoi_Disk_Stack target_tower);

	void PrintHanoiTowerTotalRecursionSteps(int n);

#endif	/*  HANOI_H  */