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

    set<string> strset;
    strset.insert("the");
    strset.insert("and");
}