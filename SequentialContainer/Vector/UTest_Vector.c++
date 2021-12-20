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
}
