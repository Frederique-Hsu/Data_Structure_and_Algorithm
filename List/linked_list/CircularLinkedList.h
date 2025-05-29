/*!
 *  \file       CircularLinkedList.h
 *  \brief      Study the structure of circular linked list.
 *
 */


#pragma once

#include <stdbool.h>

#include "../pre_defines.h"

typedef int     ElemType;

typedef struct CircularLinkedList
{
    ElemType                    data;
    struct CircularLinkedList   *next;
} CircularLinkedList, *CircularLinkedListPtr;

void InitCircularLinkedList(CircularLinkedList** circ_list);
void DestroyCircularLinkedList(CircularLinkedList* circ_list);
void ClearCircularLinkedList(CircularLinkedList* circ_list);
int LengthOfCircularinkedList(CircularLinkedList* circ_list);
void AppendToCircularLinkedList(CircularLinkedList* circ_list, ElemType elem);
void DisplayCircularLinkedList(CircularLinkedList* circ_list);
bool IsCircularLinkedListEmpty(CircularLinkedList* circ_list);
Status GetElemFromCircularLinkedList(CircularLinkedList* circ_list, int index, ElemType* elem);
bool FindElemPositionFromCircularLinkedList(CircularLinkedList* circ_list,
                                            ElemType            target_elem,
                                            int*                position);
