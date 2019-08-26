#include "SeqContainer.h"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

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
}