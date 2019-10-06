/**************************************************************************************************
 * File name    : class_template.h
 * Description  : Only define the class template in header file.
 * Creator      : Frederick Hsu
 * Creation date: Fri.  05 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef CLASS_TEMPLATE_H
#define CLASS_TEMPLATE_H

    #include <iostream>
    using namespace std;

    template<class Type> class QueueItem;
    template<class Type> class Queue;

    /* function template declaration MUST precede friend declaration in 
     * both QueueItem and Queue.
     */
    template<class Type> ostream& operator<<(ostream& out, const Queue<Type>& queue);
    template<class Type> istream& operator>>(istream& in, Queue<Type>& queue);

    template<class Type>
    class QueueItem
    {
        friend class Queue<Type>;
        friend ostream& operator<< <Type> (ostream& out, const Queue<Type>& queue);
        friend istream& operator>> <Type> (istream& in, Queue<Type>& queue);
    private:
        QueueItem(const Type& t) : item(t), next(0) {}
    private:
        Type item;          /* value stored in this element */
        QueueItem* next;    /* pointer to next element in the Queue */
    };

    template<class Type>
    class Queue
    {
        friend ostream& operator<< <Type> (ostream& out, const Queue<Type>& queue);
        friend istream& operator>> <Type> (istream& in, Queue<Type>& queue);
    public:
        Queue();
        Queue(const Queue& q);
        Queue& operator=(const Queue& orig);
        ~Queue();
    public:
        /* construct a Queue from a pair of iterators on some sequence */
        template<class It> Queue(It begin, It end);
        /* replace current Queue by contents delimited by a pair of iterators */
        template<class Iter> void assign(Iter, Iter);
    public:
        Type& front();
        const Type& front() const;
        void push(const Type& elem);
        void pop();
        bool empty() const;
    private:
        QueueItem<Type> *head;
        QueueItem<Type> *tail;
    private:
        void destroy();
        void copy_elems(const Queue& orig);
        /* version of copy to be used by assign to copy elements from iterator range */
        template<class Iter> void copy_elems(Iter, Iter);
    };

    #if defined (NOT_SUPPORT_EXPORTED_TEMPLATE)
    #else
        #include "class_template.cpp"
    #endif

#endif  /* CLASS_TEMPLATE_H */
