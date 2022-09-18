/*!
 *  \file   List.hpp
 *  \brief  Define the structure of List container.
 *
 */

#pragma once

#include <functional>
#include "IteratorException.hpp"

#define ENABLE_ITERATOR_ERROR_CHECKING

template<typename ObjType> class List
{
private:
    struct Node
    {
        ObjType  data;
        Node    *prev;
        Node    *next;

        Node(const ObjType& d = ObjType{},
             Node *prevnode = nullptr,
             Node *nextnode = nullptr);
        Node(ObjType&& d,
             Node *prevnode = nullptr,
             Node *nextnode = nullptr);
    };
public:
    class const_iterator
    {
        friend class List<ObjType>;
    public:
        const_iterator();
    protected:
        Node *current;
        const List<ObjType> *theList;

        const_iterator(Node *p);
        const_iterator(const List<ObjType>& lst, Node *p);
    public:
        const ObjType& operator*() const;
        const_iterator& operator++();           // for prefix operator : ++itr
        const_iterator  operator++(int);        // for postfix operator: itr++
        const_iterator& operator+(int n);       // itr + n
        const_iterator& operator--();
        const_iterator  operator--(int);
        const_iterator& operator-(int n);
        bool operator==(const const_iterator& rhs) const;
        bool operator!=(const const_iterator& rhs) const;
    protected:
        ObjType& retrieve() const;
        void assertIsValid() const;
    };

    class iterator : public const_iterator
    {
        friend class List<ObjType>;
    public:
        iterator();
    protected:
        iterator(Node *p);
        iterator(const List<ObjType>& lst, Node *p);
    public:
        ObjType& operator*();               // mutator of operator*
        const ObjType& operator*() const;   // accessor of operator*
        iterator& operator++();
        iterator  operator++(int);
        iterator& operator+(int n);
        iterator& operator--();
        iterator  operator--(int);
        iterator& operator-(int n);
    };
public:
    List();
    List(const List& rhs);
    List(List&& rhs);
    List& operator=(const List& rhs);
    List& operator=(List&& rhs);
    ~List();
private:
    int m_size;
    Node *head;
    Node *tail;

    void init();
public:
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    int size() const;
    bool empty() const;
    void clear();
    ObjType& front();
    const ObjType& front() const;
    ObjType& back();
    const ObjType& back() const;
    void push_front(const ObjType& obj);
    void push_front(ObjType&& obj);
    void push_back(const ObjType& obj);
    void push_back(ObjType&& obj);
    void pop_front();
    void pop_back();
    iterator insert(iterator itr, const ObjType& obj);
    iterator insert(iterator itr, ObjType&& obj);
    iterator erase(iterator itr);
    iterator erase(iterator from, iterator to);
};

#include "List_impl.hpp"


