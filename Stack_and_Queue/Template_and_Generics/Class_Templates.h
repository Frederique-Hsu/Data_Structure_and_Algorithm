/**************************************************************************************************
 * File name	: CLass_Templates.h
 * Description	: class template header goes in the shared header file.
 * Creator		: Frederick Hsu
 * Creation date: Fri.	09 Aug. 2019
 * Copyright(C)	2019	All rights reserved.
 *
 **************************************************************************************************/


#ifndef CLASS_TEMPLATES_H
#define CLASS_TEMPLATES_H

	#include <cstdio>
	#include <iostream>

	template<class Type> class QueueItem;
	template<class Type> class Queue;		/* declaration that Queue is a template needed for friend declaration in QueueItem */

	/* function template declaration must precede friend declaration in QueueItem and Queue. */
	template<class Type> std::ostream& operator<<(std::ostream& os, const Queue<Type>& q);
	template<typename Type> std::istream& operator>>(Type value, Queue<Type>& q);

	template <class Type>
	class QueueItem
	{
		friend class Queue<Type>;
		friend std::ostream& operator<< <Type>(std::ostream& os, const Queue<Type>& q);
	private:
		QueueItem(const Type& t) : item(t), next(0)
		{
		}
		Type item;
		QueueItem* next;
	};

	template<class Type>
	class Queue
	{
		friend std::ostream& operator<< <Type>(std::ostream& os, const Queue<Type>& q);
	public:
		Queue() : head(0), tail(0)			/* default constructor */
		{
		}
		Queue(const Queue& q) : head(0), tail(0)
		{
			copy_elems(q);
		}
		/* construct a Queue from a pair of iterators on some sequence */
		template<class It> Queue(It begin, It end);		
		// Queue& operator=(const Queue& other);
		~Queue()
		{
			destroy();
		}

		Type& front()		/* return element from head of Queue */
		{
			return head->item;
		}
		const Type& front() const
		{
			return head->item;
		}
		void push(const Type&);		/* add element to back of Queue */
		void pop();					/* remove element from head of Queue */
		bool empty() const			/* true if no elements in the Queue */
		{
			return (head == 0);
		}
		void showQueue();
		/* replace current queue by contents delimited by a pair of iterators */
		template<class Iter> void assign(Iter, Iter);
	private:
		QueueItem<Type>* head;
		QueueItem<Type>* tail;
		void destroy();
		void copy_elems(const Queue&);
		/* version of copy to be used by assign to copy elements from iterator range */
		template<class Iter> void copy_elems(Iter, Iter);
	};

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

	template<class Type> void Queue<Type>::push(const Type& val)
	{
		QueueItem<Type>* pt = new QueueItem<Type>(val);
		if (empty())
		{
			head = tail = pt;
		}
		else
		{
			tail->next = pt;
			tail = pt;
		}
	}

	template<class Type> void Queue<Type>::copy_elems(const Queue& orig)
	{
		for (QueueItem<Type>* pt = orig.head; pt; pt = pt->next)
		{
			push(pt->item);
		}
	}

	template<class Type> void Queue<Type>::showQueue()
	{
		std::printf("\nCurrent queue is showed as below : \n");
		std::printf("Node#\t\t| Item\t\t| Current node address\t\t| Next node address\n");
		std::printf("----------------+---------------+-------------------------------+-------------------------------\n");

		QueueItem<Type>* pnode = head;
		int index = 1;
		while (pnode != 0)
		{
			std::cout << index++ << "\t\t| " << pnode->item << "\t\t| ";
			std::printf("0x%016llX \t%s| 0x%016llX\n", 
				        (unsigned long long)pnode, 
						(pnode == head) ? "head\t" : ((pnode != tail) ? "\t" : "tail\t"),
				        (unsigned long long)pnode->next);
			std::printf("----------------+---------------+-------------------------------+-------------------------------\n");
			pnode = pnode->next;
		}
	}

	template<class Type> std::ostream& operator<<(std::ostream& os, const Queue<Type>& q)
	{
		os << "< ";
		QueueItem<Type>* p;
		for (p = q.head; p; p = p->next)
		{
            os << p->item << ", ";
		}
		os << ">";
		return os;
	}

	template<class Type> template<class Iter>
	Queue<Type>::Queue(Iter begin, Iter end) : head(0), tail(0)
	{
		copy_elems(begin, end);
	}

	template<class Type> template<class Iter>
	void Queue<Type>::assign(Iter begin, Iter end)
	{
		destroy();
		copy_elems(begin, end);
	}

	template<class Type> template<class Iter>
	void Queue<Type>::copy_elems(Iter begin, Iter end)
	{
		while (begin != end)
		{
			push(*begin);
			++begin;
		}
	}

#endif	/* CLASS_TEMPLATES_H */
