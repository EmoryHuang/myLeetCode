'''
Descroption: LeetCode 面试题 01.08. 零矩阵
Author: EmoryHuang
Date: 2022-09-30 09:06:08
Method:
寻找矩阵中所有零所在的位置，并记录，之后再次遍历清零
'''


class Solution:

    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        row, col = [0] * m, [0] * n
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row[i], col[j] = 1, 1
        for i in range(m):
            for j in range(n):
                if row[i] or col[j]:
                    matrix[i][j] = 0
