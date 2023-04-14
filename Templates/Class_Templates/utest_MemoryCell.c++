/*!
 *  \file   utest_MemoryCell.c++
 *  \brief  Make the unit test for the class template MemoryCell<ObjectType>
 *  \author Frederique Hsu
 *  \date   Tue.    14 Dec. 2021
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "MemoryCell.hpp"

TEST(UTest4MemoryCell, Validate_CreateMemoryCellObject)
{
    MemoryCell<int> intcell;
    MemoryCell<std::string> strcell{"hello"};

    intcell.write(38);

    ASSERT_TRUE(strcell.read() == "hello");
    strcell.write(strcell.read() + "world");

    ASSERT_TRUE(intcell.read() == 38);
    ASSERT_TRUE(strcell.read() == std::string{"helloworld"});
}
