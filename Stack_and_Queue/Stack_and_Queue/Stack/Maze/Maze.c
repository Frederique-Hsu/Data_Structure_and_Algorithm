/*********************************************************************************************
 * File name		: Maze.c
 * Description		: 編程求解“迷宮”問題.
 * Creator			: XU ZAN
 * Creation date	: Thur.	Dec. 25, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *********************************************************************************************/


#include "Maze.h"
#include "../../general.h"

#include <stdio.h>
#include <stdlib.h>

/*
 =============================================================================================
							“迷宮” 問題

		如下圖所示是一個用字符模擬出來的一個迷宮。

		10x10的迷宮, 其有一個入口[坐標位置(1, 0)]和一個出口[坐標位置(9, 8)]. 求迷宮中從入口到
		出口的所有路徑.  圖中用*表示的即為一條路徑.

		 0123456789
		0@*@@@@@@@@
		1@* @   @ @
		2@* @   @ @
		3@*   @@  @
		4@*@@@    @
		5@***@*** @
		6@ @***@**@
		7@ @@@ @@*@
		8@@    @ **     
		9@@@@@@@@@@

		迷宮問題是一個經典的程序設計問題.  用計算機求解迷宮問題, 通常用的是"窮擧求解"的方法.
		
		即: 從入口出發, 順某一方向向前探索, 若能走通, 則繼續向前走;
		否則沿着原路退回, 換一個方向再繼續探索, 直至所有可能的通路都被探索到爲止.

		爲了保證在任何位置上都能沿原路退回, 顯然需要用一個后入先出的結構來保存從入口到
		當前位置的路徑

		因此, 在迷宮通路的算法中就可以使用"棧"這種結構來實現了.


 =============================================================================================
 */

