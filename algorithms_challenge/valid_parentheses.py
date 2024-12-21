# File name     : valid_parentheses.py
# Description   : 
#
#


class Solution:
    @staticmethod
    def isValid(s : str) -> bool:
        parentheses_stack : list[str] = []

        for index in range(0, len(s)):
            if s[index] in ['(', ')', '[', ']', '{', '}']:
                if len(parentheses_stack) == 0:
                    parentheses_stack.append(s[index])
                else:
                    top_char = parentheses_stack[-1]
                    if ((top_char == '(' and s[index] == ')') or 
                        (top_char == '[' and s[index] == ']') or
                        (top_char == '{' and s[index] == '}')):
                        parentheses_stack.pop()
                    else:
                        parentheses_stack.append(s[index])
        
        return len(parentheses_stack) == 0
    
#===============================================================================

import unittest

class TestSolutionIsValid(unittest.TestCase):
    def test_isValid(self):
        self.assertEqual(Solution.isValid("()"), True)
        self.assertEqual(Solution.isValid("([{}])"), True)
        self.assertEqual(Solution.isValid("([{)"), False)


if __name__ == "__main__":
    unittest.main()