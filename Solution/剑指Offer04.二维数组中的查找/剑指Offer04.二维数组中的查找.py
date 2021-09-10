'''
Descroption: ��ָ Offer 04. ��ά�����еĲ���
Author: EmoryHuang
Date: 2021-06-27 16:00:00
����˼·:
���⣬�����»������Ͻ��в���
'''


class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        n, m = len(matrix), len(matrix[0])
        i, j = n-1, 0
        while i >= 0 and j < m:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        return False
