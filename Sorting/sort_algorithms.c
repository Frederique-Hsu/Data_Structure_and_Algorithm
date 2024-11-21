/*!
 *  \file       sort_algorithms.c
 *  \brief      
 *  
 */


#include "sort_algorithms.h"

void insert_sort(DataType data[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        DataType tmp = data[i];
        int j;
        for (j = i; 
             j > 0 && tmp < data[j-1]; 
             --j)
        {
            data[j] = data[j-1];
        }
        data[j] = tmp;
    }
}

void select_sort(DataType data[], int n)
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
        // swap the data[i] and data[min_element_index]
        {
            DataType tmp = data[i];
            data[i] = data[min_element_index];
            data[min_element_index] = tmp;
        }
    }
}

void bubble_sort(DataType data[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (data[j] < data[j-1])
            {
                DataType tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp; 
            }
        }
    }
}