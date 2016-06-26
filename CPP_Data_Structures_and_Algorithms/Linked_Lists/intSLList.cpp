/*************************************************************************************************
 * File name    : intSLList.cpp
 * Description  : Singly-linked list class to store the integers. Implement this class.
 * Creator      : Frederick Hsu
 * Creation date: Sun.  26 June, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#include "intSLList.h"

IntSLLNode::IntSLLNode(void)
{
    next = NULL;
}

IntSLLNode::IntSLLNode(int el, IntSLLNode *ptr)
{
    info = el;
    next = ptr;
}