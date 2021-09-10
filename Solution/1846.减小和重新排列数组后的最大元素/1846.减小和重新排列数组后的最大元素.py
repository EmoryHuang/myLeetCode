'''
Descroption: LeetCode 1846. 减小和重新排列数组后的最大元素
Author: EmoryHuang
Date: 2021-07-15 18:47:11
解题思路:
排序后遍历数组，第一项为 1
若arr[i]与arr[i - 1]之差大于 1，则令arr[i] = arr[i - 1] + 1
'''


class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        arr[0] = 1
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] > 1:
                arr[i] = arr[i - 1] + 1
        return arr[len(arr) - 1]
