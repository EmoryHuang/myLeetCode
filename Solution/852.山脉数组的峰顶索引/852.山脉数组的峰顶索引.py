'''
Descroption: LeetCode 852. 山脉数组的峰顶索引
Author: EmoryHuang
Date: 2021-06-15 16:12:00
解题思路:
简单题，枚举的方法就不写了，写了一下二分
若 arr[mid] >= arr[mid + 1] 就说明 mid 在右半部分
按照二分查找模板即可
'''


class Solution:
    # 二分查找
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr)-1
        while l < r:
            mid = l + (r - l) // 2
            if arr[mid] >= arr[mid + 1]:
                r = mid
            else:
                l = mid + 1
        return l
