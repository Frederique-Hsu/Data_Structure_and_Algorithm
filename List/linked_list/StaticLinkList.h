/*!
 *  \file       StaticLinkList.h
 *  \brief      Define the structure of static linked list.
 *
 */


#pragma once


#define MAX_SIZE    10

typedef int     ElemType;

typedef struct
{
    ElemType    data;
    int         cursor;
} component, SLinkList[MAX_SIZE];


void InitSLinkList(SLinkList slist);

void DisplaySLinkList(SLinkList slist);

void DestroySLinkList(SLinkList slist);
