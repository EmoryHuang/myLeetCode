'''
Descroption: LeetCode 807. ���ֳ��������
Author: EmoryHuang
Date: 2021-06-19 14:41:00
����˼·:
������е����ֵԪ�أ�����ÿ��grid[i][j]ֻ��Ҫȡ�����������ֵ����Сֵ����
'''


class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        row, col = [0] * n, [0] * n
        for i in range(n):
            for j in range(n):
                row[i] = max(row[i], grid[i][j])
                col[j] = max(col[j], grid[i][j])
        # ���д��
        # row = [max(i) for i in grid]
        # col = [max(j) for j in zip(*grid)]
        ans = 0
        for i in range(n):
            for j in range(n):
                ans += min(row[i], col[j]) - grid[i][j]
        return ans