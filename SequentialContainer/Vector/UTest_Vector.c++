/*!
 *  \file   UTest_Vector.c++
 *  \brief  Make the unit test for Vector<T> container.
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Vector.hpp"

#include <vector>
#include <iostream>

TEST(UTest4StdVector, CheckStdVectorObject)
{
    std::vector<unsigned> vec;
    std::cout << "The initial std::vector has " << vec.size() << " item in size." << std::endl;
    std::cout << "The initial std::vector's capacity is " << vec.capacity() << std::endl;

    std::vector<unsigned> fibonacci(5);
    std::cout << "This fibonacci series has " << fibonacci.size() << " items." << std::endl;
    std::cout << "This fibonacci series capacity is " << fibonacci.capacity() << std::endl;
}

TEST(UTest4Vector, CheckVectorInstance)
{
    Vector<unsigned> vec(4);
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec.capacity(), 4 + 16);
}

TEST(UTest4Vector, CheckBackELement)
{
    // GTEST_SKIP();
    Vector<unsigned> fibonacci;
    fibonacci.push_back(1);
    fibonacci.push_back(1);
    std::cout << "fibonacci[0] = " << fibonacci[0] << std::endl;
    std::cout << "fibonacci[0] = " << fibonacci[1] << std::endl;
    for (auto index = 2; index < 50; ++index)
    {
        fibonacci.push_back(fibonacci[index-1] + fibonacci[index-2]);
        std::cout << "fibonacci[" << index << "] = " << fibonacci[index] << std::endl;
    }
    EXPECT_EQ(fibonacci.size(), 50);
}

TEST(UTest4StdVector, CheckBackElement)
{
    std::vector<unsigned> fibonacci(20);
    EXPECT_EQ(fibonacci.size(), 20);

    fibonacci.push_back(1);
    EXPECT_EQ(fibonacci[0], 0);
    EXPECT_EQ(fibonacci[20], 1);
    EXPECT_EQ(fibonacci.size(), 21);

    fibonacci.push_back(1);
    EXPECT_EQ(fibonacci.size(), 22);

    fibonacci[0] = 1;
    fibonacci[1] = 1;
    fibonacci[2] = 2;
    fibonacci[3] = 3;
    fibonacci[4] = 5;
    fibonacci[5] = 8;
    EXPECT_EQ(fibonacci.size(), 22);
    EXPECT_EQ(fibonacci[0], 1);
}
