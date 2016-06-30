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

    /*********************************************************************************************/

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

    /*********************************************************************************************/

    class IntSLList     // The linked_list chain, not the independent node
    {
    private:
        IntSLLNode *head;   // head node    // 8 bytes
        IntSLLNode *tail;   // tail node    // 8 bytes
#if defined (CLASS_MEMBER_VARIABLE_MEMORY_ALIGNMENT)
                                            // Remark :
        char sNum;                          // 1 byte, but this variable memory bytes will be
                                            // aligned to the largest member variable's memory bytes
                                            // 8 bytes
#endif  /* CLASS_MEMBER_VARIABLE_MEMORY_ALIGNMENT */
    public:
        IntSLList(void);
        ~IntSLList(void);
        
        int isEmpty(void);                  // Member functions doesn't occupy the memory bytes
        void addToHead(int);
        void addToTail(int);
        int insertBeforeNode(int elem, int beforePosNth);
        int insertAfterNode(int elem, int afterPosNth);
        int deleteFromHead(void);
        int deleteFromTail(void);
        void deleteNode(int);
        int deleteNthNode(int positionN);
        bool isInList(int) const;
        
        unsigned int lengthOfList(void);
        IntSLLNode* locatePosition(int positionN);
        void printListChain(void);
    protected:
    };

#endif  /* INT_SINGLY_LINKED_LIST_H */
