#include "Map.h"

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

void insert_erase_multimap_elements(void)
{
    multimap<string, string> authors;
    typedef multimap<string, string>::value_type    KVP;
    typedef multimap<string, string>::key_type      Key;
    typedef multimap<string, string>::mapped_type   Value;

    /* adds first element with key Barth */
    authors.insert(make_pair(string("Barth, John"), string("Sot-Weed Factor")));
    authors.insert(KVP("Alain de Botton", "Head First HTML, CSS & JavaScript"));
    /* adds second element with key Barth */
    authors.insert(make_pair(string("Barth, John"), string("Lost in the Funhouse")));
    authors.insert(pair<string, string>("Adam Drozdek", "Data Structures and Algorithms in C++"));
    authors.insert(KVP("Stanley B. Lippman", "C++ Primer"));
    authors.insert(pair<string, string>("Alain de Botton", "Qt 5 development"));
    authors.insert(make_pair("Josee Lajoie", "C++ Primer"));
    authors.insert(make_pair("Barbara E. Moo", "C++ Primer"));
    authors.insert(KVP("Alain de Botton", "Build the embedded Linux system"));

    string search_item("Kazuo Ishiguro");
    /* erase all elements with this key; returns number of elements removed. */
    multimap<string, string>::size_type cnt = authors.erase(search_item);

    multimap<string, string>::iterator iter_to_erase = authors.find("Josee Lajoie");
    iter_to_erase = authors.erase(iter_to_erase);

    Key search_author("Alain de Botton");;
    /* how many entries are there for this author */
    typedef multimap<string, string>::size_type sz_type;
    sz_type entries = authors.count(search_author);
    /* get iterator to the first entry for this author */
    multimap<string, string>::iterator iter = authors.find(search_author);
    /* loop through the number of entries there are for this author */
    for (sz_type cnt = 0; cnt != entries; ++cnt, ++iter)
    {
        cout << iter->second << endl;   /* print out each book title */
    }
    cout << "\n\n" << endl;

    /* begin and end iterators denotes range of elements for this author */
    typedef multimap<string, string>::iterator author_iter;
    author_iter begin = authors.lower_bound(search_author),
        end = authors.upper_bound(search_author);
    /* loop through the number of entries there are for this author */
    while (begin != end)
    {
        cout << begin->second << endl;
        ++begin;
    }
    cout << "\n\n" << endl;

    pair<author_iter, author_iter> pos = authors.equal_range(search_author);
    while (pos.first != pos.second)
    {
        cout << pos.first->second << endl;
        pos.first++;
    }

    pos = authors.equal_range("Barth, John");
    authors.erase(pos.first, pos.second);
}