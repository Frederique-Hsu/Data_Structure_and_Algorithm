/*************************************************************************************************
 * File name    : DoublyLinkedList.cpp
 * Description  : Define the Doubly_Linked_List data structure and its template class.
 * Creator      : Frederick Hsu
 * Creation date: Mon.	4 July, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/


#include "DoublyLinkedList.h"


#if 0
template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(void)
{
	next = NULL;
}

template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(const T& elem,
                                              DoublyLinkedListNode *successor,
                                              DoublyLinkedListNode *predecessor)
{
	info = elem;
	prev = predecessor;
	next = successor;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(void)
{
    head = NULL;
    tail = NULL;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList<T>(void)
{
    DoublyLinkedListNode<T> *pNode = head;
    while (pNode != NULL)
    {
        pNode = head->next;
        delete head;
        head = pNode;
    }
}

template<class T>
void DoublyLinkedList<T>::addToDoublyLinkedListHead(T& elem)
{
    if (head == NULL)   // DoublyLinkedList is empty
    {
        head = new DoublyLinkedListNode<T>(elem);
        head->prev = NULL;
        head->next = NULL;
        
        tail = head;
    }
    else
    {
        head = new DoublyLinkedListNode<T>(elem, head);
        head->prev = NULL;
    }
}

template<class T>
void DoublyLinkedList<T>::addToDoublyLinkedListTail(T& elem)
{
    if (tail == NULL)
    {
        tail = new DoublyLinkedListNode<T>(elem);
        tail->prev = NULL;
        tail->next = NULL;
        
        head = tail;
    }
    else
    {
        tail = new DoublyLinkedListNode<T>(elem, NULL, tail);
    }
}

template<class T>
void DoublyLinkedList<T>::printDoublyLinkedList(void)
{
    DoublyLinkedListNode<T> *pNode = head;
    std::printf(" Curr. node    | Prev. node    | Data      | Next node     \n");
    std::printf("--------------------------------------------------------------------------\n");
    while (pNode != NULL)
    {
        std::printf(" 0x016lX   | 0x016lX   | %d        | 0x016lX   \n",
                    pNode,
                    pNode->prev,
                    pNode->info,
                    pNode->next);
        pNode = pNode->next;
        std::printf("--------------------------------------------------------------------------\n");
    }
    std::printf("\n");
}
#endif
