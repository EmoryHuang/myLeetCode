'''
Descroption: LeetCode 1267. ͳ�Ʋ���ͨ�ŵķ�����
Author: EmoryHuang
Date: 2021-07-15 20:21:16
����˼·:
��������
��һ��ͳ��ÿ��ÿ�з�����������
�ڶ������ÿ��ÿ�з������������ж��Ƿ�Ϊ��ͨ
'''


class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        row, col = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    row[i] += 1
                    col[j] += 1
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and (row[i] > 1 or col[j] > 1):
                    ans += 1
        return ans
