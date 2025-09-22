/*!
 *  \file       search.hpp
 *  \brief      
 *  
 */


#pragma once

#include <cstdint>
#include <vector>

template<typename T> int binarySearch(T nums[], std::size_t len, T target);

template<typename T> int binarySearchLeftCloseRightOpen(T nums[], std::size_t len, T target);

/*!
 *  \note   不存在重复元素的
 */
template<typename T> int binarySearchInsertion(const std::vector<T>& nums, T target);

template<typename T> int binarySearchInsertionDuplicate(const std::vector<T>& nums, T target);