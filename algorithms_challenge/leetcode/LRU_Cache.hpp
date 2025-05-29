/*!
 *  \file       LRU_Cache.hpp
 *  \brief      
 *  
 */


#pragma once

class LRUCache
{
public:
    LRUCache(int capacity);
private:

public:
    int get(int key);
    void put(int key, int value);
};