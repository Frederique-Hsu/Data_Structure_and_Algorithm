#include "pair_type.h"

#include <utility>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void create_and_initialize_pair_objects(void)
{
    pair<string, string> anon;     /* holds two strings */
    pair<string, int> word_count;   /* holds a string and an int */
    pair< string, vector<int> > line;   /* holds string and vector<int> */

    pair<string, string> author("James", "Joyce");

    typedef pair<string, string> Author;
    Author proust("Marcel", "Proust");

    string firstBook;
    /* access and test the data members of the pair */
    if ((author.first == "James") && (author.second == "Joyce"))
    {
        firstBook = "Stephen Hero";
    }

    Author next_auth;
    string first, last;
    cin >> first >> last;
    next_auth = make_pair(first, last);     /* generate a pair from first and last */
    Author me = pair<string, string>("Frederique", "Hsu");
}

void store_pair_objects(void)
{
    typedef pair<string, int> Data;
    string field;
    int value;

    vector<Data> data_tanker;
    while (cin >> field >> value)
    {
        Data dt(field, value);
        if (data_tanker.size() > 10)
        {
            break;
        }
        else
        {
            data_tanker.push_back(dt);
        }
    }

    cout << "The data tanker contains the below elements: " << endl;
    for (vector<Data>::iterator iter = data_tanker.begin(); iter != data_tanker.end(); ++iter)
    {
        cout << "field = " << iter->first << ", value = " << iter->second << endl;
    }
}