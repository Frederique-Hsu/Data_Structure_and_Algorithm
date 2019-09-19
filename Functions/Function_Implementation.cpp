#include "Function_Prototype.h"
#include <cstdlib>
#include <iostream>

int gcd(int v1, int v2)
{
    while (v2)
    {
        int temp = v2;
        v2 = v1 % v2;
        v1 = temp;
    }
    return v1;
}

void process(void)      /* equivalent to void process() */
{
}

void reset(int *ip)
{
    *ip = 0;    /* change the value of the object to which ip points */
    ip = 0;     /* change only the local value of ip; the argument is unchanged */
}

#if !defined (REFERENCE_PARAMETERS)
void swap(int v1, int v2)
{
    int temp = v2;
    v2 = v1;        /* assigns new value to local copy of the argument */
    v1 = temp;
}       /* local objects v1 and v2, no longer exist */
#else
void swap(int& v1, int& v2)
{
    if (v1 == v2)
        return;
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
}
#endif
void ptrswap(int *&v1, int *&v2)
/* swap values of 2 pointers to int */
{
    int *tmp = v2;
    v2 = v1;
    v1 = tmp;
}

vector<int>::const_iterator find_val(vector<int>::const_iterator beg,
                                     vector<int>::const_iterator end,
                                     int value,
                                     vector<int>::size_type& occurs)
/* return an iterator that refers to the first occurrence of value,
 * the reference parameter occurs contains a second return value.
 */
{
    vector<int>::const_iterator res_iter = end;
    occurs = 0;     /* set occurrence count parameter */
    for (; beg != end; ++beg)
    {
        if (*beg == value)
        {
            if (res_iter == end)    /* remember first occurrence of value */
            {
                res_iter = beg;
            }
            ++occurs;   /* increment occurrence count */
        }
    }
    return res_iter;
}

bool isShorter(const string& s1, const string& s2)
/* compare the length of two strings. */
{
    return s1.size() < s2.size();
}

int incr(int &val)
/* function takes a non-const reference parameter */
{
    return ++val;
}

string::size_type find_char(const string& s, char c)
/* returns index of fist occurrence of c in s or s.size() if c isn't in s
 * Note: s doesn't change, so it should be a reference to const
 */
{
    string::size_type i = 0;
    while (i != s.size() && s[i] != c)
    {
        ++i;
    }
    return i;
}

bool is_sentence(const string& s)
{
    return (find_char(s, '.') == s.size()-1);
}

void print(vector<int>::const_iterator beg, vector<int>::const_iterator end)
/* pass iterators to the first and one past the last element to print */
{
    while (beg != end)
    {
        cout << *beg++;
        if (beg != end)
        {
            cout << " ";
        }
    }
    cout << endl;
}

void printValues(const int iarr[], size_t size)
/* const int iarr[] is equivalent to const int* iarr
 * size is passed explicitly and used to control access to element of iarr
 */
{
    for (size_t index = 0; index != size; ++index)
    {
        cout << iarr[index] << endl;
    }
}

void printValues(int (&arr)[10])
/* parameter is a reference to an array; size of array is fixed */
{
    for (size_t index = 0; index != 10; ++index)
    {
        cout << arr[index] << endl;
    }
}

string make_plural(size_t ctr, const string& word, const string& ending)
/* return plural version of a word if ctr > 1 */
{
    return ((ctr == 1) ? word : word + ending);
}

const string& shorterString(const string& s1, const string& s2)
/* find longer of two strings */
{
    return (s1.size() < s2.size() ? s1 : s2);
}

char& get_val(string& str, string::size_type pos)
{
    return str[pos];
}
