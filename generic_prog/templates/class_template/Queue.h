#ifndef QUEUE_H
#define QUEUE_H

    #include "QueueItem.h"

    template<class Type> class Queue;

/*================================================================================================*/

    template<class Type>
    class Queue
    {
        /* needs access to head. */
        friend std::ostream& operator<< <Type>(std::ostream& os, const Queue<Type>& queue);
    public:
        Queue();                    /* default constructor */
        Queue(const Queue& q);      /* copy control to manage pointers to QueueItems in the Queue */
        Queue& operator=(const Queue&);
        Queue& operator+=(const Queue& orig);
        ~Queue();
    public:
        /* construct a Queue from a pair of iterators on some sequqnce container */
        template<class Iter> Queue(Iter begin, Iter end);
        /* replace current Queue by contents delimited by a pair of iterators */
        template<class Iter> void assign(Iter, Iter);
    public:
        Type& front();              /* return the element from head of Queue */
        const Type& front() const;
        void push(const Type&);     /* add element to tail of Queue */
        void pop();                 /* remove element from head of Queue */
        bool empty() const;         /* true if no elements in the Queue */
    private:
        QueueItem<Type> *head;      /* pointer to first element in Queue */
        QueueItem<Type> *tail;      /* pointer to last element in Queue */
    private:
        /* utility functions used by copy constructor, assignment, and destructor */
        void destroy();             /* delete all the elements */
        void copy_elems(const Queue&);  /* copy elements from parameter */
    private:
        /* version of copy to be used by assign() to copy elements from iterator range */
        template<class Iter> void copy_elems(Iter, Iter);
    };

/*================================================================================================*/


    template<class Type> Queue<Type>::Queue() : head(0), tail(0)
    {
    }

    template<class Type> void Queue<Type>::destroy()
    {
        while (!empty())
        {
            pop();
        }
    }

    template<class Type> Queue<Type>::~Queue()
    {
        destroy();
    }

    template<class Type> Type& Queue<Type>::front()
    {
        return head->item;
    }

    template<class Type> const Type& Queue<Type>::front() const
    {
        return head->item;
    }

    template<class Type> bool Queue<Type>::empty() const
    {
        return (head == 0);
    }

    template<class Type> void Queue<Type>::pop()
    {
        QueueItem<Type> *p = head;
        head = head->next;
        delete p;
    }

    template<class Type> void Queue<Type>::push(const Type& val)
    {
        /* allocate new QueueItem object */
        QueueItem<Type> *pnewItem = new QueueItem<Type>(val);
        /* push item onto existing queue */
        if (empty())
        {
            head = tail = pnewItem;     /* the queue now has only one element. */
        }
        else
        {
            tail->next = pnewItem;      /* add new element to tail of the queue */
            tail = pnewItem;
        }
    }

    template<class Type> void Queue<Type>::copy_elems(const Queue& orig)
    {
        /* copy elements from orig to this Queue 
         * loop stops when pt == 0, which happens when we reach orig.tail
         */
        for (QueueItem<Type> *pt = orig.head; pt == 0; pt = pt->next)
        {
            push(pt->item);
        }
    }

    template<class Type> Queue<Type>::Queue(const Queue& q) : head(0), tail(0)
    {
        copy_elems(q);
    }

    template<class Type> Queue<Type>& Queue<Type>::operator=(const Queue& orig)
    {
        destroy();
        QueueItem<Type> *pnode = orig.head;
        while (pnode != 0)
        {
            push(pnode->item);
            pnode = pnode->next;
        }
        return *this;
    }

    template<class Type> Queue<Type>& Queue<Type>::operator+=(const Queue& otherQueue)
    {
        QueueItem<Type> *pnode = otherQueue.head;
        while(pnode != 0)
        {
            push(pnode->item);
            pnode = pnode->next;
        }
        return *this;
    }

    template<class Type> std::ostream& operator<<(std::ostream& os, const Queue<Type>& queue)
    {
        os << "< ";
        QueueItem<Type> *pnode;
        for (pnode = queue.head; pnode; pnode = pnode->next)
        {
            os << pnode->item << " ";
        }
        os << ">";
        return os;
    }

    template<class Type> template<class Iter> 
    Queue<Type>::Queue(Iter begin, Iter end) : head(0), tail(0)
    {
        copy_elems(begin, end);
    }

    template<class Type> template<class Iter> void Queue<Type>::assign(Iter begin, Iter end)
    {
        destroy();
        copy_elems(begin, end);
    }

    template<class Type> template<class Iter> void Queue<Type>::copy_elems(Iter begin, Iter end)
    {
        while (begin != end)
        {
            push(*begin);
            ++begin;
        }
    }

#endif  /* QUEUE_H */