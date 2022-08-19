'''
Descroption: LeetCode 334. 递增的三元子序列
Author: EmoryHuang
Date: 2021-07-27 19:24:08
Method:
最长递增子序列问题
维护最小值和中间值，若找到比中间值更大的元素，则找到了三元子序列
'''


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        min, mid = float('inf'), float('inf')
        for num in nums:
            if min >= num:
                min = num
            elif num <= mid:
                mid = num
            else:
                return True
        return False
