'''
Descroption: 面试题 10.09. 排序矩阵查找
Author: EmoryHuang
Date: 2021-07-18 14:08:06
解题思路:
从左下或者右上开始查找
'''


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not len(matrix):
            return False
        m, n = len(matrix), len(matrix[0])
        i, j = m - 1, 0
        while i >= 0 and j < n:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        return False
