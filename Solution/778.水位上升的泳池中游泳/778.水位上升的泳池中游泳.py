'''
Descroption: LeetCode 778. ˮλ������Ӿ������Ӿ
Author: EmoryHuang
Date: 2021-08-25 16:37:30
Method:
����һ�����鼯
ά��ÿ���߶ȶ�Ӧ��λ�ã�Ȼ���� t ʱ��ʱ�����λ�ã������ĸ��������
��δ�����߽粢�Ҹ߶�С�ڵ��� t��tʱ�̸߶�Ϊt������ô���кϲ�
�����(0, 0) �� (n-1, n-1) �Ƿ���һ����ͨͼ�С�

������������ + BFS/DFS
���ַ��ж� mid ʱ���ܷ񵽴�(n-1, n-1)
������˵����(0, 0)��ʼ���й�����ȱ�����
��δ�����߽粢�Ҹ߶�С�ڵ��� t������Ϊ����
'''


class Solution:
    # ����һ�����鼯
    def swimInWater(self, grid: List[List[int]]) -> int:
        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def merge(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        n = len(grid)
        if n == 1: return 0
        # ��ʼ�����鼯
        parent = list(range(n * n))
        # �õ�ÿ���߶ȶ�Ӧ��λ��
        pos = [0, 0] * (n * n - 1)
        for i in range(n):
            for j in range(n):
                pos[grid[i][j]] = [i, j]
        # ����ʱ�� t
        for t in range(n * n):
            # t ʱ�̣��߶�Ϊ t ��λ�ã�
            i, j = pos[t]
            for dx, dy in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                x, y = i + dx, j + dy
                # ��δ�����߽粢�Ҹ߶�С�ڵ��� t
                if 0 <= x < n and 0 <= y < n and grid[x][y] <= t:
                    merge(i * n + j, x * n + y)
            if find(0) == find(n * n - 1):
                return t
        return -1

    # ������������ + BFS/DFS
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
    #         # ���ַ��ж� mid ʱ���ܷ񵽴�(n-1, n-1)
    #         if check(mid):
    #             r = mid
    #         else:
    #             l = mid + 1
    #     return l