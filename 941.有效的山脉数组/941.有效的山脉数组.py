'''
Descroption: LeetCode 941. 有效的山脉数组
Author: EmoryHuang
Date: 2021-06-04 13:51:00
解题思路:
分别从左到右，从右到左进行遍历，找到山顶
'''


class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        l, r = 0, len(arr)-1
        while l < r and arr[l] < arr[l+1]:
            l += 1
        while l < r and arr[r] < arr[r-1]:
            r -= 1
        return l == r and l != 0 and r != len(arr)-1
