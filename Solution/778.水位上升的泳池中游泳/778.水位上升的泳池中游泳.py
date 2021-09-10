'''
Descroption: LeetCode 778. 水位上升的泳池中游泳
Author: EmoryHuang
Date: 2021-08-25 16:37:30
Method:
方法一：并查集
维护每个高度对应的位置，然后考虑 t 时刻时方格的位置，并向四个方向遍历
若未超出边界并且高度小于等于 t（t时刻高度为t），那么进行合并
最后检查(0, 0) 与 (n-1, n-1) 是否在一个连通图中。

方法二：二分 + BFS/DFS
二分法判断 mid 时刻能否到达(n-1, n-1)
具体来说，从(0, 0)开始进行广度优先遍历，
若未超出边界并且高度小于等于 t，则标记为访问
'''


class Solution:
    # 方法一：并查集
    def swimInWater(self, grid: List[List[int]]) -> int:
        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def merge(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        n = len(grid)
        if n == 1: return 0
        # 初始化并查集
        parent = list(range(n * n))
        # 得到每个高度对应的位置
        pos = [0, 0] * (n * n - 1)
        for i in range(n):
            for j in range(n):
                pos[grid[i][j]] = [i, j]
        # 遍历时间 t
        for t in range(n * n):
            # t 时刻（高度为 t 的位置）
            i, j = pos[t]
            for dx, dy in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                x, y = i + dx, j + dy
                # 若未超出边界并且高度小于等于 t
                if 0 <= x < n and 0 <= y < n and grid[x][y] <= t:
                    merge(i * n + j, x * n + y)
            if find(0) == find(n * n - 1):
                return t
        return -1

    # 方法二：二分 + BFS/DFS
    # def swimInWater(self, grid: List[List[int]]) -> int:
    #     def check(t: int) -> None:
    #         if grid[0][0] > t: return False
    #         vis = [[0] * n for _ in range(n)]
    #         vis[0][0] = 1
    #         q = deque()
    #         q.append([0, 0])
    #         while q:
    #             i, j = q.popleft()
    #             for dx, dy in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
    #                 x, y = i + dx, j + dy
    #                 if 0 <= x < n and 0 <= y < n and grid[x][y] <= t and vis[x][y] == 0:
    #                     q.append([x, y])
    #                     vis[x][y] = 1
    #         return vis[n - 1][n - 1] == 1

    #     n = len(grid)
    #     if n == 1: return 0
    #     l, r = 0, n * n - 1
    #     while l < r:
    #         mid = l + (r - l) // 2
    #         # 二分法判断 mid 时刻能否到达(n-1, n-1)
    #         if check(mid):
    #             r = mid
    #         else:
    #             l = mid + 1
    #     return l