int Maze[][10] = 
/* 用0-1矩陣來模擬表示一個迷宮
 * 1 表示障礙, 不可通行; 0 表示通路,可通行.
 *
 * 後面轉換為上圖所示的字符迷宮, 同"@"來代替1, 用" "來代替0
 * 若能找到一條從入口到出口的路徑, 則用"*"來填充這條路徑.
 */
{
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{1, 1, 0, 0, 0, 0, 1, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

MazePosition Maze_Entrance = {1, 0, 0},  Maze_Exit = {9, 8, 0};

int MazePath(PtrMaze_Stack			pMazePathStack, 
			 MazePosition			entrance, 
			 MazePosition			exit, 
			 PtrFootprint_LinkNode	pFootprintLNodes)
/* 若迷宮Maze中存在從入口 Maze_Entrance 到出口 Maze_Exit 的通道，
 * 則求得一條通道存放在棧中（從棧底到棧頂），並返回TRUE，否則返回FALSE.
 */
{
	MazePosition curpos = {0, 0, 0};
	int curstep	= 0;
	
	InitMazeStack(pMazePathStack);	// 初始化迷宮通道的棧
	curpos = Maze_Entrance;		// 設定“當前位置”為“入口位置”
	curstep = 1;				// 探索第一步

	do
	{
		if (Pass(pMazePathStack, curpos))
		{
			Footprint(pFootprintLNodes, &curpos);
		}
		else
		{
		}
	}
	while (!MazeStackEmpty(pMazePathStack));

	return FALSE;
}

int DisplayMaze(void)
{
	int row_num = 0, column_num = 0, total_elem_num = 0, 
		iRowCnt = 0, iColomnCnt = 0;

	total_elem_num = sizeof(Maze)/sizeof(int);
	column_num = (sizeof(*Maze)/sizeof(int));
	row_num = total_elem_num/column_num;

	printf("Display the maze layout : \n\n\n");
	for (iRowCnt=0; iRowCnt<row_num; iRowCnt++)
	{
		for (iColomnCnt=0; iColomnCnt<column_num; iColomnCnt++)
		{
			if (Maze[iRowCnt][iColomnCnt] == 1)
			{
				printf("@");
			}
			else if (Maze[iRowCnt][iColomnCnt] == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
	return OK;
}

void DisplayMazeLayout(int *MazeMatrix, int rownum, int colnum)
{
	int iRowcnt = 0, iColcnt = 0;
	printf("Display the maze layout : \n\n\n");
	for (iRowcnt=0; iRowcnt<rownum; iRowcnt++)
	{
		for (iColcnt=0; iColcnt<colnum; iColcnt++)
		{
			if (*(MazeMatrix+iColcnt+iRowcnt*colnum) == 1)
			{
				printf("@");
			}
			else if (*(MazeMatrix+iColcnt+iRowcnt*colnum) == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
	return;
}

int InitMazeStack(PtrMaze_Stack pStackOfMaze)
{
	pStackOfMaze->stack_base = (PtrMaze_Elem_Type)calloc(MAZE_STACK_INIT_SIZE, sizeof(Maze_Elem_Type));
	pStackOfMaze->stack_top = pStackOfMaze->stack_base;
	pStackOfMaze->stack_size = MAZE_STACK_INIT_SIZE;
	pStackOfMaze->stack_actual_length = 1;
	return OK;
}

int Footprint(PtrFootprint_LinkNode FootprintLNode, MazePosition *pYourCurrentPos)
{
	PtrFootprint_LinkNode	pLNode		= FootprintLNode, 
							pNewLNode	= NULL, 
							pHeadLNode	= FootprintLNode;
	pNewLNode = (PtrFootprint_LinkNode)calloc(1, sizeof(Footprint_LinkNode));
	if (pNewLNode == NULL)
		return OVERFLOW;
	(pNewLNode->current).row_index = pYourCurrentPos->row_index;
	(pNewLNode->current).column_index = pYourCurrentPos->column_index;
	(pNewLNode->current).point = pYourCurrentPos->point;
	pNewLNode->next = NULL;

	while (pLNode->next != NULL)
	{
		pLNode = pLNode->next;
	}
	pLNode->next = pNewLNode;	// Insert as a tail node.

	pLNode = pHeadLNode;		// Return the head node pointer
	FootprintLNode = pLNode;
	return OK;
}

int Pass(PtrMaze_Stack pStack, MazePosition CurrentPosition)
{
	int iEastDirection = 0,
		iNorthDirection = 0,
		iSouthDirection = 0,
		iWestDirection = 0;

	MazeDirection eLastStepDirection = 0;

	iEastDirection	= Maze[CurrentPosition.row_index][CurrentPosition.column_index+1];
	iNorthDirection = Maze[CurrentPosition.row_index-1][CurrentPosition.column_index];
	iSouthDirection = Maze[CurrentPosition.row_index+1][CurrentPosition.column_index];
	iWestDirection	= Maze[CurrentPosition.row_index][CurrentPosition.column_index-1];

	eLastStepDirection = (pStack->stack_top-1)->direction;	// 上一個步驟的方向
	if ( (eLastStepDirection == East) && 
		 (iEastDirection == 1) && 
		  (iNorthDirection == 1) && 
		  (iSouthDirection == 1) )
	{
		return FALSE;
	}
	else if ( (eLastStepDirection == West) && 
			  (iWestDirection == 1) &&
			  (iNorthDirection == 1) &&
			  (iSouthDirection == 1) )
	{
		return FALSE;
	}
	else if ( (eLastStepDirection == South) && 
			  (iSouthDirection == 1) &&
			  (iEastDirection == 1) && 
			  (iWestDirection == 1) )
	{
		return FALSE;
	}
	else if ( (eLastStepDirection == North) &&
			  (iNorthDirection == 1) &&
			  (iEastDirection == 1) &&
			  (iWestDirection == 1) )
	{
		return FALSE;
	}
	return TRUE;
}

int MazeStackEmpty(PtrMaze_Stack MazePathStack)
{
	if ( (MazePathStack->stack_actual_length == 0) && 
		 (MazePathStack->stack_top == MazePathStack->stack_base) )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int InitMazeFootprintLinkNode(PtrFootprint_LinkNode FootprintLNode)
{
	PtrFootprint_LinkNode pLNode = (PtrFootprint_LinkNode)calloc(1, sizeof(Footprint_LinkNode));
	if (pLNode == NULL)
		return OVERFLOW;
	(pLNode->current).row_index = 0;
	(pLNode->current).column_index = 0;
	(pLNode->current).point = EMPTY;
	pLNode->next = NULL;

	FootprintLNode = pLNode;
	return OK;
}

int MakeMazeFootprintHeadNode(PtrFootprint_LinkNode pHeadNode, MazePosition MazeEntrance)
{
	(pHeadNode->current).row_index = MazeEntrance.row_index;
	(pHeadNode->current).column_index = MazeEntrance.column_index;
	(pHeadNode->current).point = MazeEntrance.point;
	return OK;
}

int DestroyMazeFootprintLinkNode(PtrFootprint_LinkNode FootprintLNode)
{
	PtrFootprint_LinkNode pTempNode = NULL;
	while (FootprintLNode != NULL)
	{
		pTempNode = FootprintLNode->next;
		free(FootprintLNode);
		FootprintLNode = pTempNode;
	}
	FootprintLNode = NULL;
	return OK;
}


Maze_Elem_Type MakeCurrentMazePosition()
{
}


void Solve_Maze_Problem(void)
{
	PtrMaze_Stack pMyMazeStack = (PtrMaze_Stack)calloc(1, sizeof(Maze_Stack));
	PtrFootprint_LinkNode pMyFootprintNode = NULL;

	InitMazeStack(pMyMazeStack);
	InitMazeFootprintLinkNode(pMyFootprintNode);

	DisplayMaze();
	MazePath(pMyMazeStack, Maze_Entrance, Maze_Exit, pMyFootprintNode);

	return;
}