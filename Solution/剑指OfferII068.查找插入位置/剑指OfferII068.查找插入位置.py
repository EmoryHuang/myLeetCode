'''
Descroption: 剑指 Offer II 068. 查找插入位置
Author: EmoryHuang
Date: 2021-08-06 18:32:18
Method:
二分法寻找左端点
'''


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + r >> 1
            # 二分法寻找左端点
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l if nums[l] >= target else len(nums)
