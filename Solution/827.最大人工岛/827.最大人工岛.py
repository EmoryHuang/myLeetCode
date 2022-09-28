'''
Descroption: LeetCode 827. 最大人工岛
Author: EmoryHuang
Date: 2022-09-18 12:15:45
Method:
并查集
使用并查集维护所有连通块大小，之后枚举所有可能翻转的位置寻找最优位置
'''


class Solution:
    def find(self, parents, x):
        if parents[x] != x:
            parents[x] = self.find(parents, parents[x])
        return parents[x]

    def union(self, parents, sizes, a, b):
        pa, pb = self.find(parents, a), self.find(parents, b)
        if pa == pb:
            return
        if sizes[pa] > sizes[pb]:
            pa, pb = pb, pa
        sizes[pb] += sizes[pa]
        parents[pa] = parents[pb]

    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ans = 0
        parents = [i for i in range(n * n + 1)]
        sizes = [1 for _ in range(n * n + 1)]
        # 遍历图并进行并查集合并，并记录每个连通块的大小
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    continue
                for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                    x, y = i + dx, j + dy
                    if 0 <= x < n and 0 <= y < n and grid[x][y] != 0:
                        self.union(parents, sizes, i * n + j + 1, x * n + y + 1)
        # 再次遍历图，枚举并进行翻转
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    ans = max(ans, sizes[self.find(parents, i * n + j + 1)])
                else:
                    total = 1
                    vis = []
                    for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                        x, y = i + dx, j + dy
                        if 0 <= x < n and 0 <= y < n and grid[x][y] != 0:
                            root = self.find(parents, x * n + y + 1)
                            if root in vis:
                                continue
                            total += sizes[root]
                            vis.append(root)
                    ans = max(ans, total)
        return ans