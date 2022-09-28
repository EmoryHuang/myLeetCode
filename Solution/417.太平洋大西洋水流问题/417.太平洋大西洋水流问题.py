'''
Descroption: LeetCode 417. 太平洋大西洋水流问题
Author: EmoryHuang
Date: 2022-04-27 09:19:52
Method:
dfs
分别计算可以流向太平洋和大西洋的位置，然后取并集
流向太平洋的位置, 可以从左边界和上边界出发, 向右边界和下边界流向(高处)
并使用visited记录所有可以经过的位置
'''


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        def dfs(x, y, visited):
            if (x, y) in visited:
                return
            visited.add((x, y))
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and heights[nx][ny] >= heights[x][y]:
                    dfs(nx, ny, visited)

        m, n = len(heights), len(heights[0])
        pacific = [(0, i) for i in range(n)] + [(i, 0) for i in range(1, m)]
        atlantic = [(m - 1, i) for i in range(n)] + [(i, n - 1) for i in range(m - 1)]

        visited_pacific = set()
        for x, y in pacific:
            dfs(x, y, visited_pacific)
        visited_atlantic = set()
        for x, y in atlantic:
            dfs(x, y, visited_atlantic)
        return list(map(list, visited_pacific & visited_atlantic))
