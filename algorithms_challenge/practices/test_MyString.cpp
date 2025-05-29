/*!
 *  \file       test_MyString.cpp
 *  \brief      
 *  
 */


#include <gtest/gtest.h>

#include "MyString.hpp"


void testMyString()
{
    /*********************************************************TEST1*****************************************************************/
    MyString str1("1");
    std::cout << "str1 : " << str1 << std::endl;

    MyString str2 = str1;
    MyString str3(str2);
    std::cout << "str2 : " << str2 << std::endl;
    std::cout << "str3 : " << str3 << std::endl;
    /*********************************************************TEST1*****************************************************************/

    /*********************************************************TEST2*****************************************************************/
    str2 = "2";
    str3 = "3";
    MyString str4 = std::move(str2);
    MyString str5(std::move(str3));

    std::cout << "str2 : " << str2 << std::endl;
    std::cout << "str3 : " << str3 << std::endl;
    std::cout << "str4 : " << str4 << std::endl;
    std::cout << "str5 : " << str5 << std::endl;
    /*********************************************************TEST2*****************************************************************/
}


TEST(UTester4MyString, CheckFunction_testMyString)
{
    testMyString();
}