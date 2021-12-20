/*!
 *  \file   Vector.hpp
 *  \brief  Define the class template Vector<T>
 *  \author Frederique Hsu
 *  \date   Sun.    19 Dec. 2021
 *
 */

#pragma once

#include <functional>

template<typename ObjType> class Vector
{
    static const int SPARE_CAPACITY;
public:
    explicit Vector(int initSize);
    Vector();
    Vector(const Vector& rhs);
    Vector& operator=(const Vector& rhs);
    ~Vector();
    Vector(Vector&& rhs);
    Vector& operator=(Vector&& rhs);
private:
    int m_size;
    int m_capacity;
    ObjType* m_objects;
public:
    void resize(int newSize);
    void reserve(int newCapacity);
    ObjType& operator[](int index);
    const ObjType& operator[](int index) const;
    bool empty() const;
    int size() const;
    int capacity() const;
    void push_back(const ObjType& obj);
    void push_back(ObjType&& obj);
    void pop_back();
    const ObjType& back() const;
public:
    typedef ObjType* iterator;
    typedef const ObjType* const_iterator;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
};


#include "Vector_impl.hpp"
