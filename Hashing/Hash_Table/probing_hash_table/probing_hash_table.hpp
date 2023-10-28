/*!
 *  \file       probing_hash_table.hpp
 *  \brief
 *
 */



#pragma once

#include <vector>
#include <cstddef>

/* Prototype =====================================================================================*/

int nextPrime(int table_size);

template<typename HashedObj>
class HashTable
{
public:
    enum EntryType
    {
        ACTIVE,
        EMPTY,
        DELETED
    };
private:
    struct HashEntry
    {
        HashedObj   element;
        EntryType   info;

        HashEntry(const HashedObj& elem = HashedObj{}, EntryType i = EMPTY);
        HashEntry(HashedObj&& elem, EntryType i = EMPTY);
    };

    std::vector<HashEntry> array;
    int currentSize;
public:
    explicit HashTable(int size = 101);

    bool contains(const HashedObj& obj) const;
    void makeEmpty();
    bool insert(const HashedObj& obj);
    bool insert(HashedObj&& obj);
    bool remove(const HashedObj& obj);
private:
    bool isActive(int currentPos) const;
    int findPos(const HashedObj& obj) const;
    void rehash();
    size_t myhash(const HashedObj& obj) const;
};


/* Implementation ================================================================================*/

template<typename HashedObj>
HashTable<HashedObj>::HashTable(int size) : array(nextPrime(size))
{
    makeEmpty();
}

template<typename HashedObj>
HashTable<HashedObj>::HashEntry::HashEntry(const HashedObj& elem, EntryType i)
    : element(elem), info(i)
{
}

template<typename HashedObj>
HashTable<HashedObj>::HashEntry::HashEntry(HashedObj&& elem, EntryType i)
    : element(std::move(elem)), info(i)
{
}

template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    currentSize = 0;

    for (auto& entry : array)
    {
        entry.infor = EMPTY;
    }
}

template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj& obj) const
{
    return isActive(findPos(obj));
}

template<typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
    return array[currentPos].info == ACTIVE;
}

template<typename HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj& obj) const
{
    int offset = 1;
    int currentPos = myhash(obj);

    while ((array[currentPos].info != EMPTY) and (array[currentPos].element != obj))
    {
        currentPos += offset;       // 计算第i次探测
        offset += 2;
        if (currentPos >= array.size())
        {
            currentPos -= array.size();
        }
    }
    return currentPos;
}

template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj& obj)
{
    int currentPos = findPos(obj);
    if (isActive(currentPos))
    {
        return false;
    }

    array[currentPos].element = obj;
    array[currentPos].info = ACTIVE;

    if (++currentSize > array.size()/2)
    {
        rehash();
    }
    return true;
}

template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj& obj)
{
    int currentPos = findPos(obj);
    if (!isActive(currentPos))
    {
        return false;
    }
    array[currentPos].info = DELETED;
    return true;
}

template<typename HashedObj>
bool HashTable<HashedObj>::insert(HashedObj&& obj)
{
    HashedObj& new_obj = std::move(obj);
    return insert(new_obj);
}
