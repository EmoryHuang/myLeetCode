'''
Descroption: LeetCode 934. 最短的桥
Author: EmoryHuang
Date: 2022-10-25 09:28:50
Method:
bfs
第一次使用dfs找到一座岛的所有陆地单元，然后再使用bfs向外拓展
将访问过的水域标记为-1，直到找到陆地
'''


class Solution:

    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        for i, row in enumerate(grid):
            for j, num in enumerate(row):
                if num != 1:
                    continue
                island = []
                grid[i][j] = -1
                q = deque([(i, j)])
                while q:
                    x, y = q.popleft()
                    island.append((x, y))
                    for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                            grid[nx][ny] = -1
                            q.append((nx, ny))

                step = 0
                q = island
                while True:
                    tmp = q
                    q = []
                    for x, y in tmp:
                        for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < n and 0 <= ny < n:
                                if grid[nx][ny] == 1:
                                    return step
                                if grid[nx][ny] == 0:
                                    grid[nx][ny] = -1
                                    q.append((nx, ny))
                    step += 1
