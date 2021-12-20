/*!
 *  \file   MemoryCell.hpp
 *  \brief  Define a class template MemoryCell
 *  \author Frederique Hsu (frederique.hsu@outlook.com)
 *  \date   Tue.    14 Dec. 2021
 *
 */

#pragma once

/* Prototypes */

/*!
 *  \class  MemoryCell<ObjectType>
 *  \brief  A class simulating a memory cell.
 */
template<typename ObjectType> class MemoryCell
{
public:
    explicit MemoryCell(const ObjectType& initialValue = ObjectType{});
private:
    ObjectType storedValue;
public:
    const ObjectType& read() const;
    void write(const ObjectType& obj);
};


/* Implementations */
#include "MemoryCell_impl.hpp"
