'''
Descroption: LeetCode 1594. ��������Ǹ���
Author: EmoryHuang
Date: 2021-06-20 13:36:00
����˼·:
��̬�滮
�� dp ʱ��Ҫ��������Ԫ�ص���������
��ˣ�ͬʱά���������� maxpos �� minneg, �ֱ�洢�����ֵ����С��ֵ
״̬ת�Ʒ���
�� grid[i][j] >= 0����
maxpos[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j])
minneg[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j])
�� grid[i][j] < 0����
maxpos[i][j] = grid[i][j] * min(minneg[i][j - 1], minneg[i - 1][j])
minneg[i][j] = grid[i][j] * max(maxpos[i][j - 1], maxpos[i - 1][j])
'''


class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        mod = 10 ** 9 + 7
        m, n = len(grid), len(grid[0])
        maxpos = [[0] * n for _ in range(m)]  # �洢�����ֵ
        minneg = [[0] * n for _ in range(m)]  # �洢��С��ֵ
        maxpos[0][0] = minneg[0][0] = grid[0][0]
        # ��ʼ����һ�к͵�һ��
        for i in range(1, n):
            maxpos[0][i] = minneg[0][i] = maxpos[0][i - 1] * grid[0][i]
        for i in range(1, m):
            maxpos[i][0] = minneg[i][0] = maxpos[i - 1][0] * grid[i][0]
        # ״̬ת��
        for i in range(1, m):
            for j in range(1, n):
                if grid[i][j] >= 0:
                    maxpos[i][j] = grid[i][j] * \
                        max(maxpos[i][j - 1], maxpos[i - 1][j])
                    minneg[i][j] = grid[i][j] * \
                        min(minneg[i][j - 1], minneg[i - 1][j])
                else:
                    maxpos[i][j] = grid[i][j] * \
                        min(minneg[i][j - 1], minneg[i - 1][j])
                    minneg[i][j] = grid[i][j] * \
                        max(maxpos[i][j - 1], maxpos[i - 1][j])
        if maxpos[m - 1][n - 1] < 0:
            return -1
        return maxpos[m - 1][n - 1] % mod
