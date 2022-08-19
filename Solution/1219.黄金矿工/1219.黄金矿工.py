'''
Descroption: LeetCode 1219. 黄金矿工
Author: EmoryHuang
Date: 2021-08-10 14:19:37
Method:
回溯
dfs暴力遍历所有可能
'''


class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
        self.ans = 0
        vis = []

        def dfs(x: int, y: int, cur: int) -> None:
            self.ans = max(self.ans, cur)
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < m and 0 <= ny < n and (
                        nx, ny) not in vis and grid[nx][ny]:
                    vis.append((nx, ny))
                    dfs(nx, ny, cur + grid[nx][ny])
                    vis.remove((nx, ny))

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    vis.append((i, j))
                    dfs(i, j, grid[i][j])
                    vis.remove((i, j))
        return self.ans
