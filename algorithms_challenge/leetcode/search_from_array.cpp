// C++ implementation below
#include <iostream>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h>
#include <algorithm>
#include <vector>
#include <initializer_list>

#include <gtest/gtest.h>

using namespace std;

class Answer
{
public:
    static bool exists(int ints[], int size, int k)
    {
        int low_index = 0, high_index = size-1;
        while (low_index <= high_index)
        {
            int mid_index = (low_index + high_index) / 2;
            if (k == ints[mid_index])
            {
                return true;
            }
            else if (k < ints[mid_index])
            {
                high_index = mid_index - 1;
            }
            else
            {
                low_index = mid_index + 1;
            }
        }
        return false;
    }
};

TEST(UTest, CheckExists)
{
    int ints[] = { -9, -5, 0, 10, 14, 37, 102, 125, 167, 180 };
    EXPECT_EQ(Answer::exists(ints, sizeof(ints)/sizeof(ints[0]), 37), true);
    EXPECT_EQ(Answer::exists(ints, sizeof(ints)/sizeof(ints[0]), 180), true);
}

int find_max(int a, int b, int c)
{
    int max_value = std::max(std::initializer_list<int>{a, b, c});
    return max_value;
}