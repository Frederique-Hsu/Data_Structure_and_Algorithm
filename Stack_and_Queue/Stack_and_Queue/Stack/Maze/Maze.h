/*********************************************************************************************
 * File name		: Maze.h
 * Description		: 編程求解“迷宮”問題.
 * Creator			: XU ZAN
 * Creation date	: Thur.	Dec. 25, 2014
 * Copyright(C)		2014	All rights reserved.
 *
 *********************************************************************************************/


#ifndef MAZE_H
#define MAZE_H

	#define MAZE_STACK_INIT_SIZE	5
	#define MAZE_STACK_INCREMENT	1

	enum MazePoint
	{
		EMPTY	= 0,
		WALL	= 1
	};

	typedef struct MazePosition
	{
		int row_index;			// 行坐標
		int column_index;		// 列坐標
		enum MazePoint point;	// 該點的值
	}
	MazePosition, *PtrMazePosition;

	typedef struct Footprint_LinkNode
	{
		MazePosition current;
		struct Footprint_LinkNode *next;
	}
	Footprint_LinkNode, *PtrFootprint_LinkNode;

	typedef enum Direction		// 迷宮中行走的方向
	{
		North,
		South,
		East,
		West
	}
	MazeDirection;

	typedef struct Maze_Elem_Type
	{
		int order;						// 通道塊在路經上的“序號”
		MazePosition maze_coordinate;	// 通道塊在迷宮中的“坐標位置”
		MazeDirection direction;		// 從此通道塊走向下一通道塊的“方向”
	}
	Maze_Elem_Type, *PtrMaze_Elem_Type;

	typedef struct Maze_Stack			// 迷宮棧模型
	{
		Maze_Elem_Type *stack_top;
		Maze_Elem_Type *stack_base;
		int stack_size;
		int stack_actual_length;
	}
	Maze_Stack, *PtrMaze_Stack;

	void Solve_Maze_Problem(void);

	int MazePath(PtrMaze_Stack			pMazePathStack, 
				 MazePosition			entrance, 
				 MazePosition			exit, 
				 PtrFootprint_LinkNode	pFootprintLNodes);

	int DisplayMaze(void);
	void DisplayMazeLayout(int *azeMatrix, int rownum, int colnum);

	int InitMazeStack(PtrMaze_Stack pStackOfMaze);
	
	int Footprint(PtrFootprint_LinkNode FootprintLNode, MazePosition *pYourCurrentPos);
	
	int Pass(PtrMaze_Stack pStack, MazePosition CurrentPosition);
	
	MazePosition NextPos(MazePosition curpos, int iStepSize);
	
	int MazeStackEmpty(PtrMaze_Stack MazePathStack);
	
	Maze_Elem_Type MakeCurrentMazePosition();
	
	int PushMazeStack(PtrMaze_Stack pStackOfMaze, Maze_Elem_Type elem);

	int InitMazeFootprintLinkNode(PtrFootprint_LinkNode FootprintLNode);
	
	int DestroyMazeFootprintLinkNode(PtrFootprint_LinkNode FootprintLNode);

#endif	/*  MAZE_H  */