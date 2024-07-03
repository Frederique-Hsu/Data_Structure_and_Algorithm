/*!
 *  \file       SqList.h
 *  \brief
 *
 */


#pragma once

#include "../pre_defines.h"

#define LIST_INIT_SIZE      10
#define LIST_INCREMENT      2


typedef int     ElemType;

typedef struct SqList
{
    ElemType*   elem;
    int         length;
    int         listsize;
}
SqList, *SqListPtr;

void InitList(SqList* list);
void DestroyList(SqList* list);
void Display(SqList list);
void ClearList(SqList* list);
bool IsListEmpty(SqList list);
int ListLength(SqList list);
Status GetElem(SqList list, int i, ElemType* elem);
int LocateElem(SqList list, ElemType elem, bool (*compare)(ElemType, ElemType));
Status PriorElem(SqList list, ElemType curr_elem, ElemType* prior_elem);
Status NextElem(SqList list, ElemType curr_elem, ElemType* next_elem);
Status ListInsert(SqList* list, int i, ElemType elem);
Status ListDelete(SqList* list, int i, ElemType* elem);
void ListTraverse(SqList list, void (*access)(ElemType));
void ListAppend(SqList* list, ElemType elem);
void Union(SqList* alist, SqList blist);
