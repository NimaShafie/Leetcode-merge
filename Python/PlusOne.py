# https://leetcode.com/problems/plus-one/
# 66. Plus One

# first python leetcode problem to solve here
# still learning the language

# importing neccessary files for List feature
from typing import List

class Solution:

    # use keyword def to define a function, python typically uses snake_case
    # digits: List[int] means that digits is expected to be a list of integers
    # -> List[int] is the return type for this function (this is a type hint, or function annotation)
    def plus_one(self, digits: List[int]) -> List[int]:
        print("Test")
        return digits

print("Main start")
input_string = input()
user_list = input_string.split()
print("Now printing list ", user_list)

sol = Solution().plus_one(user_list)