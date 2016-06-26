/*************************************************************************************************
 * File name    : intSLList.h
 * Description  : Singly-linked list class to store the integers.
 * Creator      : Frederick Hsu
 * Creation date: Sun.  26 June, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#ifndef INT_SINGLY_LINKED_LIST_H
#define INT_SINGLY_LINKED_LIST_H

    #include <cstdlib>

    class IntSLLNode    // Just one Node of a Linked List
    {
    private:
    public:
        int info;
        IntSLLNode *next;

        IntSLLNode(void);
        IntSLLNode(int el, IntSLLNode *ptr = NULL);
    protected:
    };

    class IntSLList
    {
    private:
        IntSLLNode *head;   // head node
        IntSLLNode *tail;   // tail node
    public:
        IntSLList(void);
        ~IntSLList(void);

        int isEmpty(void);
        void addToHead(int);
        void addToTail(int);
        int deleteFromHead(void);
        int deleteFromTail(void);
        void deleteNode(int);
        bool isInList(int) const;
    protected:
    };

#endif  /* INT_SINGLY_LINKED_LIST_H */