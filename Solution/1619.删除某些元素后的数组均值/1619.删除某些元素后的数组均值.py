'''
Descroption: LeetCode 1619. 删除某些元素后的数组均值
Author: EmoryHuang
Date: 2021-09-22 20:59:38
Method:
简单题，去掉前后 5% 后计算均值
'''


class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        n = len(arr)
        d = n // 20
        return sum(arr[d:(n - d)]) / (n - 2 * d)
