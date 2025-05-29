/*!
 *  \file       sort_algorithms.cpp
 *  \brief      
 *  
 */


#include "sort_algorithms.hpp"

#include <algorithm>

template<typename T>
void insert_sort(T data[], int n)
{
    for (int i = 1, j; i < n; ++i)
    {
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; --j)
        {
            data[j] = data[j-1];
        }
        data[j] = tmp;
    }
}

template<typename T> 
void select_sort(T data[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_element_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (data[j] < data[min_element_index])
            {
                min_element_index = j;
            }
        }

        std::swap(data[i], data[min_element_index]);
    }
}

template<typename T> 
void bubble_sort(T data[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (data[j] < data[j-1])
            {
                std::swap(data[j], data[j-1]);
            }
        }
    }
}

template<typename T> 
void improved_bubble_sort(T data[], int n)
{
    bool swap_again_flag = true;
    for (int i = 0; i < n - 1 && swap_again_flag; ++i)
    {
        for (int j = n - 1, swap_again_flag = false; j > i; --j)
        {
            if (data[j] < data[j-1])
            {
                std::swap(data[j], data[j-1]);
                swap_again_flag = true;
            }
        }
    }
}

template<typename T> 
void comb_sort(T data[], int n)
{
    int step = n;
    while ((step = static_cast<int>(step / 1.3)) > 1)   // Phase 1
    {
        for (int j = n - 1; j >= step; --j)
        {
            int k = j - step;
            if (data[j] < data[k])
            {
                std::swap(data[j], data[k]);
            }
        }
    }

    bool swap_again_flag = true;
    for (int i = 0; i < n - 1 && swap_again_flag; ++i)     // Phase 2
    {
        for (int j = n - 1, swap_again_flag = false; j > i; --j)
        {
            if (data[j] < data[j-1])
            {
                std::swap(data[j], data[j-1]);
                swap_again_flag = true;
            }
        }
    }
}

template<typename T> 
void shell_sort(T data[], int n)
{

}