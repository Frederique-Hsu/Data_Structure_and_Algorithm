#include "String.h"

#include <string>
using std::string;
using std::getline;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void access_string_object(void)
{
    string s;   /* empty string */
    cin >> s;   /* read whitespace-separated string into s */
    cout << s << endl;
}

void read_multi_string_objects(void)
{
    string word;
    /* read until end-of-file, writing each word to a new line */
    while (cin >> word)
    {
        /* Julie Chen, mobile : 18516113780 */
        cout << word << endl;
    }
}

void read_text_one_line(void)
{
    string line;
    /* read text line at one time until end-of-file */
    while (getline(cin, line))
    {
        cout << line << endl;
    }
}