'''
Descroption: LeetCode 1351. 统计有序矩阵中的负数
Author: EmoryHuang
Date: 2021-06-22 19:30:00
解题思路:
若当前数为负数，那么剩下的数必然也是负数，计数后进入下一行
'''


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] < 0:
                    cnt += n - j
                    break
        return cnt
