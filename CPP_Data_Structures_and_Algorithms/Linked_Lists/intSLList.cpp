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

/*************************************************************************************************/

IntSLList::IntSLList(void)
{
    head = NULL;
    tail = NULL;
}

IntSLList::~IntSLList(void)
/* Destructor, it means to destroy the linked list chain.
 * remove all nodes of the linked list chain, including 
 * the head and tail nodes. The entire linked list chain
 * is empty.
 */
{
    IntSLLNode *pNode = head;

    while (pNode != NULL)       // Till the next pointer of tail node
    {
        pNode = head->next;     // Must get the next node's pointer firstly.
        delete head;            // Delete current node
        head = pNode;           // Assign the pointer of next node to head pointer, move to next node
    }

    head = NULL;    
    tail = NULL;
}

int IntSLList::isEmpty(void)
{
    return (head == NULL);
}

void IntSLList::addToHead(int el)
{
    IntSLLNode *pNode = new IntSLLNode(el, head);
    head = pNode;

    if (tail == NULL)   // Current list is empty?
        tail = pNode;   // head node is also the tail node, only 1 node existed.
}

void IntSLList::addToTail(int el)
{
    if (tail != NULL)   // Current list is empty?
    {
        tail->next = new IntSLLNode(el);
        tail = tail->next;  // Move the tail pointer to new inserted node
    }
    else
    {
        tail = new IntSLLNode(el);
        head = tail;    // head and tail point to the same node, it means only 1 node now.
    }
}