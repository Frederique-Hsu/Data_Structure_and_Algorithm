/*!
 *  \file   utest_IntCell.c++
 *  \brief  Make the unit tests for IntCell class.
 *  \author Frederique Hsu
 *  \date   Sun.    05 Dec. 2021
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IntCell.hpp"

TEST(UTest4IntCell, InstantiateObjects)
{
    IntCell obj = IntCell(37);
    ASSERT_TRUE(obj.read() == 37);

    obj.write(1816);
    ASSERT_TRUE(obj.read() == 1816);
}

void swap(unsigned int& a, unsigned int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


