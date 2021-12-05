/*!
 *  \file   Lvalue_Rvalue_reference.c++
 *  \brief  Study how the Lvalue and Rvalue works, and their difference.
 *  \author Frederique Hsu
 *  \date   Sun.    05 Dec. 2021
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(UTest4LvalueRvalueReference, CheckDiffBetweenLvalueAndRvalue)
{
    std::string str = "hell";
    std::string& left_str = str;    /* left_str is the synonym of str */
    left_str += 'o';
    ASSERT_THAT(str, "hello");
    ASSERT_THAT(left_str, "hello");

    bool cond = (&str == &left_str);
    ASSERT_TRUE(cond == true);

    // std::string& bad1 = "hello";    /* illegal: "hello" is not a modifiable Lvalue */
    // std::string& bad2 = str + "!";  /* illegal: str + "!" is not an Lvalue */
    // std::string& sub = str.substr(0, 4);    /* illegal: str.substr(0, 4) is not an Lvalue */

    std::string&& bad1 = "hello";    /* Legal: because literal "hello" is Rvalue */
    std::string&& bad2 = str + "!";     /* Legal: temporary variable str + "!" can be Rvalue */
    std::string&& sub = str.substr(0, 4);   /* Legal: same as above */
    ASSERT_THAT(bad1, "hello");
    ASSERT_THAT(bad2, "hello!");
    ASSERT_THAT(sub, "hell");
}

/*!
 *  \note   Lvalue references use #1: aliasing complicated names
 *
 *  \note   Lvalue references use #2: range for loops
 *
 *  \note   Lvalue references use #3: avoiding a copy
 */

TEST(UTest4LvalueRvalueReference, LvalueRefAppliedOnRangeForLoops)
{
    std::vector<int> fibonacci {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

    for (auto elem : fibonacci)     /* elem assumes a copy of each value in the vector */
    {
        ++elem;
    }
    ASSERT_TRUE(fibonacci[0] == 1);
    ASSERT_TRUE(fibonacci[fibonacci.size()-1] == 55);

    for (auto& elem : fibonacci)    /* here elem is the reference of each value in the vector */
    {
        ++elem;
    }
    ASSERT_TRUE(fibonacci[0] == 2);
    ASSERT_TRUE(fibonacci[fibonacci.size() - 1] == 56);
}
