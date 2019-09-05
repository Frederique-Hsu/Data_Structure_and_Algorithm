#include "AssociativeContainer.h"

#include <map>
#include <string>
#include <list>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

void initialize_map_objects(void)
{
    /* count number of times each word occurs in the input */
    map<string, int> word_cnt;

    map< string, list<int> > word_line_numbers;
    map< vector<int>::iterator, int > mymap;
    map< pair<int, string>, int > pair_map;
}

void access_map_objects(void)
{
    map<string, int> word_cnt;      /* empty map */
    /* insert default initialized element with key Anna; then assign 1 to its value */
    word_cnt["Anna"] = 1;

    /* get an iterator to an element in word_cnt */
    map<string, int>::iterator map_it = word_cnt.begin();
    /* *map_it is a reference to a pair<const string, int> object */
    cout << "The key = " << map_it->first << endl;      /* prints out the key for this element */
    cout << ", and the value = " << map_it->second << endl;     /* prints out the value of the element */
    // map_it->first = "new key";      /* error : key is const */
    ++map_it->second;       /* OK: we can change value through an iterator */

    typedef map<string, int>::key_type Key;
    typedef map<string, int>::mapped_type Value;
    typedef map<string, int>::value_type KVP;

    word_cnt["Alice"] = 10;
    cout << word_cnt["Anna"] << endl;   /* fetch element indexed by Anna; prints 1 */
    ++word_cnt["Anna"];     /* fetch the element and add one to it */
    cout << word_cnt["Anna"] << endl;

    string word;
#if 0
    while (cin >> word)
    {
        ++word_cnt[word];
    }
#endif
    word_cnt.insert(KVP("Frederick", 5));
    word_cnt.insert(make_pair("Perfect", 8));

    while (cin >> word)
    {
        /* inserts element with key equal to word and value 1;
         * if word already in word_cnt, insert does nothing.
         */
        pair<map<string, int>::iterator, bool> ret = word_cnt.insert(KVP(word, 1));
        if (!ret.second)
        {
            ++((ret.first)->second);    /* increment counter */
        }
    }
    int occurs;
    if (word_cnt.count("Foobar"))
    {
        occurs = word_cnt["Foobar"];
        cout << "The key \"Foobar\" occurs " << occurs << " time(s)." << endl;
    }
    map_it = word_cnt.find("foobar");
    if (map_it != word_cnt.end())
    {
        occurs = map_it->second;
    }
}

void traverse_map_through_iterator(void)
{
    map<string, int> word_count;

    typedef map<string, int>::key_type      Key;
    typedef map<string, int>::mapped_type   Value;
    typedef map<string, int>::value_type    KVP;

    string word;
    while (cin >> word)
    {
        ++word_count[word];
    }
    /* get iterator positioned on the first element */
    map<string, int>::const_iterator map_cit = word_count.begin();
    /* for each element in the map */
    while (map_cit != word_count.end())
    {
        /* print the element key-value pairs */
        cout << "The word \"" << map_cit->first << "\" occurs " << map_cit->second << " times." << endl;
        ++map_cit;      /* increment iterator to denote the next element */
    }
}