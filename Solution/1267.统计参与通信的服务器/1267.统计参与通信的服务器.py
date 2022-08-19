'''
Descroption: LeetCode 1267. 统计参与通信的服务器
Author: EmoryHuang
Date: 2021-07-15 20:21:16
解题思路:
遍历两遍
第一遍统计每行每列服务器的数量
第二遍根据每行每列服务器的数量判读是否为连通
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
