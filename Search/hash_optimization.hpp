/*!
 *  \file       hash_optimization.hpp
 *  \brief      
 *  
 */


#pragma once

#include <vector>

/*!
 *  \note   给定一个数组 nums 和一个目标元素 target, 请在数组中搜索“和”为 target 的两个元素，
 *          并返回它们的数组索引，返回任意一个解即可。
 */
template<typename T>
std::vector<T> twoSumBruteForce(const std::vector<int>& nums, T target);

template<typename T>
std::vector<T> twoSumHashTable(const std::vector<T>& nums, T target);