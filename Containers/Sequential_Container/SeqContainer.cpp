#include "SeqContainer.h"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

bool findElementFromIteratorRange(vector<int>::const_iterator start,
    vector<int>::const_iterator stop,
    int elementToFind);
void printOutConsoleLines(void);
void split_list_container(list<int> origin, deque<int>& odd, deque<int>& even);


void intialize_seq_container(void)
{
    vector<string> svec;
    svec.push_back("Prosperity");
    svec.push_back("Democracy");
    svec.push_back("Civility");
    svec.push_back("Harmony");
    svec.push_back("Freedom");
    svec.push_back("Equality");
    svec.push_back("Justice");
    svec.push_back("Rule of law");
    svec.push_back("Patriotism");
    svec.push_back("Dedication");
    svec.push_back("Integrity");
    svec.push_back("Friendship");

    vector<string> core_socialist_values(svec);
    cout << "The core socialist values are : " << endl;
    for (vector<string>::const_iterator citer = core_socialist_values.begin(); citer != core_socialist_values.end(); ++citer)
    {
        cout << *citer << endl;
    }

    /* intialize slist with copy of each element of svec */
    list<string> slist(svec.begin() + 1, svec.end() - 1);
    /* find the midpoint in the vector */
    vector<string>::iterator mid = svec.begin() + svec.size() / 2;
    /* initialize front with first half of svec : The elements up to but not including *mid */
    deque<string> front(svec.begin(), mid);
    /* initialize back with second half of svec : The elements *mid through end of svec */
    deque<string> back(mid, svec.end());

    typedef char string_t[20];
    string_t words[] = { "stately", "plump", "buck", "milligan" };
    /* calculate how many elements in words array */
    size_t words_size = sizeof(words) / sizeof(string_t);
    /* use entire array to initialize words_list */
    list<string> words_list(words, words + words_size);

    string sa[6] = {"Fort Sumter", "Manassas", "Perryville", "Vicksburg", "Meridian", "Chancellorsville"};
    vector<string> strvec(sa, sa + 6);
    list<string> strlist(sa, sa + 6);       /* tansposed pointer range */
    for (list<string>::const_iterator cit = strlist.begin(); cit != strlist.end(); ++cit)
    {
        cout << *cit << endl;
    }
}

void allocate_seq_container_elements(void)
{
    const list<int>::size_type list_size = 64;
    list<string> slist(list_size, "eh?");       /* 64 strings, each element is "eh?" */
    list<int> ilist(list_size);     /* 64 elements, each intialized to 0 */

#if 0
    extern unsigned get_word_count(const string & file_name);
    /* svec has as many elements as the return value from get_word_count */
    vector<string> svec(get_word_count("Chimera"));
#endif
    /* vector of vectors */
    vector< vector<string> > lines;     /* OK : space required between close > */
    // vector< vector<string>> vec_lines;      /* Error : >> treated as shift operator */
    list< deque<int> > lstdq;
}

void utilize_container_defined_types(void)
{
    /* iter is the iterator type-defined by list<string> */
    list<string>::iterator iter;
    /* cnt is the difference_type type-defined by vector<int> */
    vector<int>::difference_type cnt;

    list<int> ilist;
    for (size_t ix = 0; ix != 4; ++ix)
    {
        ilist.push_back(ix);
    }
    for (size_t idx = 100; idx != 90; --idx)
    {
        ilist.push_front(idx);
    }
    for (list<int>::const_reverse_iterator criter = ilist.rbegin(); criter != ilist.rend(); ++criter)
    {
        cout << *criter << endl;
    }

    deque<int> odd, even;
    split_list_container(ilist, odd, even);
}

void manipulate_container(void)
{
    vector<string> svec;
    list<string> slist;
    string spouse("Beth");
    /* equivalent to calling slist.push_front(spouse) */
    slist.insert(slist.begin(), spouse);

    /* no push_front on vector, but we can insert before begin()
     * warning: inserting anywhere but at the end of a vector is an expensive operation.
     */
    svec.insert(svec.begin(), spouse);
    svec.insert(svec.end(), 10, "Anna");

#if 0
    /* repeatly insert the new element in the front of list */
    list<string> lst;
    list<string>::iterator iter = lst.begin();
    string word;
    while (cin >> word)
    {
        iter = lst.insert(iter, word);      /* same as calling push_front */
    }
#endif

    string sarray[4] = {"Quasi", "Simba", "Frollo", "Scar"};
    /* insert all the elements in sarray at end of slist */
    slist.insert(slist.end(), sarray, sarray + 4);
    // list<string>::iterator slist_iter = (slist.begin() + 2);    /* list<> container class does not overload the iterator + arithmetic operator */
    vector<string>::iterator vec_iter = (svec.begin() + 2);
    svec.insert(vec_iter, sarray, sarray + 3);

    vector<int> ivec(1, 10);
    vector<int>::iterator first = ivec.begin(), last = ivec.end();      /* cache end iterator */
    int number = 42;
#if defined (NOT_FLUSH_END_ITERATOR)
    /* disaster : behaviour of this loop is undefined */
    while (first != last)       /* here last iterator had not been refreshed, invalid iterator */
#else
    /* safer : recalculate end on each trip whenever the loop adds/erases elements */
    while (first != ivec.end())
#endif
    {
        /* do some processing 
         * insert new value and reassign first, which otherwise would be invalid 
         */
        first = ivec.insert(first, number++);
        ++first;    /* advance first just past the element we added */
        if (ivec.size() >= 25)
        {
            break;
        }
    }
}

/*=================================================================================================*/
/* Exercises : */
bool findElementFromIteratorRange(vector<int>::const_iterator start,
                                  vector<int>::const_iterator stop,
                                  int elementToFind)
{
    for (vector<int>::const_iterator cit = start; cit == stop; ++cit)
    {
        if (*cit == elementToFind)
        {
            return true;
        }
    }
    return false;
}

void printOutConsoleLines(void)
{
    vector<string> lines;
    string line;
    while (getline(cin, line))
    {
        lines.push_back(line);
    }

    for (vector<string>::const_iterator cit = lines.begin(); cit != lines.end(); ++cit)
    {
        cout << *cit << endl;
    }
}

void split_list_container(const list<int> origin, deque<int>& odd, deque<int>& even)
{
    for (list<int>::const_iterator iter = origin.begin(); iter != origin.end(); ++iter)
    {
        int number = *iter;
        if (number % 2 == 0)
        {
            even.push_back(number);
        }
        else
        {
            odd.push_back(number);
        }
    }
}