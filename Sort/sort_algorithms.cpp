#include <algorithm>
using namespace std;

template<typename T> void insertion_sort(T data[], int n)
{
    for (int i = 1, j; i < n; ++i)
    {
        T tmp = data[i];
        for (j = i; (j > 0) && (tmp < data[j-1]); j--)
        {
            data[j] = data[j-1];
        }
        data[j] = tmp;
    }
}

template<typename T> void selection_sort(T data[], int n)
{
    for (int i = 0, j, least; i < n-1; i++)
    {
        for (j = i+1, least = i; j < n; j++)
        {
            if (data[j] < data[least])
            {
                least = j;
            }
        }
        swap(data[least], data[i]);
    }
}


template<typename T> void bubble_sort(T data[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (data[j] < data[j-1])
            {
                swap(data[j], data[j-1]);
            }
        }
    }
}

template<typename T> void comb_sort(T data[], int n)
{
    int step = n, j, k;
    while ((step = int(step/1.3)) > 1)
    {
        for (j = n-1; j >= step; j--)
        {
            k = j-step;
            if (data[j] < data[k])
            {
                swap(data[j], data[k]);
            }
        }
    }

    bool again = true;
    for (int i = 0; (i < n-1) && again; i++)
    {
        for (j = n-1, again = false; j > i; --j)
        {
            if (data[j] < data[j-1])
            {
                swap(data[j], data[j-1]);
                again = true;
            }
        }
    }
}

template<typename T> void heap_sort(T data[], int size)
{
    for (int i = size/2 - 1; i>= 0; i--)
    {
        move(data, i, size-1);
    }
    for (int i = size-1; i >= 1; i--)
    {
        swap(data[0], data[i]);
        move(data, 0, i-1);
    }
}

template<typename T> void quick_sort(T data[], int first, int last)
{
    int lower = first+1, upper = last;
    swap(data[first], data[(first+last)/2]);
    T bound = data[first];
    while (lower <= upper)
    {
        while (data[lower] < bound)
        {
            lower++;
        }
        while (bound < data[upper])
        {
            upper--;
        }
        if (lower < upper)
        {
            // qsort()
            swap(data[lower++], data[upper--]);
        }
        else
        {
            lower++;
        }
    }
    swap(data[upper], data[first]);
    if (first < upper-1)
    {
        quick_sort(data, first, upper-1);
    }
    if (upper+1 < last)
    {
        quick_sort(data, upper+1, last);
    }
}

template<typename T> void quick_sort(T data[], int n)
{
    int i, max;
    if (n < 2)
    {
        return;
    }
    for (i = 1, max = 0; i < n; i++)
    {
        if (data[max] < data[i])
        {
            max = i;
        }
    }
    swap(data[n-1], data[max]);
    quick_sort(data, 0, n-2);
}
