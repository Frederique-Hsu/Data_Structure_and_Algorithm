#include "String.h"

#include <string>
using std::string;
using std::getline;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cctype>
using std::ispunct;

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

void manipulate_string_object(void)
{
    string st("The expense of spirit\n");
    cout << "The size of " << st << "is " << st.size()
        << " characters, including the newline escaping." << endl;

    string big = "big", small = "small";
    string s1 = big;
    if (big == small)
        cout << "\"" << big << "\" == \"" << small << "\"" << endl;
    if (big <= s1)
        cout << "\"" << big << "\" <= \"" << s1 << "\"" << endl;
}

void concatenate_string_objects(void)
{
    string s1 = "hello";    /* no punctuation */
    string s2 = "world";
    string s3 = s1 + ", ";          /* ok : adding a string and a literal */
    // string s4 = "hello" + ", ";     /* error : no string operand */
    string s5 = (s1 + ", ") + "world!";    /* ok : each + has string operand */
    // string s6 = "hello" + ", " + s2;    /* error : cannot add string literals */

    for (string::size_type index = 0; index != s5.size(); ++index)
    {
        cout << s5[index] << endl;
    }

    string::size_type punct_cnt = 0;
    /* count number of punctuation characters in s5 */
    for (string::size_type index = 0; index != s5.size(); ++index)
    {
        if (ispunct(s5[index]))
        {
            ++punct_cnt;
        }
    }
    cout << punct_cnt << " punctuation characters in " << s5 << endl;
}