/*!
 *  \file       StaticLinkList.c
 *  \brief
 *
 */


#include "StaticLinkList.h"

#include <stdio.h>

void InitSLinkList(SLinkList slist)
{
    slist[MAX_SIZE-1].cursor = 0;
    for (int i = 0; i < MAX_SIZE-2; i++)
    {
        slist[i].cursor = i + 1;
    }
    slist[MAX_SIZE-2].cursor = 0;
}

/*!
 *  \brief  The structure of static-link-list
 *
 *  \struct SLinkList[MAX_SIZE]
 *
 *     data       cursor
 *  +-----------+--------+
 *  |           |   1    |  [0]  <--- the first valid node
 *  +-----------+--------+
 *  |           |   2    |  [1]
 *  +-----------+--------+
 *  |           |   3    |  [2]
 *  +-----------+--------+
 *  |           |        |
 *  |           |   .    |   .
 *  |           |   .    |   .
 *  |           |   .    |   .
 *  |           |        |
 *  +-----------+--------+
 *  |           |   7    |  [6]
 *  +-----------+--------+
 *  |           |   8    |  [7]
 *  +-----------+--------+
 *  |           |   0    |  [8]
 *  +-----------+--------+
 *  |           |   0    |  [9]  <--- the head node of empty list
 *  +-----------+--------+
 */

void DisplaySLinkList(SLinkList slist)
{
    printf("\ncurrent node \t % 8s \t cursor\n", "data");
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        printf("%p \t % 8d \t % 4d\n", slist + i, (slist + i)->data, (slist + i)->cursor);
    }
}

void DestroySLinkList(SLinkList slist)
{
}
