#include "exercises.h"

#include <iostream>
using std::cout;
using std::endl;

void verifyExercises(void)
{
    string sentence("Hello, Alice Yu, I Love you so MUCH!");
    toUpper(sentence);
    cout << sentence << endl;

    string love = "You are so Beautiful that I have fallen in LOVE with you.";
    cout << love << endl;
    eraseUpperLettersFrom(love);
    cout << love << endl;

    vector<char> myName;
    myName.push_back('F');
    myName.push_back('r');
    myName.push_back('e');
    myName.push_back('d');
    myName.push_back('e');
    myName.push_back('r');
    myName.push_back('i');
    myName.push_back('c');
    myName.push_back('k');
    myName.push_back(' ');
    myName.push_back('H');
    myName.push_back('s');
    myName.push_back('u');
    string name = instantiateStringObjectFromVector(myName);
    cout << "My name is " << name << endl;
}

void toUpper(string& origin)
{
    for (string::iterator iter = origin.begin(); iter != origin.end(); ++iter)
    {
        if (('a' <= *iter) && (*iter <= 'z'))
        {
            *iter -= 32;
        }
    }
}

void eraseUpperLettersFrom(string& origin)
{
    string::iterator iter = origin.begin();
    while (iter != origin.end())
    {
        if (('A' <= *iter) && (*iter <= 'Z'))
        {
            origin.erase(iter);
            if (iter == origin.begin())
            {
            }
            else
            {
                --iter;
            }
        }
        ++iter;
    } 
}

string instantiateStringObjectFromVector(const vector<char>& charvec)
{
    string str;
    for (vector<char>::const_iterator citer = charvec.begin(); citer != charvec.end(); ++citer)
    {
        str.push_back(*citer);
    }
    return str;
}