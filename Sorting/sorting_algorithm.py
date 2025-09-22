# File          : sorting_algorithm.py
# Description   : Implement the sorting algorithms in Python
# 
#
#


def select_sort(nums : list[int]):
    n = len(nums)

    for i in range(n-1):
        min_elem_index = i
        for j in range(i+1, n):
            if nums[j] < nums[min_elem_index]:
                min_elem_index = j
        nums[i], nums[min_elem_index] = nums[min_elem_index], nums[i]



if __name__ == "__main__":
    import unittest