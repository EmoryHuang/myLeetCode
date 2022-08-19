'''
Descroption: LeetCode 1252. ����ֵ��Ԫ�����Ŀ
Author: EmoryHuang
Date: 2021-07-15 20:06:16
����˼·:
ģ�ⷨ��ģ���ÿ��ÿ�еļӷ���Ȼ�����ͳ�������ĸ���
'''


class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        mat = [[0] * n for _ in range(m)]
        for row, col in indices:
            for i in range(n):
                mat[row][i] += 1
            for i in range(m):
                mat[i][col] += 1
        ans = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] % 2 == 1:
                    ans += 1
        return ans
