'''
Descroption: LeetCode 1920. 基于排列构建数组
Author: EmoryHuang
Date: 2021-11-05 20:20:30
Method:
简单题
'''


class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        return [nums[num] for num in nums]