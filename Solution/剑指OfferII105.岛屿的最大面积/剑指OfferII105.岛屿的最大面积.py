'''
Descroption: ��ָ Offer II 105. �����������
Author: EmoryHuang
Date: 2021-08-19 16:20:48
Method:
����һ�����鼯
��ʼʱ��ÿ��λ�ö���Ϊ��������Χ��½�أ���ͺϲ�����¼ÿ����ͨͼ�Ľڵ�����
��������BFS
������ȱ�����ÿ����һ����ͽ����� 0����¼ÿ����ͨͼ�Ľڵ�������ȡ���ֵ
��������DFS
�� BFS ���ƣ�ÿ����һ����ͽ����� 0����¼ÿ����ͨͼ�Ľڵ�������ȡ���ֵ
'''


class Solution:
    # ����һ�����鼯
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
    #     # ��ʼ�����鼯
    #     parent = list(range(m * n))
    #     # ���¼��ϴ�С
    #     num = [0] * (m * n)
    #     for i in range(m):
    #         for j in range(n):
    #             if grid[i][j] == 1:
    #                 num[i * n + j] = 1
    #                 # ֻ��Ҫ���»�����
    #                 for dx, dy in [(0, 1), (1, 0)]:
    #                     x, y = i + dx, j + dy
    #                     if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
    #                         num[x * n + y] = 1
    #                         union(i * n + j, x * n + y)
    #     return max(num)

    # ��������BFS
    # def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
    #     def bfs(i: int, j: int) -> None:
    #         q = deque()
    #         q.append([i, j])
    #         grid[i][j] = 0  # ���Ϊ����
    #         cnt = 1  # ��¼��ǰ����С
    #         while q:
    #             x, y = q.popleft()
    #             for dx, dy in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
    #                 nx, ny = x + dx, y + dy
    #                 if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1:
    #                     grid[nx][ny] = 0  # ���Ϊ����
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

    # ��������DFS
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def dfs(i: int, j: int) -> int:
            grid[i][j] = 0  # ���Ϊ����
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
