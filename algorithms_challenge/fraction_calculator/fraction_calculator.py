# File name     : fraction_calculator.py
# Description   : Demonstrate how to carry out the Python unit test
#
#


class Fraction:
    def __init__(self, numerator, denominator):
        if denominator == 0:
            raise ValueError("Denominator cannot be zero")
        self.numerator = numerator
        self.denominator = denominator

    