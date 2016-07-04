/*************************************************************************************************
 * File name    : intSLList.cpp
 * Description  : Singly-linked list class to store the integers. Implement this class.
 * Creator      : Frederick Hsu
 * Creation date: Sun.  26 June, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#include "intSLList.h"
#include <iostream>
#include <cerrno>
#include <cstdio>

IntSLLNode::IntSLLNode(void)
{
    info = 0;
    next = NULL;
}

IntSLLNode::IntSLLNode(int el, IntSLLNode *ptr)
{
    info = el;
    next = ptr;
}

#if defined (DISABLE_DEFAULT_DESTRUCTOR)
    IntSLLNode::~IntSLLNode(void)
    {
        info = 0;
        next = NULL;
        // delete this;
    }
#endif  /* DISABLE_DEFAULT_DESTRUCTOR */

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
    while (head != NULL)
    {
        pNode = head->next;
        delete head;
        head = pNode;
    }
    // delete tail;     // At this moment, DO NOT delete tail node once again,
                        // because it is already NULL now.
                        // Although the tail node is still shown a meaningful poointer address.
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

int IntSLList::deleteFromHead(void)
{
    // assert(!isEmpty());      // Terminate the program if false
    if (isEmpty())
    {
        throw ("Empty");
    }
    
    int elem = head->info;          // Stash the info of head node
    IntSLLNode *tmpNode = head;     // and the head node pointer.
    
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;      // Move to next node
    }
    delete tmpNode;     // Remove the head node
    return elem;
}

int IntSLList::deleteFromTail(void)
{
    if (isEmpty())
    {
        throw ("Empty");
    }
    
    int elem = tail->info;
    if (head == tail)    // Only 1 node in the list chain
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        IntSLLNode *tmpNode = NULL;
#if 0
        for (tmpNode = head; tmpNode->next != tail; tmpNode = tmpNode->next)
        {
            ;    // Move to the previous node of tail.
        }
#else
        tmpNode = head;
        do
        {
            tmpNode = tmpNode ->next;
        }
        while (tmpNode->next != tail);   // Move position, till the predecessor of tail node.
#endif
        delete tail;
        tail = tmpNode;  // the predecessor of tail becomes the tail.
        tail->next = NULL;
    }
    return elem;
}

void IntSLList::printListChain(void)
{
    IntSLLNode *pNode = head;
    
    std::printf("\n\n");
    std::printf(" Curr. node				| Data		| Next node		\n");
    std::printf("------------------------------------------------------------------\n");
    while (pNode != NULL)
    {
        std::printf(" 0x%016lX		|	%d		| 0x%016lX    \n",
                    pNode,
                    pNode->info,
                    pNode->next);
        std::printf("------------------------------------------------------------------\n");
        pNode = pNode->next;
    }
    
    std::printf("\n\n");
}

void IntSLList::deleteNode(int elem)
{
#if 1   // From Frederick's implementation
    IntSLLNode *pNode = head;
    
    if (elem == head->info)
    {
        deleteFromHead();
        return;
    }
    else if (elem == tail->info)
    {
        deleteFromTail();
        return;
    }
    else
    {
        while (pNode != NULL)
        {
            if ((pNode->next)->info == elem)
            {
                break;
            }
            pNode = pNode->next;
        }
        if (pNode == NULL)
        {
            return;     // It means that the info of every node does NOT equal to elem
        }
        else
        {
            IntSLLNode *successor = pNode->next;
            pNode->next = successor->next;
            delete successor;
            return;
        }
    }
#else
    if (head != NULL)   // Non-empty list chain
    {
        if ((head == tail) && (elem == head->info))     // Only 1 node in the list chain
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else if (elem == head->info)    // If more than 1 node in the list chain
        {
            IntSLLNode *tmpNode = head;
            head = head->next;
            delete tmpNode;     // and old head node is deleted.
        }
        else
        {
            IntSLLNode *pred, *tmp;
            for (pred = head, tmp = head->next;
                 ((tmp != NULL) && (elem == tmp->info));
                 pred = pred->next, tmp = tmp->next)
            {
                ;
            }
            if (tmp != NULL)
            {
                pred->next = tmp->next;
                if (tmp == tail)
                {
                    tail = pred;
                }
                delete tmp;
            }
        }
    }
#endif
}

