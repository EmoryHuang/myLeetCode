'''
Descroption: LeetCode 1403. 非递增顺序的最小子序列
Author: EmoryHuang
Date: 2021-06-05 14:55:00
解题思路:
贪心思想，首先将 nums 进行排序
然后从大到小选择元素，若该子序列中的元素之和大于剩余元素，则找到
'''


class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        sub = []
        for num in sorted(nums, reverse=True):
            sub.append(num)
            if(sum(sub) > sum(nums) - sum(sub)):
                return sub
