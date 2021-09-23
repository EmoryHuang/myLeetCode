'''
Descroption: LeetCode 1913. 两个数对之间的最大乘积差
Author: EmoryHuang
Date: 2021-09-23 19:09:19
Method:
简单题，排序之后取头尾4个元素
'''


class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return nums[-1] * nums[-2] - nums[0] * nums[1]