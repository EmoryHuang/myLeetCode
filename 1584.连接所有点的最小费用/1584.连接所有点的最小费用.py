'''
Descroption: LeetCode 1584. 连接所有点的最小费用
Author: EmoryHuang
Date: 2021-06-20 15:15:00
解题思路:
kruskal算法
计算所有点之间的距离，然后从小到大进行排序
利用并查集构建最小生成树，如果当前边的两个点没有不在最小生成树中，则将该边添加到最小生成树中，更新边数和费用
'''


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        mp = []
        n = len(points)
        # 计算所有点之间的距离
        for i in range(n):
            for j in range(i + 1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                mp.append([i, j, abs(x1 - x2) + abs(y1 - y2)])
        # 按距离从小到大排序
        mp.sort(key=lambda x: x[2])
        parent = list(range(n))

        # 并查集
        def find(x: int):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        edges, cost = 0, 0  # 记录边数和总花费
        for i, j, c in mp:
            a, b = find(i), find(j)
            if a != b:  # 如果不在一个集合
                parent[a] = b  # 合并
                edges += 1
                cost += c
                if edges == n - 1:
                    break
        return cost
