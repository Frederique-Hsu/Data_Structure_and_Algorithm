/*!
 *  \file       hash_table_impl.hpp
 *  \brief
 *
 */


#include <cstddef>

/* Implementation ================================================================================*/

template<typename HashedObj>
size_t HashTable<HashedObj>::myhash(const HashedObj& obj) const
{
    static hash<HashedObj> hash_fn;
    return hash_fn(obj) % theLists.size();
}

template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    /*!
     *  \warning    此处必须为list选择引用类型，否则list为拷贝值，其并不能清除theLists的实际内容。
     */
    for (auto& list : theLists)
    {
        list.clear();
    }
    currentSize = 0;
}

template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj& obj) const
{
    auto& whichList = theLists[myhash(obj)];
    return std::find(std::begin(whichList), std::end(whichList), obj) != std::end(whichList);
}

template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj& obj)
{
    std::list<HashedObj>& whichList = theLists[myhash(obj)];

    auto iter = std::find(std::begin(whichList), std::end(whichList), obj);
    if (iter == std::end(whichList))
    {
        return false;
    }
    whichList.erase(iter);
    --currentSize;
    return true;
}

template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj& new_obj)
{
    std::list<HashedObj>& whichList = theLists[myhash(new_obj)];

    // 检查链表中是否存在obj？
    if (std::find(std::begin(whichList), std::end(whichList), new_obj) != std::end(whichList))
    {
        return false;
    }
    whichList.push_front(new_obj);

    if (++currentSize > theLists.size())
    {
        rehash();
    }
    return true;
}
