/*!
 *  \file       hash_table.hpp
 *  \brief
 *
 */


#pragma once


#include <vector>
#include <list>
#include <string>

#include "../hash.hpp"

/* Prototype =====================================================================================*/

/*!
 *  \class      HashTable<HashedObj>
 *  \brief      分离链接Hash表,   separate chaining hash table
 *
 */
template<typename HashedObj>
class HashTable
{
public:
    explicit HashTable(int size = 101);
private:
    std::vector<std::list<HashedObj>> theLists;
    int currentSize;
public:
    bool contains(const HashedObj& obj) const;
    void makeEmpty();
    bool insert(const HashedObj& new_obj);
    bool insert(HashedObj&& new_obj);
    bool remove(const HashedObj& obj);
private:
    void rehash();
    size_t myhash(const HashedObj& obj) const;
};

/*================================================================================================*/
#include "hash_table_impl.hpp"
