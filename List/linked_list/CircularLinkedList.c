/*!
 *  \file       CircularLinkedList.c
 *  \brief
 *
 */


#include "CircularLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

void InitCircularLinkedList(CircularLinkedList** circ_list)
{
    CircularLinkedList* node = (CircularLinkedList*)malloc(sizeof(struct CircularLinkedList));
    if (node == NULL)
    {
        exit(OVERFLOW);
    }
    node->next = node;
    *circ_list = node;
}

void DestroyCircularLinkedList(CircularLinkedList* circ_list)
{
    CircularLinkedList* node = circ_list->next;
    while (node != circ_list)   // go through till the head node
    {
        CircularLinkedList* next_node = node->next;
        free(node);
        node = next_node;
    }
    free(circ_list);
    circ_list = NULL;
}

int LengthOfCircularinkedList(CircularLinkedList* circ_list)
{
    int len = 0;
    CircularLinkedList* node = circ_list->next;
    while (node != circ_list)
    {
        len++;
        node = node->next;
    }
    return len;
}

void AppendToCircularLinkedList(CircularLinkedList* circ_list, ElemType elem)
{
    CircularLinkedList* new_node = (CircularLinkedList*)malloc(sizeof(struct CircularLinkedList));
    if (new_node == NULL)
    {
        exit(OVERFLOW);
    }
    new_node->data = elem;

    CircularLinkedList* node = circ_list->next;
    while (node->next != circ_list)
    {
        node = node->next;
    }
    node->next = new_node;
    new_node->next = circ_list;
}

void DisplayCircularLinkedList(CircularLinkedList* circ_list)
{
    printf("\ncurrent node \t % 8s \t next node\n", "data");
    printf("%p \t % 8d \t %p <--- head node\n", circ_list, circ_list->data, circ_list->next);

    CircularLinkedList* node = circ_list->next;
    while (node != circ_list)
    {
        printf("%p \t % 8d \t %p\n", node, node->data, node->next);
        node = node->next;
    }
}

void ClearCircularLinkedList(CircularLinkedList* circ_list)
{
    CircularLinkedList* node = circ_list->next;
    /*!
     *  \attention  Only remove the nodes except the head node
     */
    while (node != circ_list)
    {
        CircularLinkedList* next_node = node->next;
        free(node);
        node = next_node;
    }
    circ_list->next = circ_list;
}

bool IsCircularLinkedListEmpty(CircularLinkedList* circ_list)
{
    if (circ_list->next == circ_list)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Status GetElemFromCircularLinkedList(CircularLinkedList* circ_list, int index, ElemType* elem)
{
    CircularLinkedList* node = circ_list->next;

    if (1 <= index && index <= LengthOfCircularinkedList(circ_list))
    {
        int position = 1;   // start from 1
        while (node && position < index)
        {
            position++;
            node = node->next;
        }
        *elem = node->data;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

bool FindElemPositionFromCircularLinkedList(CircularLinkedList* circ_list,
                                            ElemType            target_elem,
                                            int*                position)
{
    CircularLinkedList* node = circ_list->next;

    int index = 0;
    while(node != circ_list)
    {
        index++;
        if (node->data == target_elem)
        {
            *position = index;
            return true;
        }
        node = node->next;
    }
    return false;
}
