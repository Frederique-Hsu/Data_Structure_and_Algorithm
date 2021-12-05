/*!
 *  \file   utest_Vector_String.c++
 *  \brief  Review the std::vector and std::string STL.
 *  \author Frederique Hsu
 *  \date   Sun.    05 Dec. 2021
 * 
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>
#include <string>

TEST(UTest4VectorAndString, UniformInitialize)
{
    /* uniform initialization */
    std::vector<int> daysInMoth { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ASSERT_TRUE(daysInMoth.size() == 12);

    std::vector<int> months {12};
    ASSERT_TRUE(months.size() == 1);
    ASSERT_TRUE(months[0] == 12);

    std::vector<int> days(12);
    ASSERT_TRUE(days.size() == 12);
}

TEST(UTest4VectorAndString, CheckRangeForLoop)
{
    std::vector<int> squares(100);
    for (size_t index = 0; index < squares.size(); ++index)
    {
        squares[index] = index * index;
    }

    int sum = 0;
    /* key word "auto" signify that the compiler will automatically infer 
     * the appropriate type.
     */
    for (auto elem : squares)   
    {
        sum += elem;
    }
    /*!
     *  \warning The range for loop is appropriate only if every item is being accessed \n 
     *           sequentially and only if the index is not needed. 
     */
}