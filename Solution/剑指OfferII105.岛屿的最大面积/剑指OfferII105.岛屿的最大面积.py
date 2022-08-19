'''
Descroption: 剑指 Offer II 105. 岛屿的最大面积
Author: EmoryHuang
Date: 2021-08-19 16:20:48
Method:
方法一：并查集
初始时将每个位置都视为根，若周围是陆地，则和合并并记录每个连通图的节点数量
方法二：BFS
广度优先遍历，每访问一个点就将其置 0，记录每个连通图的节点数量，取最大值
方法三：DFS
与 BFS 类似，每访问一个点就将其置 0，记录每个连通图的节点数量，取最大值
'''


class Solution:
    # 方法一：并查集
    # def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
    #     def find(x: int) -> int:
    #         if x != parent[x]:
    #             parent[x] = find(parent[x])
    #         return parent[x]

    #     def union(x: int, y: int) -> None:
    #         r1, r2 = find(x), find(y)
    #         if r1 != r2:
    #             parent[r2] = r1
    #             num[r1] += num[r2]

    #     m, n = len(grid), len(grid[0])
    #     # 初始化并查集
    #     parent = list(range(m * n))
    #     # 更新集合大小
    #     num = [0] * (m * n)
    #     for i in range(m):
    #         for j in range(n):
    #             if grid[i][j] == 1:
    #                 num[i * n + j] = 1
    #                 # 只需要向下或向右
    #                 for dx, dy in [(0, 1), (1, 0)]:
    #                     x, y = i + dx, j + dy
    #                     if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
    #                         num[x * n + y] = 1
    #                         union(i * n + j, x * n + y)
    #     return max(num)

    # 方法二：BFS
    # def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
    #     def bfs(i: int, j: int) -> None:
    #         q = deque()
    #         q.append([i, j])
    #         grid[i][j] = 0  # 标记为访问
    #         cnt = 1  # 记录当前岛大小
    #         while q:
    #             x, y = q.popleft()
    #             for dx, dy in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
    #                 nx, ny = x + dx, y + dy
    #                 if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
    #                     grid[nx][ny] = 0  # 标记为访问
    #                     q.append([nx, ny])
    #                     cnt += 1
    #         self.ans = max(self.ans, cnt)

    #     m, n = len(grid), len(grid[0])
    #     self.ans = 0
    #     for i in range(m):
    #         for j in range(n):
    #             if grid[i][j] == 1:
    #                 bfs(i, j)
    #     return self.ans

    # 方法三：DFS
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            grid[i][j] = 0  # 标记为访问
            cnt = 1
            for dx, dy in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
                nx, ny = i + dx, j + dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
                    cnt += dfs(nx, ny)
            return cnt

        m, n = len(grid), len(grid[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans = max(ans, dfs(i, j))
        return ans
