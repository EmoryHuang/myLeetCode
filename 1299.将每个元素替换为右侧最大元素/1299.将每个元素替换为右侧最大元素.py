'''
Descroption: LeetCode 1299. 将每个元素替换为右侧最大元素
Author: EmoryHuang
Date: 2021-07-23 20:07:07
解题思路:
从后往前遍历数组，维护最大值
'''


class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        amax = -1
        for i in range(len(arr) - 1, -1, -1):
            amax, arr[i] = max(amax, arr[i]), amax
        return arr
