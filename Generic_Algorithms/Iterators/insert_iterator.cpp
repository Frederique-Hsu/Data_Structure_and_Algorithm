#include "iterators.h"

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void insert_container_through_inserter_iterator(void)
{
    list<int> ilst;
    vector<int> ivec;
    int num;
    while (cin >> num)
    {
        ilst.push_back(num);
        ivec.push_back(num * num);
    }

    /* position an iterator into ilst */
    list<int>::iterator it = find(ilst.begin(), ilst.end(), 42);
    /* insert replaced copies of ivec at that point in ilst */
    replace_copy(ivec.begin(), ivec.end(), inserter(ilst, it), 100, 0);
}