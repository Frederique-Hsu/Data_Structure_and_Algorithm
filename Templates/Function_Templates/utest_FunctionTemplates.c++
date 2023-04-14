/*!
 *  \file   utest_FunctionTemplates.c++
 *  \brief  Make the unit test for the function templates.
 *
 */

#include "Function_Templates.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

TEST(UTest4FnctTemplates, ValidateFindMax)
{
    std::vector<int> nums {5, 9, -12, 85, 120, 65, -20, 560, 48, 75};

    int maximum = findMax(nums);

    std::sort(nums.begin(), nums.end());
    ASSERT_TRUE(maximum == nums[nums.size()-1]);
    ASSERT_TRUE(maximum == *(nums.end()-1));
#if defined (DEBUG)
    std::cout << "The max element is " << maximum << std::endl;
#endif

    maximum = -45;
    maximum = findMax(nums);
    ASSERT_TRUE(maximum == 560);
}
