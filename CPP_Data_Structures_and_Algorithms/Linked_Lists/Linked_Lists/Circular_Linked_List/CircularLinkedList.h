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
    #include <cstring>
	#include <iostream>

    template<class T> class CircularLinkedListNode;
    template<> class CircularLinkedListNode<const char*>;
    template<class T> class CircularLinkedList;

    /********************************************************************/

    template<class T>
	class CircularLinkedListNode
	{
	private:
	public:
		T info;
		CircularLinkedListNode *left;
		CircularLinkedListNode *right;

		CircularLinkedListNode(void);
		CircularLinkedListNode(const T& elem,       // 注意，此处用上const是为了让类模板函数能够进行隐含的类型推断，否则就必须使用显性的类型变量。
                               CircularLinkedListNode *LHand = NULL,
                               CircularLinkedListNode *RHand = NULL);
	protected:
	};

    template<>
    class CircularLinkedListNode<const char*>
    {
    private:
    public:
        const char* info;
        CircularLinkedListNode *left;
        CircularLinkedListNode *right;
        
        CircularLinkedListNode(const char* elem,
                               CircularLinkedListNode<const char*> *LHand = NULL,
                               CircularLinkedListNode<const char*> *RHand = NULL);
        ~CircularLinkedListNode(void);
    protected:
    };

	template<class T>
	class CircularLinkedList
	{
	private:
        CircularLinkedListNode<T> *head;
        CircularLinkedListNode<T> *tail;
	public:
        CircularLinkedList(void);
        CircularLinkedList(const T& elem);
        ~CircularLinkedList(void);
        void addToCircularLinkedListHead(const T& elem);
        void addToCircularLinkedListTail(const T& elem);
        void printCircularLinkedList(void);
        int numberOfNodes(void);
        void insertNewNodeBeforePositionN(const T& elem, int n);
        void insertNewNodeAfterPositionN(const T& elem, int n);
        const T& deleteFromHead(void);
        const T& deleteFromTail(void);
        const T& deleteNodeOfPositionN(int n);
	protected:
	};

	/**************************************************************************************************/

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
		left = LHand;
		right = RHand;
	}

	CircularLinkedListNode<const char*>::CircularLinkedListNode(const char* elem,
																CircularLinkedListNode<const char*> *LHand,
																CircularLinkedListNode<const char*> *RHand)
	{
		std::size_t len = std::strlen(elem);
		info = new char[len+1];
		// std::memcpy((void*)info, elem, (len+1)*sizeof(char));    // 务必要进行强制类型转换，不然void *不能转换为const char*
		std::strcpy((char*)info, elem);     // 务必进行强制类型转换，不然const char*做为左值不能写入新的值进去。
		left = LHand;
		right = RHand;
	}

	CircularLinkedListNode<const char*>::~CircularLinkedListNode(void)
	{
		if (0 != std::strlen(info))
			delete [] info;
		else
			info = NULL;
		left = NULL;
		right = NULL;
	}

	/**************************************************************************************************/

	template<class T>
	CircularLinkedList<T>::CircularLinkedList(void)
	{
		head = NULL;
		tail = NULL;
	}

	template<class T>
	CircularLinkedList<T>::CircularLinkedList(const T& elem)
	{
		head = new CircularLinkedListNode<T>(elem);
		tail = head;
	}

	template<class T>
	CircularLinkedList<T>::~CircularLinkedList(void)
	{
		CircularLinkedListNode<T> *pNode = head->right, *pTempNode;
		while (pNode != tail)
		{
			pTempNode = pNode->right;
			delete pNode;
			pNode = pTempNode;
		}

		delete head;
		delete tail;

		head = NULL;
		tail = NULL;
	}

	template<class T>
	void CircularLinkedList<T>::addToCircularLinkedListHead(const T& elem)
	{
		if (head == NULL)
		{
			head = new CircularLinkedListNode<T>(elem);
			tail = head;
		}
		else
		{
			CircularLinkedListNode<T> *pNewNode = new CircularLinkedListNode<T>(elem, tail, head);
			head->left = pNewNode;
			tail->right = pNewNode;
			head = pNewNode;
		}
	}

	template<class T>
	void CircularLinkedList<T>::addToCircularLinkedListTail(const T& elem)
	{
		if (tail == NULL)
		{
			tail = new CircularLinkedListNode<T>(elem);
			head = tail;
		}
		else
		{
			CircularLinkedListNode<T> *pNewNode = new CircularLinkedListNode<T>(elem, tail, head);
			head->left = pNewNode;
			tail->right = pNewNode;
			tail = pNewNode;
		}
	}

	template<class T>
	void CircularLinkedList<T>::printCircularLinkedList(void)
	{
		CircularLinkedListNode<T> *pNode = head;
		std::printf("\n\n");
		std::printf(" Left  node		| Curr. node		| Curr. data	| Right node	\n");
		std::printf("---------------------------------------------------------------------------------------------\n");
		do
		{
			std::printf(" 0x%016lX	| 0x%016lX	| ", pNode->left, pNode);
			std::cout<<pNode->info<<"		| ";
			std::printf("0x%016lX	\n", pNode->right);
			std::printf("---------------------------------------------------------------------------------------------\n");
			pNode = pNode->right;
		}
		while (pNode != tail);		// Until to the previous node of tail
		/* Need to print out the tail node */
		std::printf(" 0x%016lX	| 0x%016lX	| ", pNode->left, pNode);
		std::cout<<pNode->info<<"		| ";
		std::printf("0x%016lX	\n", pNode->right);
		std::printf("---------------------------------------------------------------------------------------------\n\n");
		return;
	}

	template<class T>
	int CircularLinkedList<T>::numberOfNodes(void)
	{
		int num = 0;
		CircularLinkedListNode<T> *pNode = head;
		if (head == NULL)
			return 0;
		else if (head == tail)
			return 1;
		else
		{
			while (pNode != tail)
			{
				num++;
				pNode = pNode->right;
			}
			return (num+1);
		}
	}

	template<class T>
	const T& CircularLinkedList<T>::deleteFromHead(void)
	{
		CircularLinkedListNode<T> *pHead_Successor = head->right;
		T elem = head->info;
		delete head;
		head = pHead_Successor;
		tail->right = pHead_Successor;
		pHead_Successor->left = tail;
		return elem;
	}

	template<class T>
	const T& CircularLinkedList<T>::deleteFromTail(void)
	{
		CircularLinkedListNode<T> *pTail_Predecessor = tail->left;
		T elem = tail->info;
		delete tail;
		tail = pTail_Predecessor;
		pTail_Predecessor->right = head;
		head->left = pTail_Predecessor;
		return elem;
	}

	template<class T>
	void CircularLinkedList<T>::insertNewNodeBeforePositionN(const T& elem, int n)
	{
		int len = numberOfNodes();
		if ((n <= 0) || (n > len))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl;
			return;
		}
		if (n == 1)
		{
			addToCircularLinkedListHead(elem);
			return;
		}
		int pos;
		CircularLinkedListNode<T> *pNode;
		if (n <= len/2)
		{
			pos = 0;
			pNode = head;
			while (pNode != tail)	// 注意，由于是环状的链表，此处必须选择tail做为截止。 不然会无限循环下去。
			{
				pos++;
				if (pos == n)
				{
					break;
				}
				pNode = pNode->right;
			}
		}
		else
		{
			pos = len;
			pNode = tail;
			while (pNode != head)	// 同样的道理，此处只能选择head做为截止。
			{
				if (pos == n)
				{
					break;
				}
				pos--;
				pNode->left;
			}
		}
		CircularLinkedListNode<T> *pLNode = pNode->left, *pCurrNode = pNode;
		CircularLinkedListNode<T> *pNewNode = new CircularLinkedListNode<T>(elem,pLNode, pCurrNode);
		pLNode->right = pNewNode;
		pCurrNode->left = pNewNode;
	}

	template<class T>
	void CircularLinkedList<T>::insertNewNodeAfterPositionN(const T& elem, int n)
	{
		int len = numberOfNodes();
		if ((n <= 0) || (n > len))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl;
			return;
		}
		if (n == len)
		{
			addToCircularLinkedListTail(elem);
			return;
		}
		int pos;
		CircularLinkedListNode<T> *pNode;
		if (n <= len/2)
		{
			pos = 0;
			pNode = head;
			while (pNode != tail)
			{
				pos++;
				if (pos == n)
				{
					break;
				}
				pNode = pNode->right;
			}
		}
		else
		{
			pos = len;
			pNode = tail;
			while (pNode != head)
			{
				if (pos == n)
				{
					break;
				}
				pos--;
				pNode = pNode->left;
			}
		}
		CircularLinkedListNode<T> *pRNode = pNode->right, *pCurrNode = pNode;
		CircularLinkedListNode<T> *pNewNode = new CircularLinkedListNode<T>(elem, pCurrNode, pRNode);
		pRNode->left = pNewNode;
		pCurrNode->right = pNewNode;
	}

	template<class T>
	const T& CircularLinkedList<T>::deleteNodeOfPositionN(int n)
	{
		int len = numberOfNodes();
		if ((n <= 0) || (n > len))
		{
			std::cout<<"The position number you entered is wrong."<<std::endl;
			return 0;
		}
		if (n == 1)
		{
			return (deleteFromHead());
		}
		else if (n == len)
		{
			return (deleteFromTail());
		}
		else
		{
			int pos;
			CircularLinkedListNode<T> *pNode;
			if (n <= len/2)
			{
				pos = 0;
				pNode = head;
				while (pNode != tail)
				{
					pos++;
					if (pos == n)
					{
						break;
					}
					pNode = pNode->right;
				}
			}
			else
			{
				pos = len;
				pNode = tail;
				while (pNode != head)
				{
					if (pos == n)
					{
						break;
					}
					pos--;
					pNode = pNode->left;
				}
			}
			CircularLinkedListNode<T> *pLNode = pNode->left, *pRNode = pNode->right;
			T elem = pNode->info;
			delete pNode;
			pLNode->right = pRNode;
			pRNode->left = pLNode;
			return elem;
		}
	}

#endif	/* CIRCULAR_LINKED_LIST_H */
