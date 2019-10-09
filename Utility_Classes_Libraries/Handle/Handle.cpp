/**************************************************************************************************
 * File name    : Handle.cpp
 * Description  : Impelement the smart generic Handle class.
 * Creator      : Frederick Hsu
 * Creation date: Mon.  07 Oct. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <stdexcept>

template<class T> Handle<T>::Handle(T *p) : ptr(p), use(new size_t(1))
{
}

template<class T> Handle<T>::Handle(const Handle& h) : ptr(h.ptr), use(h.use)
{
    ++(*use);
}

template<class T> Handle<T>::~Handle()
{
    rem_ref();
}

template<class T> void Handle<T>::rem_ref()
{
    if (--(*use) == 0)
    {
        delete ptr;
        delete use;
    }
}

template<class T> Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
    ++(*(rhs.use));     /* protect against selft-assignment */
    rem_ref();          /* decrement use count and delete pointers if needed */
    ptr = rhs.ptr;
    use = rhs.use;
    return *this;
}

template<class T> inline T& Handle<T>::operator*()
{
    if (ptr)
    {
        return *ptr;
    }
    throw std::runtime_error("dereference of unbound Handle.");
}

template<class T> inline T* Handle<T>::operator->()
{
    if (ptr)
    {
        return ptr;
    }
    throw std::runtime_error("access through unbound Handle.");
}

template<class T> inline const T& Handle<T>::operator*() const
{
    if (ptr)
    {
        return *ptr;
    }
    throw std::runtime_error("dereference of unbound Handle.");
}

template<class T> inline const T* Handle<T>::operator->() const
{
    if (ptr)
    {
        return ptr;
    }
    throw std::runtime_error("access through unbound Handle.");
}
