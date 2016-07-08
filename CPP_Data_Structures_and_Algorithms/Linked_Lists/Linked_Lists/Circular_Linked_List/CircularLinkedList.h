/*************************************************************************************************
 * File name    : CircularLinkedList.h
 * Description  : Define the Circular Doubly_Linked_List data structure and its template class.
 * Creator      : Frederick Hsu
 * Creation date: Mon.	4 July, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

    #include <cstdio>

    template<class T>
	class CircularLinkedListNode
	{
	private:
	public:
		T info;
		CircularLinkedListNode *left;
		CircularLinkedListNode *right;

		CircularLinkedListNode(void);
		CircularLinkedListNode(const T& elem,
                               CircularLinkedListNode *LHand = NULL,
                               CircularLinkedListNode *RHand = NULL);
	protected:
	};

	template<class T>
	class CircularLinkedList
	{
	private:
        CircularLinkedList *head;
        CircularLinkedList *tail;
	public:
        CircularLinkedList(void);
        ~CircularLinkedList(void);
        void addToCircularLinkedListHead(T& elem);
        void addToCircularLinkedListTail(T& elem);
	protected:
	};

#endif	/* CIRCULAR_LINKED_LIST_H */
