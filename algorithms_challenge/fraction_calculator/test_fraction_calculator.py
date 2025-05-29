# File name     : test_fraction_calculator.py
# Description   : 
#
#


import unittest
from fraction_calculator import Fraction

class TestFraction(unittest.TestCase):
    def test_create_fraction(self):
        f = Fraction(1, 2)
        self.assertEqual(f.numerator, 1)
        self.assertEqual(f.denominator, 2)
    
    def test_create_fraction_with_zero_denominator(self):
        with self.assertRaises(ValueError):
            Fraction(1, 0)


if __name__ == "__main__":
    unittest.main()