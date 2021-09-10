'''
Descroption: LeetCode 1584. �������е����С����
Author: EmoryHuang
Date: 2021-06-20 15:15:00
����˼·:
kruskal�㷨
�������е�֮��ľ��룬Ȼ���С�����������
���ò��鼯������С�������������ǰ�ߵ�������û�в�����С�������У��򽫸ñ���ӵ���С�������У����±����ͷ���
'''


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        mp = []
        n = len(points)
        # �������е�֮��ľ���
        for i in range(n):
            for j in range(i + 1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                mp.append([i, j, abs(x1 - x2) + abs(y1 - y2)])
        # �������С��������
        mp.sort(key=lambda x: x[2])
        parent = list(range(n))

        # ���鼯
        def find(x: int):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        edges, cost = 0, 0  # ��¼�������ܻ���
        for i, j, c in mp:
            a, b = find(i), find(j)
            if a != b:  # �������һ������
                parent[a] = b  # �ϲ�
                edges += 1
                cost += c
                if edges == n - 1:
                    break
        return cost
