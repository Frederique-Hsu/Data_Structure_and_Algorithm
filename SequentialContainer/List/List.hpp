/*!
 *  \file   List.hpp
 *  \brief  Define the structure of List container.
 *
 */

#pragma once

#include <functional>

template<typename ObjType> class List
{
private:
    struct Node
    {
        ObjType  data;
        Node    *prev;
        Node    *next;

        Node(const ObjType& d = ObjType{}, Node *prevnode = nullptr, Node *nextnode = nullptr);
        Node(ObjType&& d, Node *prevnode = nullptr, Node *nextnode = nullptr);
    };
public:
    class const_iterator
    {
        friend class List<ObjType>;
    public:
        const_iterator();
    protected:
        Node *current;
        const_iterator(Node *p);
    public:
        const ObjType& operator*() const;
        const_iterator& operator++();
        const_iterator  operator++(int);
        bool operator==(const const_iterator& rhs) const;
        bool operator!=(const const_iterator& rhs) const;
    protected:
        ObjType& retrieve() const;
    };

    class iterator : public const_iterator
    {
        friend class List<ObjType>;
    public:
        iterator();
    protected:
        iterator(Node *p);
    public:
        ObjType& operator*();
        const ObjType& operator*() const;
        iterator& operator++();
        iterator operator++(int);
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


