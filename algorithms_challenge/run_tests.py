# File name     : run_tests.py
# Description   : With this script to automatically discover and run all unit test cases, 
#                 which are distributed in many .py files.
#
#
#


import unittest

start_dir = "./"
pattern = None
top_level_dir = None

suite = unittest.defaultTestLoader.discover(start_dir=start_dir, pattern="*.py")
runner = unittest.TextTestRunner()
runner.run(suite)