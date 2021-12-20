/*!
 *  \file   utest_Functor.c++
 *  \brief  Make the unit test case to verify whether the user-defined functor can work well.
 *
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "CaseInsensitiveCompare.hpp"
#include "../Function_Templates/Function_Templates.hpp"

TEST(UTest4Functor, Check_findMax_with_Functor)
{
    std::vector<std::string> arr = {"ZEBRA", "alligator", "crocodile"};
    std::cout << findMax(arr, CaseInsensitiveCompare{}) << std::endl;
    ASSERT_THAT(findMax(arr, CaseInsensitiveCompare{}), std::string{"ZEBRA"});

    std::cout << findMaximum<std::string, Compare>(arr, Compare()) << std::endl;
}
