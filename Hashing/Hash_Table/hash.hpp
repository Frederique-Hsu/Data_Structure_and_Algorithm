/*!
 *  \file       hash.hpp
 *  \brief
 *
 */


#pragma once

#include <cstddef>
#include <string>

#include "separate_chaining_hash_table/employee.hpp"

template<typename Key> class hash
{
public:
    size_t operator()(const Key& key) const;
};

template<> class hash<std::string>
{
public:
    size_t operator()(const std::string& key) const;
};

template<> class hash<Employee>
{
public:
    size_t operator()(const Employee& item) const;
};


#include "hash_impl.hpp"
