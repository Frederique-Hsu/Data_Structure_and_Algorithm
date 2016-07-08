/*************************************************************************************************
 * File name    : CircularLinkedList.cpp
 * Description  : Define the Circular Doubly_Linked_List data structure and its template class.
 * Creator      : Frederick Hsu
 * Creation date: Mon.	4 July, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#include "CircularLinkedList.h"


template<class T>
CircularLinkedListNode<T>::CircularLinkedListNode(void)
{
    left = NULL;
    right = NULL;
}

template<class T>
CircularLinkedListNode<T>::CircularLinkedListNode(const T& elem,
                                                  CircularLinkedListNode *LHand,
                                                  CircularLinkedListNode *RHand)
{
    info = elem;
    LHand = left;
    RHand = right;
}


template<class T>
CircularLinkedList<T>::CircularLinkedList(void)
{
	head = NULL;
	tail = NULL;
}

template<class T>
void CircularLinkedList<T>::addToCircularLinkedListHead(T& elem)
{
    if (head == NULL)
    {
        head = new CircularLinkedListNode<T>(elem);
        head->left = NULL;
        head->right = NULL;
        
        tail = head;
    }
    else
    {
        head = new CircularLinkedListNode<T>(elem, NULL, head);
        head->left = tail;
    }
}

template<class T>
void CircularLinkedList<T>::addToCircularLinkedListTail(T& elem)
{
    if (tail == NULL)
    {
        tail = new CircularLinkedListNode<T>(elem);
        tail->left = NULL;
        tail->right = NULL;
        
        head = tail;
    }
    else
    {
        tail = new CircularLinkedListNode<T>(elem, tail, NULL);
        tail->right = head;
    }
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList(void)
{
    CircularLinkedListNode<T> *pNode = head;
    while (pNode == tail)
    {
        pNode = head->right;
        delete head;
        head = pNode;
    }
    delete tail;
}
