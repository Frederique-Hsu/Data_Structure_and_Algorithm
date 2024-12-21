#include <vector>
#include <string>
#include <iostream>

#include <gtest/gtest.h>

class Solution
{
public:
    int digitToNumber(char digit)
    {
        switch (digit)
        {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default:  return 0;
        }
    }

    int summary(const std::vector<int>& numbers)
    {
        int sum = 0;
        for (int number : numbers)
        {
            sum += number;
        }
        return sum;
    }

    int computeFollowedNumber(int num)
    {
        std::string digits = std::to_string(num);
        std::vector<int> numbers;
        for (char digit : digits)
        {
            numbers.push_back(digitToNumber(digit));
        }
        return num + summary(numbers);
    }

    int computeSameJoint(int s1, int s2)
    {
        int followedNumber1 = computeFollowedNumber(s1);
        int followedNumber2 = computeFollowedNumber(s2);
        std::cout << "s1 = " << s1 << ", s2 = " << s2 << ", ";

        while (followedNumber1 != followedNumber2)
        {
            std::cout << "followedNumber1 = " << followedNumber1 << ", followedNumber2 = " << followedNumber2 << std::endl;
            followedNumber1 = computeFollowedNumber(followedNumber1);
            followedNumber2 = computeFollowedNumber(followedNumber2);
        }
        return followedNumber1;
    }
};

TEST(UTest, CheckSameJoint)
{
    GTEST_SKIP();
    int s1 = 54, s2 = 41;
    int jointNumber = Solution().computeSameJoint(s1, s2);

    std::cout << "s1 = " << s1 << ", s2 = " << s2 << ", same_joint_number = " << jointNumber << std::endl;
}