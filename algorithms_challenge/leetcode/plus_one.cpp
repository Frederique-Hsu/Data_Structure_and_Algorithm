/*!
 *  \file       plus_one.cpp
 *  \brief      
 *  
 */


#include <vector>
#include <gtest/gtest.h>
#include <initializer_list>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int> result = digits;
        reverse(result.begin(), result.end());

        vector<int>::iterator iter;
        int number = 0;
        for (iter = result.begin(); iter != result.end(); ++iter)
        {
            number = *iter + 1;
            if (number < 10)
            {
                *iter += 1;
                break;
            }

            *iter = number % 10;
        }
        if (number >= 10)
        {
            result.push_back(1);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


TEST(UTest, CheckPlusOne)
{
    vector<int> numbers{1, 2, 3, 4};
    vector<int> result = Solution().plusOne(numbers);
    EXPECT_EQ(result[3], 5);

    numbers = {1, 3, 5, 7, 9};
    result = Solution().plusOne(numbers);

    numbers = {9, 9, 9, 9};
    result = Solution().plusOne(numbers);
}