'''
Descroption: 面试题 10.03. 搜索旋转数组
Author: EmoryHuang
Date: 2021-07-11 15:17:04
解题思路:
二分搜索，由于是旋转的数组，因此还需要判断 mid 的位置
'''


class Solution:
    def search(self, arr: List[int], target: int) -> int:
        if not arr:
            return -1
        l, r = 0, len(arr) - 1
        while l <= r:
            if arr[l] == target:
                return l
            mid = (l + r) // 2
            if arr[mid] == target:
                r = mid
            elif arr[l] < arr[mid]:  # target落在左半边
                if arr[l] <= target < arr[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            elif arr[l] > arr[mid]:  # target落在右半边
                if arr[mid] < target <= arr[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                l += 1
        return -1
