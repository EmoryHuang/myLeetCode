'''
Descroption: 剑指 Offer II 069. 山峰数组的顶部
Author: EmoryHuang
Date: 2021-08-06 18:27:47
Method:
二分法寻找左端点
'''


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr) - 1
        while l < r:
            mid = l + r >> 1
            # 二分法寻找左端点
            if arr[mid] >= arr[mid + 1]:
                r = mid
            else:
                l = mid + 1
        return l
