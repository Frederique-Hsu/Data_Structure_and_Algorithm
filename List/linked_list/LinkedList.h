/*!
 *  \file       LinkedList.h
 *  \brief
 *
 */


#pragma once

#include <stdbool.h>

#include "../pre_defines.h"

typedef int     ElemType;

typedef struct LinkedList   LinkedList;
typedef LinkedList          *LinkedListPtr;

LinkedList* InitLinkedList();

void DestroyLinkedList(LinkedList* list);

void ClearLinkedList(LinkedList* list);

bool IsLinkedListEmpty(LinkedList* list);

int LinkedListLength(LinkedList* list);

Status GetLinkedListElem(LinkedList* list, int index, ElemType* elem);

int LocateLinkedListElement(LinkedList* list,
                            ElemType    target_elem,
                            bool        (*compare)(ElemType, ElemType));

Status LinkedListPriorElem(LinkedList* list, ElemType curr_elem, ElemType* prior_elem);

Status LinkedListNextElem(LinkedList* list, ElemType curr_elem, ElemType* next_elem);

void LinkedListAppend(LinkedList* list, ElemType elem);

void DisplayLinkedList(LinkedList* list);

Status LinkedListInsert(LinkedList* list, int index, ElemType elem);

Status LinkedListDelete(LinkedList* list, int index, ElemType* elem);

void LinkedListTraverse(LinkedList* list, void (*visit)(ElemType));

void CreateLinkedListReverseOrder(LinkedList** list, int n);
void CreateLinkedListPositiveOrder(LinkedList** list, int n);

void MergeTwoLinkedLists(LinkedList*    la,
                         LinkedList*    lb,
                         LinkedList*    lc,
                         bool           (*less)(ElemType, ElemType));

/*================================================================================================*/

void CreateLinkedListWithoutHead(LinkedList** list, ElemType elem);

void DestroyLinkedListWithoutHead(LinkedList* list);

int LengthOfLinkedListWithoutHead(LinkedList* list);

void AppendToLinkedListWithoutHead(LinkedList* list, ElemType elem);

Status GetElemFromLinkedListWithoutHead(LinkedList* list, int index, ElemType* elem);

void DisplayLinkedListWithoutHead(LinkedList* list);

Status InsertIntoLinkedListWithoutHead(LinkedList** list, int at_index, ElemType elem);

Status DeleteFromLinkedListWithoutHead(LinkedList** list, int at_index, ElemType* elem);
