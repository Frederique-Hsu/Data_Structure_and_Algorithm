/*!
 *  \file       search.cpp
 *  \brief      
 *  
 */


#include "search.hpp"

template<typename T>
int binarySearch(T nums[], std::size_t len, T target)
{
    int head_index = 0, tail_index = len - 1;

    while (head_index <= tail_index)
    {
        int mid_index = (head_index + tail_index) / 2;
        if (nums[mid_index] < target)
        {
            head_index = mid_index + 1;
        }
        else if (target < nums[mid_index])
        {
            tail_index = mid_index - 1;
        }
        else if (nums[mid_index] == target)
        {
            return mid_index;
        }
    }
    return -1;
}

template<typename T>
int binarySearchLeftCloseRightOpen(T nums[], std::size_t len, T target)
{
    int head_index = 0, tail_index = len;
    
    while (head_index < tail_index)
    {
        int mid_index = (head_index + tail_index) / 2;
        if (nums[mid_index] < target)
        {
            head_index = mid_index + 1;
        }
        else if (target < nums[mid_index])
        {
            tail_index = mid_index;
        }
        else
        {
            return mid_index;
        }
    }
    return -1;
}

template<typename T>
int binarySearchInsertion(const std::vector<T>& nums, T target)
{
    int head_index = 0, tail_index = nums.size() - 1;

    while (head_index <= tail_index)
    {
        int mid_index = (head_index + tail_index) / 2;
        if (nums[mid_index] < target)
        {
            head_index = mid_index + 1;
        }
        else if (target < nums[mid_index])
        {
            tail_index = mid_index - 1;
        }
        else
        {
            return mid_index;
        }
    }
    return head_index;
}

template<typename T>
int binarySearchInsertionDuplicate(const std::vector<T>& nums, T target)
{
    int head_index = 0, tail_index = nums.size() - 1;
    while (head_index <= tail_index)
    {
        int mid_index = (head_index + tail_index) / 2;
        if (nums[mid_index] < target)
        {
            head_index = mid_index + 1;
        }
        else if (target < nums[mid_index])
        {
            tail_index = mid_index - 1;
        }
        else
        {
            return mid_index - 1;
        }
    }
    return head_index;
}