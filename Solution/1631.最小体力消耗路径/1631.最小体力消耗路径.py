'''
Descroption: LeetCode 1631. ��С��������·��
Author: EmoryHuang
Date: 2021-08-25 19:07:15
Method:
����һ�����鼯
��ͼ�е����б߰���Ȩֵ��С����������򣬲����μ��벢�鼯��
������ϽǺ����½Ǵӷ���ͨ״̬��Ϊ��ͨ״̬����ô�õ���

������������ + BFS/DFS
���ַ��ж���������Ϊ mid ʱ�ܷ񵽴�(n-1, n-1)
������˵����(0, 0)��ʼ���й�����ȱ�����
��δ�����߽粢�Ҹ߶�С�ڵ��� t������Ϊ����
'''


class Solution:
    # ����һ�����鼯
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def merge(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        m, n = len(heights), len(heights[0])
        # ��ʼ�����鼯
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

    # ������������ + BFS/DFS
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
    #         # ���ַ��ж���������Ϊ mid ʱ�ܷ񵽴�(n-1, n-1)
    #         if check(mid):
    #             r = mid
    #         else:
    #             l = mid + 1
    #     return l