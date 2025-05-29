/*!
 *  \file       MyString.cpp
 *  \brief      
 *  
 */


#include "MyString.hpp"

#include <cstring>
#include <cstdlib>
#include <stdexcept>

MyString::MyString(const char* str) : m_str{nullptr}
{
    std::size_t len = std::strlen(str);

    m_str = (char*)calloc(len + 1, sizeof(char));
    if (m_str == nullptr)
    {
        throw std::bad_alloc();
    }
    std::memcpy(m_str, str, sizeof(char) * len);
    m_str[len] = '\0';
}

MyString::~MyString()
{
    if (m_str != nullptr)
    {
        free(m_str);
    }
}

int MyString::length()
{
    return std::strlen(m_str);
}

MyString::MyString(const MyString& rhs)
{
    int len = std::strlen(rhs.m_str);

    m_str = (char*)calloc(len + 1, sizeof(char));
    if (m_str == nullptr)
    {
        throw std::bad_alloc();
    }
    std::memcpy(m_str, rhs.m_str, len);
    m_str[len] = '\0';
}

MyString& MyString::operator=(const MyString& rhs)
{
    if (this != &rhs)
    {
        if (m_str != nullptr)
        {
            free(m_str);
        }
        int len = std::strlen(rhs.m_str);

        m_str = (char*)calloc(len + 1, sizeof(char));
        if (m_str == nullptr)
        {
            throw std::bad_alloc();
        }
        std::memcpy(m_str, rhs.m_str, len);
        m_str[len] = '\0';
    }
    return *this;
}

MyString::MyString(MyString&& rhs)
{
    m_str = rhs.m_str;

    rhs.m_str = nullptr;
}

MyString& MyString::operator=(MyString&& rhs)
{
    if (this != &rhs)
    {
        if (m_str != nullptr)
        {
            free(m_str);
        }
        m_str = rhs.m_str;
        rhs.m_str = nullptr;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& mystr)
{
    if (mystr.m_str != nullptr)
    {
        os << mystr.m_str;
    }
    else
    {
        os << "";
    }

    return os;
}