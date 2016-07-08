/*************************************************************************************************
 * File name    : DoublyLinkedList.h
 * Description  : Define the Doubly_Linked_List data structure and its template class.
 * Creator      : Frederick Hsu
 * Creation date: Mon.	4 July, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

	#include <cstdlib>
	#include <cstdio>

	template<class T>
	class DoublyLinkedListNode
	{
	private:
	public:
		T info;
		DoublyLinkedListNode *prev;
		DoublyLinkedListNode *next;

		DoublyLinkedListNode(void);
		DoublyLinkedListNode(const T& elem,
                             DoublyLinkedListNode *successor = NULL,
                             DoublyLinkedListNode *predecessor = NULL);
	protected:
	};



	template<class T>
	class DoublyLinkedList
	{
	private:
	public:
		DoublyLinkedList(void);
		~DoublyLinkedList(void);

        void addToDoublyLinkedListHead(T& elem);
		void addToDoublyLinkedListTail(T& elem);
		T deleteFromDoublyLinkedListTail(void);
        void printDoublyLinkedList(void);
	protected:
		DoublyLinkedListNode<T> *head;
		DoublyLinkedListNode<T> *tail;
	};

	/*********************************************************************************************/

	template<class T>
	DoublyLinkedListNode<T>::DoublyLinkedListNode(void)
	{
		prev = NULL;
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
	DoublyLinkedList<T>::~DoublyLinkedList(void)
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

#endif  /* DOUBLY_LINKED_LIST_H */
