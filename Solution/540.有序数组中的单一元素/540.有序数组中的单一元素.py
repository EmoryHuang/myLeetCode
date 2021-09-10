'''
Descroption: LeetCode 540. 有序数组中的单一元素
Author: EmoryHuang
Date: 2021-07-30 14:34:29
Method:
二分搜索
单一元素只会出现在偶数下标位置
'''


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if mid % 2 == 1:
                mid -= 1
            if nums[mid] != nums[mid + 1]:
                r = mid
            else:
                l = mid + 2
        return nums[l]