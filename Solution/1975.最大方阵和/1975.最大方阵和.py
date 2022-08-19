'''
Descroption: LeetCode 1975. ������
Author: EmoryHuang
Date: 2021-09-23 19:20:08
Method:
���������������ż������ô���и������ܱ������
�����������������������ôֻ��Ҫ��¼����ֵ��С����
'''


class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        ans = 0
        # ��¼����������������ֵ��С����
        cnt, m = 0, float('inf')
        for i in range(n):
            for j in range(n):
                ans += abs(matrix[i][j])
                if matrix[i][j] <= 0:
                    cnt += 1
                m = min(m, abs(matrix[i][j]))
        if cnt % 2 == 0:
            return ans
        return ans - 2 * m
