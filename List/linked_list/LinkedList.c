/*!
 *  \file       LinkedList.c
 *  \brief
 *
 */


#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

struct LinkedList
{
    ElemType            data;
    struct LinkedList*  next;
};

LinkedList* InitLinkedList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (list == NULL)
    {
        exit(OVERFLOW);
    }
    list->next = NULL;
    return list;
}

void DestroyLinkedList(LinkedList* list)
{
    while (list)
    {
        LinkedList* next_node = list->next;
        free(list);
        list = next_node;
    }
    list = NULL;
}

void ClearLinkedList(LinkedList* list)
{
    LinkedList* node = list->next;  // From the 1st node, except the head node.
    while (node)
    {
        LinkedList* tmp_node = node->next;
        free(node);
        node = tmp_node;
    }
    list->next = NULL;      // only save the head node.
}

bool IsLinkedListEmpty(LinkedList* list)
{
    if (list->next)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int LinkedListLength(LinkedList* list)
{
    int length = 0;
    LinkedList* node = list->next;  // point to the 1st node.
    while (node)
    {
        length++;
        node = node->next;
    }
    return length;
}

Status GetLinkedListElem(LinkedList* list, int index, ElemType* elem)
{
    int cnt = 1;
    LinkedList* node = list->next;
    while (node && cnt < index)
    {
        node = node->next;
        cnt++;
    }
    if ((node == NULL) || (cnt > index))
    {
        return ERROR;
    }
    *elem = node->data;
    return OK;
}

int LocateLinkedListElement(LinkedList* list,
                            ElemType    target_elem,
                            bool        (*compare)(ElemType, ElemType))
{
    int index = 0;
    LinkedList* node = list->next;
    while (node)
    {
        index++;
        if (compare(node->data, target_elem))
        {
            return index;
        }
        node = node->next;
    }
    return 0;
}

Status LinkedListPriorElem(LinkedList* list, ElemType curr_elem, ElemType* prior_elem)
{
    LinkedList* node = list->next;  // point to the 1st node
    while (node->next)
    {
        LinkedList* next_node = node->next;
        if (curr_elem == next_node->data)
        {
            *prior_elem = node->data;
            return OK;
        }
        node = node->next;
    }
    return INFEASIBLE;
}

Status LinkedListNextElem(LinkedList* list, ElemType curr_elem, ElemType* next_elem)
{
    LinkedList* node = list->next;
    while (node->next)
    {
        if (node->data == curr_elem)
        {
            *next_elem = node->next->data;
            return OK;
        }
        node = node->next;
    }
    return INFEASIBLE;
}

void LinkedListAppend(LinkedList* list, ElemType elem)
{
    LinkedList* node = list;    // For current scenario, point to the head node.
    while (node)
    {
        if (node->next == NULL)
        {
            LinkedList* new_node = (LinkedList*)malloc(sizeof(struct LinkedList));
            if (new_node == NULL)
            {
                exit(OVERFLOW);
            }
            new_node->data = elem;
            new_node->next = NULL;
            node->next = new_node;
            break;
        }
        node = node->next;
    }
}

void DisplayLinkedList(LinkedList* list)
{
    printf("\ncurrent \t\t\t data \t\t next\n");
    int position = 0;
    while (list)
    {
        if (position == 0)
        {
            printf("0x%016" PRIXPTR "\t % 16d \t 0x%016" PRIXPTR "\t <--- head node\n",
                   (uintptr_t)list,
                   list->data,
                   (uintptr_t)list->next);
        }
        else
        {
            printf("0x%016" PRIXPTR "\t % 16d \t 0x%016" PRIXPTR "\n",
                   (uintptr_t)list,
                   list->data,
                   (uintptr_t)list->next);
        }
        list = list->next;
        position++;
    }
}

Status LinkedListInsert(LinkedList* list, int index, ElemType elem)
{
    int pos = 0;
    LinkedList* node = list;
    while (node && pos < index-1)
    {
        node = node->next;
        pos++;
    }

    if ((node == NULL) || (pos > index-1))
    {
        return ERROR;
    }

    LinkedList* new_node = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (new_node == NULL)
    {
        exit(OVERFLOW);
    }
    new_node->data = elem;
    new_node->next = node->next;
    node->next = new_node;
    return OK;
}

Status LinkedListDelete(LinkedList* list, int index, ElemType* elem)
{
    int pos = 0;
    LinkedList* node = list;
    while (node && pos < index-1)
    {
        node = node->next;
        pos++;
    }

    if ((node->next == NULL) || (pos > index-1))
    {
        return ERROR;
    }
    LinkedList* node_under_delete = node->next;
    *elem = node_under_delete->data;
    node->next = node_under_delete->next;
    free(node_under_delete);
    return OK;
}

void LinkedListTraverse(LinkedList* list, void (*visit)(ElemType))
{
    while (list)
    {
        visit(list->data);
        list = list->next;
    }
    printf("\n");
}

void CreateLinkedListReverseOrder(LinkedList** list, int n)
{
    *list = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (*list == NULL)
    {
        exit(OVERFLOW);
    }
    (*list)->next = NULL;

    printf("Please enter %d number of data:\n", n);
    for (int i = 0; i < n; ++i)
    {
        LinkedList* new_node = (LinkedList*)malloc(sizeof(struct LinkedList));
        if (new_node == NULL)
        {
            exit(OVERFLOW);
        }
        scanf("%d", &new_node->data);
        new_node->next = (*list)->next;    // Insert into the head
        (*list)->next = new_node;
    }
}

void CreateLinkedListPositiveOrder(LinkedList** list, int n)
{
    *list = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (*list == NULL)
    {
        exit(OVERFLOW);
    }
    (*list)->next = NULL;

    LinkedList* node = (*list);
    printf("Please enter %d number of data:\n", n);
    for (int i = 0; i < n; ++i)
    {
        LinkedList* new_node = (LinkedList*)malloc(sizeof(struct LinkedList));
        if (new_node == NULL)
        {
            exit(OVERFLOW);
        }
        scanf("%d", &new_node->data);
        node->next = new_node;
        node = node->next;
    }
    node->next = NULL;
}

void MergeTwoLinkedLists(LinkedList*    la,
                         LinkedList*    lb,
                         LinkedList*    lc,
                         bool           (*less)(ElemType, ElemType))
{
    LinkedList* node_a = la->next;
    LinkedList* node_b = lb->next;
    LinkedList* node_c = lc;

    while (node_a && node_b)
    {
        if (less(node_a->data, node_b->data))
        {
            node_c->next = node_a;
            node_c = node_a;
            node_a = node_a->next;
        }
        else
        {
            node_c->next = node_b;
            node_c = node_b;
            node_b = node_b->next;
        }
    }
    node_c->next = (node_a != NULL) ? node_a : node_b;
}

/*================================================================================================*/

void CreateLinkedListWithoutHead(LinkedList** list, ElemType elem)
{
    LinkedList* node = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (node == NULL)
    {
        exit(OVERFLOW);
    }
    node->data = elem;
    node->next = NULL;

    *list = node;
}

void DestroyLinkedListWithoutHead(LinkedList* list)
{
    while (list)
    {
        LinkedList* next_node = list->next;
        free(list);
        list = next_node;
    }
}

int LengthOfLinkedListWithoutHead(LinkedList* list)
{
    int len = 0;
    while (list)
    {
        len++;
        list = list->next;
    }
    return len;
}

void AppendToLinkedListWithoutHead(LinkedList* list, ElemType elem)
{
    while (list->next)
    {
        list = list->next;
    }

    LinkedList* new_node = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (new_node == NULL)
    {
        exit(OVERFLOW);
    }
    new_node->data = elem;
    new_node->next = NULL;
    list->next = new_node;
}

Status GetElemFromLinkedListWithoutHead(LinkedList* list, int index, ElemType* elem)
{
    int position = 0;

    while (list && position < index-1)
    {
        position++;
        list = list->next;
    }
    if ((list == NULL) || (position > index))
    {
        return ERROR;
    }
    *elem = list->data;
    return OK;
}

void DisplayLinkedListWithoutHead(LinkedList* list)
{
    printf("\ncurrent node \t % 8s \t next node\n", "data");

    int position = 0;
    LinkedList* node = list;
    while (node)
    {
        if (position == 0)
        {
            printf("%p \t % 8d \t %p <--- start node\n", node, node->data, node->next);
        }
        else if (node->next == NULL)
        {
            printf("%p \t % 8d \t % 14p <--- end node\n", node, node->data, node->next);
        }
        else
        {
            printf("%p \t % 8d \t %p\n", node, node->data, node->next);
        }
        node = node->next;
        position++;
    }
}

Status InsertIntoLinkedListWithoutHead(LinkedList** list, int at_index, ElemType elem)
{
    int position = 0;
    LinkedList* node = *list;

    LinkedList* new_node = (LinkedList*)malloc(sizeof(struct LinkedList));
    if (new_node == NULL)
    {
        exit(OVERFLOW);
    }
    new_node->data = elem;

    if (at_index == 1)
    {
        new_node->next = node;
        (*list) = new_node;
    }
    else
    {
        while (node && position < at_index-1)
        {
            position++;
            node = node->next;
        }
        if ((node == NULL) || (position > at_index))
        {
            return ERROR;
        }
        new_node->next = node->next;
        node->next = new_node;
    }
    return OK;
}

Status DeleteFromLinkedListWithoutHead(LinkedList** list, int at_index, ElemType* elem)
{
    int position = 0;
    LinkedList* node = (*list);
    if (at_index == 1)
    {
        (*list) = node->next;
        *elem = node->data;
        free(node);
    }
    else
    {
        while (node && position < at_index-2)
        {
            position++;
            node = node->next;
        }
        if (node == NULL || position > at_index-1)
        {
            return ERROR;
        }
        LinkedList* node_under_delete = node->next;
        node->next = node_under_delete->next;
        *elem = node_under_delete->data;
        free(node_under_delete);
    }
    return OK;
}
