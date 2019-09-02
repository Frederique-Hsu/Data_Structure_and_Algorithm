#include "StringContainer.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

void execute_test_cases(void)
{
    // access_string_iterator();
    // modify_string_object();
    operations_on_string();
    compare_string_objects();
}

void access_string_iterator(void)
{
    string s("Hiya");
    string::iterator iter = s.begin();
    while (iter != s.end())
    {
        cout << *iter++ << endl;        /* postfix increment: print old value */
        // cout << *++iter << endl;     /* at this scenario, cannot use prefix */
    }

    const char* cp = "Hello";     /* null-terminated array */
    char c_array[] = "World!!!!";   /* null-terminated */
    char no_null[] = { 'H', 'i' };  /* no null-terminated */
    string s1(cp);
    cout << "s1 = " << s1 << endl;
    string s2(c_array, 5);
    cout << "s2 = " << s2 << endl;
    string s3(c_array + 5, 4);
    cout << "s3 = " << s3 << endl;
    // string s4(no_null);     /* runtime error: no_null has no null-terminated */
    // cout << "s4 = " << s4 << endl;
    string s5(no_null, 2);
    cout << "s5 = " << s5 << endl;
}

void modify_string_object(void)
{
    string motto = "Cease to struggle, and you cease to live.";
    string myMotto(motto.begin(), motto.end());

    motto.erase(motto.size() - 5, 5);       /* erase last five characters from motto */
    cout << "The motto is : " << motto << endl;

    myMotto.insert(myMotto.size(), 5, '!');     /* insert five exclamation points at the end of myMotto */
    cout << "My motto is : " << myMotto << endl;

    const char* cp = "Stately plump Buck";
    string str;
    str.assign(cp, 7);
    cout << "the str is : " << str << endl;
    str.insert(str.size(), cp + 7);
    cout << "the str become to : " << str << endl;

    string some = "some string";
    string other = "some other string";
    /* 3 equivalent ways to insert all the characters from other at the beginning of some */
    /* insert iterator range before some.begin() */
    // some.insert(some.begin(), other.begin(), other.end());
    
    /* insert copy of other before position 0 in some */
    // some.insert(0, other);

    /* insert other.size() characters from other starting at other[0] before some[0] */
    some.insert(0, other, 0, other.size());
    
    cout << "some = " << some << endl;
}

void operations_on_string(void)
{
    string str("Hello, world!");
    string substr1 = str.substr(6, 5);   /* return substring of 5 characters starting at position 6 */
    string substr2 = str.substr(6);     /* return substring from position 6 to the end of str */

    string s("C++ Primer");
    s.append(" 3rd Edition.");
    cout << "The string is : " << s << endl;
    // s.insert(s.size(), "3rd Ed.");      /* equivalent to s.append(" 3rd Ed.") */

    s.replace(11, 3, "4th");    /* starting at position 11, erase 3 characters and then insert "4th" */
    /* equivalent way to replace "3rd" by "4th" */
    // s.erase(11, 3);
    // s.insert(11, "4th");
    s.replace(11, 3, "Fourth");
    cout << "After replaced, the new string become to be : " << s << endl;

    string slogan = "Life can only be understood backwards; but it must be lived forwards.";
    string::size_type pos = slogan.find("backwards");
    pos = slogan.find("But");
    if (pos == string::npos)
    {
        cout << "The word you want to search had not yet been found. Sorry!" << endl;
    }
    pos = slogan.find_first_of("be");
    if (pos != string::npos)
    {
        cout << "found position at index " << pos << ", and the element is : " << slogan[pos] << endl;
    }

    pos = 0;
    /* each trip reset pos to the next instance in slogan */
    while ((pos = slogan.find_first_of("it", pos)) != string::npos)
    {
        cout << "found word at index: " << pos << ", element is: " << slogan[pos] << endl;
        ++pos;      /* move to the next character */
    }
    
    
    string digits("1234567890");
    string session_number = "60735se842";
    string::size_type position = session_number.find_first_not_of(digits);

    string river("Mississippi");
    string::size_type first_pos = river.find("si");
    string::size_type last_pos = river.rfind("si");
    cout << "The first_pos = " << first_pos << ", last_pos = " << last_pos << endl;
}

void compare_string_objects(void)
{
    string cobol_program_crash("abend");
    string cplus_program_crash("abort");
    int result = cobol_program_crash.compare(cplus_program_crash);
    result = cplus_program_crash.compare(cobol_program_crash);

    const char* first_ed = "C++ Primer, 1st Edition";
    char second_ed[] = "C++ Primer, 2nd Edition";
    string third_ed("C++ Primer, 3rd Edition");
    string fourth_ed = "C++ Primer, 4th Edition";
    /* compares C++ library string to C-style string */
    result = fourth_ed.compare(second_ed);      /* OK, second_ed is null-terminated */
    /* compares substrings of fourth_ed and third_ed */
    result = fourth_ed.compare(fourth_ed.find("4th"), 3, third_ed, third_ed.find("3rd"), 3);
}