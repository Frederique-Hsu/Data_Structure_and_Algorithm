/*!
 *  \file   UTest_List.c++
 *  \brief  Make the unit test for List<T> container
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "List.hpp"

class UTest4List : public ::testing::Test
{
public:
    List<unsigned> lst;
};

TEST_F(UTest4List, CheckListInstance)
{

}
