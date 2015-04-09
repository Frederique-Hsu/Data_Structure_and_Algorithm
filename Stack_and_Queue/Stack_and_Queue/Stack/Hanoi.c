/*******************************************************************************************
 * File name		: Hanoi.c
 * Description		: Study the Hanoi Tower problem, demonstrate the running process of 
 *					  disk movement in Hanoi tower.
 * Creator			: Frederick Hsu
 * Creation date	: Wed.	April 01, 2015
 * Copyright(C)		2015	All rights reserved.
 *
 *******************************************************************************************/

#include "Hanoi.h"
#include <stdlib.h>
#include <stdio.h>
#include "../general.h"

static void Print_Disk_Line(int a, int b, int c);


int Create_HanoiTowerDiskStack(int n, Hanoi_Disk_Stack *disk_stack)
{
	int i = 0;
	if (NULL == (disk_stack->bottom = (int *)calloc(n, sizeof(int))))
	{
		printf("Allocating memory failed.");
		return OVERFLOW;
	}
	for (i=0; i<n; i++)
	{
		*((disk_stack->bottom) + i) = n-i;
	}
	disk_stack->top = disk_stack->bottom + n-1;
	disk_stack->stacksize = n;
	disk_stack->actual_length = n;

	return OK;
}

int Create_EmptyHanoiTowerDiskStack(int n, Hanoi_Disk_Stack *empty_disk_stack)
{
	int i = 0;
	if (NULL == (empty_disk_stack->bottom = (int *)calloc(n, sizeof(int))))
	{
		printf("Allocating memory failed.");
		return OVERFLOW;
	}
	for (i=0; i<n; i++)
	{
		*((empty_disk_stack->bottom) + i) = 0;
	}
	empty_disk_stack->top = empty_disk_stack->bottom + n - 1;
	empty_disk_stack->stacksize = n;
	empty_disk_stack->actual_length = 0;

	return OK;
}

void Destroy_HanoiTowerDiskStack(Hanoi_Disk_Stack *disk_stack)
{
	free(disk_stack->bottom);
	disk_stack->top = NULL;
	disk_stack->stacksize = 0;
	disk_stack->actual_length = 0;
	disk_stack->bottom = NULL;
	return;
}

void Display_HanoiTowerDiskStack(Hanoi_Disk_Stack disk_stack)
{
	int len = disk_stack.actual_length, size = disk_stack.stacksize, i = 0;
	printf("          ------------------\n");
	for (i=size-1; i>=0; i--)
	{
		if (i>len)
		{
			printf("          |                |\n");
			printf("          ------------------\n");
		}
		else
		{
			if (i == disk_stack.actual_length-1)
			{
				printf("top------>|       %d       |\n", *(disk_stack.bottom + i));
				printf("          ------------------\n");
			}
			else if (i==0)
			{
				printf("bottom--->|       %d       |\n", *(disk_stack.bottom + i));
				printf("          ------------------\n");
			}
			else
			{
				printf("          |       %d       |\n", *(disk_stack.bottom + i));
				printf("          ------------------\n");
			}
		}
	}
	return;
}


void Display_3ParallelHanoiTowers(Hanoi_Disk_Stack	source, 
								  Hanoi_Disk_Stack	auxiliary,
								  Hanoi_Disk_Stack	target)
{
	int size = source.stacksize, i = 0;

	printf("   3 Hanoi Towers :\n");
	printf("-----------------------------------------\n");
	printf(" Source          Aux.            Target  \n");
	printf("---------       ---------       ---------\n");

	for (i=size-1; i>=0; i--)
	{
		Print_Disk_Line(*(source.bottom+i), *(auxiliary.bottom+i), *(target.bottom+i));
		printf("---------       ---------       ---------\n");
	}
	printf("\n\n\n");
}

static void Print_Disk_Line(int a, int b, int c)
{
	char str[64] = {0}, str1[128] = {0}, str2[256] = {0};
	if (a == 0)
	{
		sprintf(str, "|	|");
	}
	else
	{
		sprintf(str, "| %d	|", a);
	}
	if (b == 0)
	{
		sprintf(str1, "%s	|	|", str);
	}
	else
	{
		sprintf(str1, "%s	| %d	|", str, b);
	}
	if (c == 0)
	{
		sprintf(str2, "%s	|	|\n", str1);
	}
	else
	{
		sprintf(str2, "%s	| %d	|\n", str1, c);
	}

	printf(str2);
	return;
}


int Push_HanoiTowerDiskStack(Hanoi_Disk_Stack *disk_stack, int elem)
{
	int len = disk_stack->actual_length, size = disk_stack->stacksize;

	/*
	if (disk_stack->actual_length != (disk_stack->top - disk_stack->bottom)/sizeof(int))
	{
		printf("The disk stack of current Hanoi tower is crashed.");
		return ERROR;
	}
	 */

	if (disk_stack->actual_length >= disk_stack->stacksize)		// Disk Stack is over
	{
		disk_stack->bottom = (int *)realloc(disk_stack->bottom, size+1);
		*(disk_stack->bottom + size) = elem;
		disk_stack->top = disk_stack->bottom + size;
		disk_stack->actual_length = len+1;
		disk_stack->stacksize = size+1;
	}
	else		// Disk stack space is enought, not over.
	{
		*(disk_stack->bottom + len) = elem;
		disk_stack->top = disk_stack->bottom + len;
		disk_stack->actual_length = len + 1;
	}

	return OK;
}

int Pop_HanoiTowerDiskStack(Hanoi_Disk_Stack *disk_stack, int *elem)
{
	int len = disk_stack->actual_length, size = disk_stack->stacksize;

	*elem = *(disk_stack->top);
	disk_stack->actual_length -= 1;
	*(disk_stack->top) = 0;		// Reset the top to 0
	disk_stack->top -= 1;

	return OK;
}

void move(Hanoi_Disk_Stack	*source_tower, 
		  int				disk_n, 
		  Hanoi_Disk_Stack	*target_tower)
{
	int elem = 0;
	Pop_HanoiTowerDiskStack(source_tower, &elem);

	if (elem != disk_n)
	{
		printf("Error : The stack top element of source_tower NOT equal to the nth of disk.");
	}

	Push_HanoiTowerDiskStack(target_tower, elem);
}

int Check_HanoiTowerDiskOverlapRule(Hanoi_Disk_Stack disk_stack)
{
	int len = disk_stack.actual_length, size = disk_stack.stacksize;
	int i = 0;
	int result = 0;

	for (i=size; i>1; i--)
	{
		if ((*(disk_stack.bottom+i-1)) >= (*(disk_stack.bottom+i-2)))
		{
			result = -1;
			break;
		}
		else
		{
			result = 0;
		}
	}
	return result;
}