'''
Descroption: LeetCode 724. 寻找数组的中心下标
Author: EmoryHuang
Date: 2021-06-16 14:25:00
解题思路:
简单题，遍历数组，若去除当前元素后前半部分和为数组元素的一半则返回下标
'''


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        cur, s = 0, sum(nums)
        for i, num in enumerate(nums):
            if 2 * cur + num == s:
                return i
            cur += num
        return -1