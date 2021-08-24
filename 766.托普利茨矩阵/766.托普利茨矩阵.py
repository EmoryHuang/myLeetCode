'''
Descroption: LeetCode 766. �������ľ���
Author: EmoryHuang
Date: 2021-08-24 11:20:06
Method:
�Ƚϵ�ǰλ��Ԫ�غ��������·�Ԫ���Ƿ����
'''


class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        m, n = len(matrix), len(matrix[0])
        if m == 1 or n == 1: return True
        for i in range(m - 1):
            if matrix[i][:-1] != matrix[i + 1][1:]:
                return False
        return True