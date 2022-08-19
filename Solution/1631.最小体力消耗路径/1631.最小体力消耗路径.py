'''
Descroption: LeetCode 1631. 最小体力消耗路径
Author: EmoryHuang
Date: 2021-08-25 19:07:15
Method:
方法一：并查集
将图中的所有边按照权值从小到大进行排序，并依次加入并查集中
如果左上角和右下角从非连通状态变为连通状态，那么得到答案

方法二：二分 + BFS/DFS
二分法判断体力消耗为 mid 时能否到达(n-1, n-1)
具体来说，从(0, 0)开始进行广度优先遍历，
若未超出边界并且高度小于等于 t，则标记为访问
'''


class Solution:
    # 方法一：并查集
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def merge(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        m, n = len(heights), len(heights[0])
        # 初始化并查集
        parent = list(range(1000001))
        edges = []
        for i in range(m):
            for j in range(n):
                pos = i * n + j
                if i > 0:
                    edges.append([abs(heights[i][j] - heights[i - 1][j]), pos, pos - n])
                if j > 0:
                    edges.append([abs(heights[i][j] - heights[i][j - 1]), pos, pos - 1])
        edges.sort()
        for d, u, v in edges:
            merge(u, v)
            if find(0) == find(m * n - 1):
                return d
        return 0

    # 方法二：二分 + BFS/DFS
    # def minimumEffortPath(self, heights: List[List[int]]) -> int:
    #     def check(t: int) -> None:
    #         m, n = len(heights), len(heights[0])
    #         vis = [[0] * n for _ in range(m)]
    #         vis[0][0] = 1
    #         q = deque()
    #         q.append([0, 0])
    #         while q:
    #             i, j = q.popleft()
    #             for dx, dy in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
    #                 x, y = i + dx, j + dy
    #                 if 0 <= x < m and 0 <= y < n and abs(
    #                         heights[x][y] - heights[i][j]) <= t and vis[x][y] == 0:
    #                     q.append([x, y])
    #                     vis[x][y] = 1
    #         return vis[m - 1][n - 1] == 1

    #     l, r = 0, 10**6 - 1
    #     while l < r:
    #         mid = l + (r - l) // 2
    #         # 二分法判断体力消耗为 mid 时能否到达(n-1, n-1)
    #         if check(mid):
    #             r = mid
    #         else:
    #             l = mid + 1
    #     return l