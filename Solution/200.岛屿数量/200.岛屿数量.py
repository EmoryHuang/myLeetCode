'''
Descroption: LeetCode 200. ��������
Author: EmoryHuang
Date: 2021-08-18 20:42:36
Method:
����һ�����鼯
i * col + jΨһ��ʶÿ��Ԫ�أ��ϲ���ͨ��Ԫ��Ϊһ������
�������� = ��ͨ��ĸ��� + ˮ��Ԫ�ظ���
����ÿ��Ԫ�ص�ʱ��ͳ��ˮ�ĸ���
��������BFS
������ȱ�����ÿ����һ����ͽ����� 0��ͳ����ͨ����
��������DFS
�� BFS ���ƣ�ÿ����һ����ͽ����� 0
'''


class Solution:
    # ����һ�����鼯
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
                    # ֻ�����Һ����²鿴
                    for dx, dy in [(0, 1), (1, 0)]:
                        x, y = i + dx, j + dy
                        if 0 <= x < m and 0 <= y < n and grid[x][y] == '1':
                            union(i * n + j, x * n + y)
        for i, num in enumerate(parent):
            if i == num:
                ans += 1
        return ans - ocean

    # ��������BFS
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

    # ��������DFS
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
