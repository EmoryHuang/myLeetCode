'''
Descroption: 剑指 Offer 53 - II. 0～n-1中缺失的数字
Author: EmoryHuang
Date: 2021-07-23 18:46:48
解题思路:
二分法寻找左端点
'''


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + r >> 1
            if nums[mid] == mid:
                # 缺失的数字在右半部分
                l = mid + 1
            else:
                # 缺失的数字在左半部分
                r = mid - 1
        return l
