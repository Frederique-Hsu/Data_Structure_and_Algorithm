/*!
 *  \file   UTest_List.c++
 *  \brief  Make the unit test for List<T> container
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "List.hpp"

class ListUTestFixture : public ::testing::Test
{
public:
    List<unsigned> lst;
};

TEST_F(ListUTestFixture, CheckListMethods)
{
    lst.push_back(1);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(8);

    EXPECT_EQ(lst.back(), 8);
    EXPECT_EQ(lst.size(), 6);
    EXPECT_EQ(lst.front(), 1);

    for (List<unsigned>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
    {
        std::cout << *itr << std::endl;
    }

    lst.erase(lst.begin() + 1, lst.end() - 2);
    EXPECT_EQ(lst.size(), 3);
}

