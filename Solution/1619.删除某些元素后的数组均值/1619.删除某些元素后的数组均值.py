'''
Descroption: LeetCode 1619. 删除某些元素后的数组均值
Author: EmoryHuang
Date: 2022-09-14 09:12:23
Method:
简单题，排序后直接截取
'''


class Solution:
    def trimMean(self, arr: List[int]) -> float:
        n = len(arr)
        arr.sort()
        return sum(arr[int(0.05 * n):int(0.95 * n)]) / (n - 0.1 * n)
