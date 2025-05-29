/*!
 *  \file       palindrome_number
 *  \brief      
 *  
 */



#include <vector>
#include <string>
#include <bits/basic_string.h>


#include <gtest/gtest.h>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string digits = std::to_string(x);

        int len = digits.length();
        std::vector<char> left_half, right_half;
        if (len % 2 == 0)
        {
            for (int index = 0; index < len/2; ++index)
            {
                left_half.push_back(digits[index]);
            }
            for (int index = len -1; index >= len/2; --index)
            {
                right_half.push_back(digits[index]);
            }
        }
        else if (len % 2 != 0)
        {
            for (int index = 0; index < len/2; ++index)
            {
                left_half.push_back(digits[index]);
            }
            for (int index = len - 1; index >= len/2 + 1; --index)
            {
                right_half.push_back(digits[index]);
            }
        }
        return isEqual(left_half, right_half);
    }
private:
    bool isEqual(const std::vector<char>& a, const std::vector<char>& b)
    {
        auto len = a.size();
        if (len != b.size())
        {
            return false;
        }
        else
        {
            for (auto index = 0U; index < len; ++index)
            {
                if (a[index] != b[index])
                {
                    return false;
                }
            }
            return true;
        }
    }
};


TEST(UTest, CheckIsPalindrome)
{
    int x = 121;
    EXPECT_EQ(Solution().isPalindrome(x), true);
}