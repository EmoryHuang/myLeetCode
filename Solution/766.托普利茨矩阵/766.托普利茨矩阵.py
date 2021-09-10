'''
Descroption: LeetCode 766. 托普利茨矩阵
Author: EmoryHuang
Date: 2021-08-24 11:20:06
Method:
比较当前位置元素和它的右下方元素是否相等
'''


class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])
        if m == 1 or n == 1: return True
        for i in range(m - 1):
            if matrix[i][:-1] != matrix[i + 1][1:]:
                return False
        return True