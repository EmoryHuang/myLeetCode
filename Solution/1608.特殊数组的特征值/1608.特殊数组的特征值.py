'''
Descroption: LeetCode 1608. 特殊数组的特征值
Author: EmoryHuang
Date: 2021-06-24 15:50:00
解题思路:
排序，然后寻找 x，满足前一个数小于 x 后一个数大于等于 x
'''


class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if nums[0] >= n:
            return len(nums)  # n 个数大于等于 n
        for i in range(1, n + 1):
            # i 个数大于等于 i
            if nums[n - i] >= i and nums[n - i - 1] < i:
                return i
        return - 1
