'''
Descroption: LeetCode 598. 范围求和 II
Author: EmoryHuang
Date: 2021-09-13 16:16:13
Method:
简单题，由于修改的范围始终是一个从左上角开始的矩阵，
那么只要得到最小的操作行列即可确定最大值所在的矩形
'''


class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        row, col = m, n
        for i, j in ops:
            row, col = min(row, i), min(col, j)
        return row * col