bool IntSLList::isInList(int elem) const
{
#if 1
    IntSLLNode *pNode = head;
    while (pNode != NULL)
    {
        if (pNode->info == elem)
        {
            return true;
        }
        pNode = pNode->next;
    }
    if (pNode == NULL)
    {
        return false;
    }
    return false;
#else
    IntSLLNode *tmp;
    for (tmp = head; ((tmp != NULL) && !(elem == tmp->info)); tmp = tmp->next);
    return (tmp != NULL);
#endif
}

unsigned int IntSLList::lengthOfList(void)
{
    unsigned int l_uilen = 0;
    IntSLLNode *pNode = head;
    while (pNode != NULL)
    {
        pNode = pNode->next;
        l_uilen++;
    }
    return l_uilen;
}

IntSLLNode* IntSLList::locatePosition(int positionN)
{
    unsigned int uiLen = lengthOfList();
    if ((positionN < 0) || (positionN > uiLen))
    {
        return NULL;
    }
    
    IntSLLNode *pNode = head;
    unsigned int uiCnt = 1;
    while (pNode != NULL)
    {
        if (uiCnt == positionN)
            break;
        pNode = pNode->next;
        uiCnt++;
    }
    return pNode;
}

int IntSLList::deleteNthNode(int positionN)
{
    if ((positionN <= 0) || (positionN > lengthOfList()))
    {
        return ((-1)*positionN);
    }
    
    if (positionN == 1)
        deleteFromHead();
    else if (positionN == lengthOfList())
        deleteFromTail();
    else
    {
        unsigned int uiCnt = 1;
        IntSLLNode *pNode = head;
        while (pNode != NULL)
        {
            if (uiCnt == positionN-1)
            {
                break;
            }
            pNode = pNode->next;
            uiCnt++;
        }
        IntSLLNode *successor = pNode->next;
        pNode->next = successor->next;
        delete successor;        
    }
    return 0;
}

int IntSLList::insertAfterNode(int elem, int afterPosNth)
{
    if ((afterPosNth <= 0) || (afterPosNth > lengthOfList()))
        return ((-1)*afterPosNth);
    
    if (afterPosNth == lengthOfList())
    {
        addToTail(elem);
        return 0;
    }
    
    unsigned int uiCnt = 1;     // NOTICE : This count should start from 1, not 0.
    IntSLLNode *pNode = head;
    while (pNode != NULL)
    {
        if (uiCnt == afterPosNth)   // Move, till the n node
        {
            break;
        }
        pNode = pNode->next;
        uiCnt++;
    }
    IntSLLNode *pNewNode = new IntSLLNode(elem);
    IntSLLNode *successor = pNode->next;
    pNode->next = pNewNode;
    pNewNode->next = successor;
    
    return 0;
}

int IntSLList::insertBeforeNode(int elem, int beforePosNth)
{
    if ((beforePosNth < 0) || (beforePosNth > lengthOfList()))
        return ((-1)*beforePosNth);
    
    if (beforePosNth == 1)
    {
        addToHead(elem);
        return 0;
    }
    
    IntSLLNode *pNode = head, *pNewNode = new IntSLLNode(elem);
    unsigned int uiCnt = 1;     // NOTICE : This count should start from 1, not 0.
    while (pNode != NULL)
    {
        if (uiCnt == beforePosNth-1)    // Move, till the (n-1) node
        {
            break;
        }
        pNode = pNode->next;
        uiCnt++;

    }
    IntSLLNode *pNodeN = pNode->next;
    pNode->next = pNewNode;
    pNewNode->next = pNodeN;
    return 0;
}

int IntSLList::changeElementOfPositionN(int positionN, int newElem)
{
    if ((positionN <= 0) || (positionN > lengthOfList()))
    {
        return ((-1)*positionN);
    }
    
    unsigned int uiCnt = 1;
    IntSLLNode *pNode = head;
    while (pNode != NULL)
    {
        if (uiCnt == positionN)
        {
            break;
        }
        pNode = pNode->next;
        uiCnt++;
    }
    pNode->info = newElem;
    
    return 0;
}

void IntSLList::replaceSameOldElements(int oldElem, int newElem)
{
    IntSLLNode *pNode = head;
    while (pNode != NULL)
    {
        if (pNode->info == oldElem)
        {
            pNode->info = newElem;
        }
        pNode = pNode->next;
    }
}
