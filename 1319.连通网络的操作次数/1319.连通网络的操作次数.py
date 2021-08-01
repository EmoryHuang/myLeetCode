'''
Descroption: LeetCode 1319. 连通网络的操作次数
Author: EmoryHuang
Date: 2021-08-01 14:05:13
Method:
并查集求连通分量数
每成功进行一次合并操作，连通分量数就会减少 1
'''


class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        def find(x: int) -> int:
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int):
            parent[find(x)] = find(y)

        edges = len(connections)
        # n 个顶点至少需要 n - 1 条边
        if edges < n - 1:
            return -1
        parent = list(range(n))
        for x, y in connections:
            union(x, y)
        ans = 0
        for i in range(n):
            if parent[i] == i:
                ans += 1
        return ans - 1