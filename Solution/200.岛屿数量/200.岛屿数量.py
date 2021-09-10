'''
Descroption: LeetCode 200. 岛屿数量
Author: EmoryHuang
Date: 2021-08-18 20:42:36
Method:
方法一：并查集
i * col + j唯一标识每个元素，合并连通的元素为一个集合
岛屿数量 = 连通块的个数 + 水的元素个数
遍历每个元素的时候，统计水的个数
方法二：BFS
广度优先遍历，每访问一个点就将其置 0，统计连通数量
方法三：DFS
与 BFS 类似，每访问一个点就将其置 0
'''


class Solution:
    # 方法一：并查集
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        parent = list(range(m * n))

        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int) -> int:
            parent[find(x)] = find(y)

        ocean, ans = 0, 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '0':
                    ocean += 1
                else:
                    # 只需向右和向下查看
                    for dx, dy in [(0, 1), (1, 0)]:
                        x, y = i + dx, j + dy
                        if 0 <= x < m and 0 <= y < n and grid[x][y] == '1':
                            union(i * n + j, x * n + y)
        for i, num in enumerate(parent):
            if i == num:
                ans += 1
        return ans - ocean

    # 方法二：BFS
    # def numIslands(self, grid: List[List[str]]) -> int:
    #     m, n = len(grid), len(grid[0])

    #     def bfs(i: int, j: int) -> None:
    #         q = deque()
    #         q.append([i, j])
    #         grid[i][j] = '0'
    #         while q:
    #             x, y = q.popleft()
    #             for dx, dy in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
    #                 nx, ny = x + dx, y + dy
    #                 if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == '1':
    #                     q.append([nx, ny])
    #                     grid[nx][ny] = '0'

    #     ans = 0
    #     for i in range(m):
    #         for j in range(n):
    #             if grid[i][j] == '1':
    #                 ans += 1
    #                 bfs(i, j)
    #     return ans

    # 方法三：DFS
    # def numIslands(self, grid: List[List[str]]) -> int:
    #     m, n = len(grid), len(grid[0])

    #     def dfs(i: int, j: int) -> None:
    #         grid[i][j] = '0'
    #         for dx, dy in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
    #             nx, ny = i + dx, j + dy
    #             if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == '1':
    #                 dfs(nx, ny)

    #     ans = 0
    #     for i in range(m):
    #         for j in range(n):
    #             if grid[i][j] == '1':
    #                 ans += 1
    #                 dfs(i, j)
    #     return ans
