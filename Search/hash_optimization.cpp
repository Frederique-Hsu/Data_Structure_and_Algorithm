/*!
 *  \file       hash_optimization.cpp
 *  \brief      
 *  
 */


#include "hash_optimization.hpp"

#include <unordered_map>


template<typename T>
std::vector<T> twoSumBruteForce(const std::vector<int>& nums, T target)
{
    int size = nums.size();

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

template<typename T>
std::vector<T> twoSumHashTable(const std::vector<T>& nums, T target)
{
    int size = nums.size();

    using Element = T;
    using Index = int;
    std::unordered_map<Element, Index> dict;

    for (int i = 0; i < size; ++i)
    {
        if (dict.find(target - nums[i]) != dict.end())
        {
            return {dict[target - nums[i]], i};
        }
        dict.emplace(nums[i], i);
    }
    return {};
}