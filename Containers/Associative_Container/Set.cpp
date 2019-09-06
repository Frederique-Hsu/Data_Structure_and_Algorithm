#include "Set.h"

#include <iostream>
#include <set>
#include <vector>

using namespace std;

void utilize_set_container(void)
{
    /* define a vector with 20 elements, holding 2 copies of each number from 0 to 9 */
    vector<int> ivec;
    for (vector<int>::size_type idx = 0; idx != 10; ++idx)
    {
        ivec.push_back(idx);
        ivec.push_back(idx);    /* duplicate copies of each number */
    }

    set<int> iset(ivec.begin(), ivec.end());    /* iset holds unique elements from ivec */
    cout << "The size of ivec is: " << ivec.size() << endl;
    cout << "The size of iset is: " << iset.size() << endl;
    set<int> intset;
    intset.insert(ivec.begin(), ivec.end());
    set<int>::iterator it = intset.find(5);
    set<int>::size_type count = intset.count(8);

    set<string> strset;
    strset.insert("the");
    strset.insert("and");
    pair<set<string>::iterator, bool> setpair = strset.insert("the");
    if (setpair.second == false)
    {
        cout << "The key \"" << *(setpair.first) << "\" was actually not inserted into set." << endl;
    }
}

void restricted_wc(ifstream& remove_file, map<string, int>& word_count)
{
    set<string> excluded;   /* set to hold words we will ignore */
    string remove_word;
    while (remove_file >> remove_word)
    {
        excluded.insert(remove_word);
    }
    /* read input and keep a count for words that are not in the exclusion set */
    string word;
    while (cin >> word)
    {
        /* increment counter only if the word is not in excluded */
        if (!excluded.count(word))
        {
            ++word_count[word];
        }
    }
}