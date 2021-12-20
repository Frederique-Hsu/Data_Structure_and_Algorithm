/*!
 *  \file   MemoryCell_impl.hpp
 *  \brief  Implement the class template MemoryCell
 *  \author Frederique Hsu (frederique.hsu@outlook.com)
 *  \date   Tue.    14 Dec. 2021
 *
 */


template<typename ObjectType> MemoryCell<ObjectType>::MemoryCell(const ObjectType& initialValue)
    : storedValue{initialValue}
{
}

template<typename ObjectType> const ObjectType& MemoryCell<ObjectType>::read() const
{
    return storedValue;
}

template<typename ObjectType> void MemoryCell<ObjectType>::write(const ObjectType& obj)
{
    storedValue = obj;
}
