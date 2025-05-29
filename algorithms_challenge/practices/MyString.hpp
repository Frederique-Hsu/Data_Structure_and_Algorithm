/*!
 *  \file       MyString.hpp
 *  \brief      
 *  
 */


#pragma once

#include <iostream>

class MyString
{
    friend std::ostream& operator<<(std::ostream& os, const MyString& mystr);
public:
    MyString(const char* str);
    MyString(const MyString& rhs);
    MyString& operator=(const MyString& rhs);
    MyString(MyString&& rhs);
    MyString& operator=(MyString&& rhs);
    ~MyString();
private:
    char* m_str;
public:
    int length();
};