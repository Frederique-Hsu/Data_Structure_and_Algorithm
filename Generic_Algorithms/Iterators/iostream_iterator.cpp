#include "iterators.h"
#include "../../Utility_Classes_Libraries/Sales_Item/Sales_item.h"

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

void define_iostream_iterators(void)
{
    istream_iterator<int> cin_it(cin);      /* read ints from cin */
    istream_iterator<int> end_of_stream;    /* end iterator value */
    /* write Sales_items from the ofstream named outfile
     * each elements is followed by a space 
     */
    istream_iterator<int> eof;
    vector<int> vec(cin_it, eof);
    /* read until end of file, storing what was read in vec */
    while (cin_it != eof)
    {
        /* increment advances the stream to the next value, 
         * dereference reads next value from the istream.
         */
        vec.push_back(*cin_it++);
    }

    ofstream outfile;
    ostream_iterator<Sales_item> output(outfile, " ");
}

void access_manipulate_ostream_iterator_objects(void)
{
    /* write one string per line to the standard output */
    ostream_iterator<string> out_iter(cout, "\n");
    /* read strings from standard input and the end iterator */
    istream_iterator<string> in_iter(cin), eof;
    /* read until eof and write what was read to the standard output */
    while (in_iter != eof)
    {
        /* write value of in_iter to standard output,
         * and then increment the iterator to get the next value from cin 
         */
        *out_iter++ = *in_iter++;
    }

    istream_iterator<Sales_item> item_iter(cin), item_eof;
    Sales_item item;
}