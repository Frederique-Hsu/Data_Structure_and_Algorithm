#include "exercises.h"

#include <iostream>
using std::cout;
using std::endl;

void verifyExercises(void)
{
    string sentence("Hello, Alice Yu, I Love you so MUCH!");
    toUpper(sentence);
    cout << sentence << endl;

    string love = "YOU are So BeauTiFUL that I have fallen in LOVE with you.";
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

    string generic1("Dear Ms Daisy:");
    string generic2("MrsMsMissPeople");
    string lastName("Swift");
    string salute = greet(generic1, lastName, generic2, 5, 4);
    cout << salute << endl;     /* print out : Dear Miss Swift */
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
#if 1
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
#else
    for (string::size_type index = 0; index < origin.size(); ++index)
    {
        if (('A' <= origin[index]) && (origin[index] <= 'Z'))
        {
            origin.erase(index, 1);
            index--;
        }
    }
#endif
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

string greet(string from, string lastname, string title, string::size_type pos, int length)
{
    string::size_type pos_Daisy = from.find("Daisy");
    string::size_type colonPosition = from.find(":");
    from.replace(pos_Daisy, colonPosition - pos_Daisy, lastname);

    string miss = title.substr(pos, length);
    from.replace(from.find("Ms"), 2, miss);
    return from;
}