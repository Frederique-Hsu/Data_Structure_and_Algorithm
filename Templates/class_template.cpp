/**************************************************************************************************
 * File name    : class_template.cpp
 * Description  : By using the separate compilation model, implement the class template in a
 *              : separate source file.
 * Creator      : Frederick Hsu
 * Creation date: Fri.  05 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#define NOT_SUPPORT_EXPORTED_TEMPLATE

#if defined (NOT_SUPPORT_EXPORTED_TEMPLATE)
    template<class Type> Queue<Type>::Queue() : head(0), tail(0)
    {
    }

    template<class Type> Queue<Type>::~Queue()
    {
        destroy();
    }

    template<class Type> Queue<Type>::Queue(const Queue& q) : head(0), tail(0)
    {
        copy_elem(q);
    }

    template<class Type> void Queue<Type>::destroy()
    {
        while (!empty())
        {
            pop();
        }
    }

    template<class Type> void Queue<Type>::pop()
    {
        QueueItem<Type>* p = head;
        head = head->next;
        delete p;
    }

    template<class Type> bool Queue<Type>::empty() const
    {
        return (head == 0);
    }

    template<class Type> Type& Queue<Type>::front()
    {
        return head->item;
    }

    template<class Type> const Type& Queue<Type>::front() const
    {
        return head->item;
    }

    template<class Type> void Queue<Type>::push(const Type& value)
    {
        QueueItem<Type> *ptr = new QueueItem<Type>(value);
        if (empty())
        {
            head = tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
    }

    template<class Type> void Queue<Type>::copy_elems(const Queue& orig)
    {
        for (QueueItem<Type> *ptr = orig.head; ptr; ptr = ptr->next)
        {
            push(ptr->item);
        }
    }

    template<class Type> Queue<Type>& Queue<Type>::operator=(const Queue& orig)
    {
        destroy();      /* firstly erase this Queue */
        QueueItem<Type> *ptr = orig.head;
        while (ptr)
        {
            push(ptr->item);
            ptr = ptr->next;
        }
        return *this;
    }

    template<class Type> ostream& operator<<(ostream& out, const Queue<Type>& queue)
    {
        out << "< ";
        QueueItem<Type>* ptr = queue.head;
        while (ptr)
        {
            out << ptr->item << " ";
            ptr = ptr->next;
        }
        out << " >";
        return out;
    }

    template<class Type> istream& operator>>(istream& in, Queue<Type>& queue)
    {
        Type element;
        while (in >> element)
        {
            queue.push(element);
        }
        return in;
    }

    template<class Type> template<class Iter> void Queue<Type>::assign(Iter begin, Iter end)
    {
        destroy();      /* remove existing elements in this Queue */
        copy_elems(begin, end);     /* copy elements from the input iterator range */
    }

    template<class Type> template<class Iter> void Queue<Type>::copy_elems(Iter begin, Iter end)
    {
        while (begin != end)
        {
            push(*begin);
            ++begin;
        }
    }

    template<class Type> template<class It> Queue<Type>::Queue(It begin, It end) : head(0), tail(0)
    {
        copy_elems(begin, end);
    }
#else
    /* exported templates are not part of the current C++ standards.
     * not supported by C++11, C++14, even C++17
     */
    export template <class Type> class Queue;

    #include "class_template.h"
#endif  /* NOT_SUPPORT_EXPORTED_TEMPLATE */

