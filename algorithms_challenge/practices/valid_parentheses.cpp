/*!
 *  \file       valid_parentheses.cpp
 *  \brief      
 *  
 */

#include <stack>
#include <string>

using namespace std;

/*!
 *  \brief      20. Valid Parentheses
 *
 *  \details    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 *              An input string is valid if:
 *
 *              Open brackets must be closed by the same type of brackets.
 *              Open brackets must be closed in the correct order.
 *              Every close bracket has a corresponding open bracket of the same type.
 */

class Solution 
{
public:
    bool isValid(string s) 
    {
        std::stack<char> parentheses_stack;

        for (auto letter : s)
        {
            switch (letter)
            {
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
                if (parentheses_stack.empty())
                {
                    parentheses_stack.push(letter);
                }
                else
                {
                    char top_char = parentheses_stack.top();
                    if ((top_char == '(' && letter == ')') || 
                        (top_char == '[' && letter == ']') || 
                        (top_char == '{' && letter == '}'))
                    {
                        parentheses_stack.pop();
                    }
                    else
                    {
                        parentheses_stack.push(letter);
                    }
                }
                break;
            default:
                break;
            }
        }

        return (parentheses_stack.empty() == true);
    }
};


#include <gtest/gtest.h>

TEST(UTest4ValidParentheses, CheckWhetherSolutionIsCorrect)
{
    Solution solution;

    bool answer = solution.isValid("()");
    EXPECT_EQ(answer, true);

    EXPECT_EQ(solution.isValid("()[]{}"), true);
    EXPECT_EQ(solution.isValid("(])"), false);
    EXPECT_EQ(solution.isValid("([])"), true);
    EXPECT_EQ(solution.isValid("({[)"), false);
}