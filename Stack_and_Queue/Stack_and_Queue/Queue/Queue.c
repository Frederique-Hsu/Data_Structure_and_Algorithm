/*****************************************************************************************************
 * File name        : Queue.c
 * Description      : Implement the operation functions regarding to Queue structure.
 * Creator          : Frederick Hsu
 * Creation date    : Sat.  April 18, 2015
 * Copyright(C)     2015    All rights reserved.
 *
 *****************************************************************************************************/


 #include "Queue.h"
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

Status InitQueue(LinkQueue *Q)
/* 構造一個空隊列Q
 */
{
    if (Q == NULL)
    {
        Q = (PtrLinkQueue)calloc(1, sizeof(LinkQueue));
        if (Q == NULL)
            return OVERFLOW;
    }
    Q->front = (QueuePtr)calloc(1, sizeof(QNode));
    if (NULL == Q->front)
        return OVERFLOW;

    Q->rear = Q->front;
    (Q->front)->next = NULL;

    return OK;
}

Status CreateQueue(LinkQueue *Q, int len)
{
    int i = 0;
    QElemType elem = 0;
    
    printf("Create a queue with %d elements.\n", len);
    
    if ((Q->front) == 0)
    {
        if (OK != InitQueue(Q))
        {
            return ERROR;
        }
    }
    Q->rear = Q->front;
    do
    {
        printf("Please enter a number : ");
        scanf("%d", &elem);
        if (NULL == Q->rear)
        {
            Q->rear = (QueuePtr)calloc(1, sizeof(QNode));
            (Q->rear)->next = NULL;
        }
        (Q->rear)->data = elem;
        (Q->rear) = (Q->rear)->next;    // Move to next node;
        
        i++;
    }
    while (i < len);
    
    return OK;
}

void DisplayQueue(LinkQueue Q)
{
    QueuePtr p = Q.front;
    
    printf("Queue :\n");
    printf("-------------------------------------\n");
    printf("        | Current | Data  | Next    |\n");
    printf("-------------------------------------\n");
    
    while (p->next != NULL)
    {
        if (p == Q.front)
        {
            printf("            ---------------------------------\n");
            printf("Q.front-->  | 0x%08X    | %d    | 0x%08X    |\n", p, p->data, p->next);
            printf("            ---------------------------------\n\n");
        }
        else if (p == Q.rear)
        {
            printf("            ---------------------------------\n");
            printf("Q.rear-->   | 0x%08X    | %d    | 0x%08X    |\n", p, p->data, p->next);
            printf("            ---------------------------------\n\n");
        }
        else
        {
            printf("            ---------------------------------\n");
            printf("            | 0x%08X    | %d    | 0x%08X    |\n", p, p->data, p->next);
            printf("            ---------------------------------\n\n");
        }
        
        p = p->next;
    }
}


