'''
Descroption: LeetCode 463. 岛屿的周长
Author: EmoryHuang
Date: 2021-06-14 14:43:00
解题思路:
遍历每个陆地格子，看其四个方向是否为陆地
若为陆地则需要 -1
'''


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    cnt = 0
                    for k in range(4):
                        x, y = i + dx[k], j + dy[k]
                        if 0 <= x < n and 0 <= y < m and grid[x][y] == 1:
                            cnt += 1
                    ans += 4 - cnt
        return ans
