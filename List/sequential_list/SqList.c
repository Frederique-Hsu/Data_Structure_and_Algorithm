/*!
 *  \file       SqList.c
 *  \brief
 *
 */


#include "SqList.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void InitList(SqList* list)
{
    list->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (list->elem == NULL)
    {
        exit(OVERFLOW);
    }
    memset(list->elem, 0x00, sizeof(ElemType) * LIST_INIT_SIZE);
    list->length = 0;
    list->listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList* list)
{
    free(list->elem);
    list->elem = NULL;
    list->length = 0;
    list->listsize = 0;
}

void Display(SqList list)
{
    printf("\n");
    for (int index = 0; index < list.listsize; ++index)
    {
        printf("elem[%d] = %d\n", index, list.elem[index]);
    }
    printf("length = %d\n", list.length);
    printf("list_size = %d\n", list.listsize);
}

void ClearList(SqList* list)
{
    list->length = 0;
}

bool IsListEmpty(SqList list)
{
    if (list.length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ListLength(SqList list)
{
    return list.length;
}

Status GetElem(SqList list, int i, ElemType* elem)
{
    if ((i < 1) || (i > list.length))
    {
        return ERROR;
    }

    *elem = *(list.elem + i - 1);
    return OK;
}

int LocateElem(SqList list, ElemType elem, bool (*compare)(ElemType, ElemType))
{
    int index = 1;
    while ((index <= list.length) && (compare(elem, list.elem[index-1]) == false))
    {
        ++index;
    }

    if (index <= list.length)
    {
        return index;
    }
    else
    {
        return 0;
    }
}

Status PriorElem(SqList list, ElemType curr_elem, ElemType* prior_elem)
{
    int index = 0;
    while (index < list.length && curr_elem != list.elem[index])
    {
        ++index;
    }

    if ((index == 0) || (index >= list.listsize))
    {
        return INFEASIBLE;
    }
    else
    {
        *prior_elem = list.elem[index-1];
        return OK;
    }
}

Status NextElem(SqList list, ElemType curr_elem, ElemType* next_elem)
{
    int index = 0;
    while (index < list.length && curr_elem != list.elem[index])
    {
        ++index;
    }
    if (index == list.length)
    {
        return INFEASIBLE;
    }
    else
    {
        *next_elem = list.elem[index+1];
        return OK;
    }
}

Status ListInsert(SqList* list, int i, ElemType elem)
{
    ElemType* new_base = NULL;
    if ((i < 0) || (i > list->length))
    {
        return ERROR;
    }
    if (list->length >= list->listsize)
    {
        int total_size = list->listsize + LIST_INCREMENT;
        new_base = (ElemType*)realloc(list->elem, total_size * sizeof(ElemType));
        if (new_base == NULL)
        {
            exit(OVERFLOW);
        }
        list->elem = new_base;
        list->listsize += LIST_INCREMENT;
    }
    ElemType* pos = list->elem + i - 1;
    for (ElemType* node = list->elem + list->length - 1; node >= pos; --node)
    {
        *(node+1) = *node;
    }
    *pos = elem;
    list->length++;
    return OK;
}

Status ListDelete(SqList* list, int i, ElemType* elem)
{
    if ((i < 0) || (i > list->length))
    {
        return ERROR;
    }
    ElemType* node = list->elem + i;    // the node under deleted
    *elem = *node;

    ElemType* pos;
    for (pos = node+1; pos < list->elem + list->length; ++pos)
    {
        *(pos-1) = *pos;
    }
    *(pos-1) = 0x00;
    list->length--;
    return OK;
}

void ListTraverse(SqList list, void (*access)(ElemType))
{
    ElemType* node = list.elem;
    for (int index = 0; index < list.length; ++index)
    {
        access(*(node++));
    }
}

void ListAppend(SqList* list, ElemType elem)
{
    if (list->length >= list->listsize)
    {
        ElemType* new_base = (ElemType*)realloc(list->elem,
                                                (list->listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (new_base == NULL)
        {
            exit(OVERFLOW);
        }
        list->elem = new_base;
        *(list->elem + list->length) = elem;
        list->length++;
        list->listsize += LIST_INCREMENT;
    }
    else
    {
        *(list->elem + list->length) = elem;
        list->length++;
    }
}

void Union(SqList* alist, SqList blist)
{
    int alength = ListLength(*alist);
    int blength = ListLength(blist);

    for (int index = 0; index < blength; ++index)
    {
        ElemType belem;
        GetElem(blist, index+1, &belem);
        ListInsert(alist, alength++, belem);
    }
}
