'''
Descroption: LeetCode 947. 移除最多的同行或同列石头
Author: EmoryHuang
Date: 2021-06-27 14:50:00
解题思路:
并查集
遍历各个点，在同一行或者同一列则合并
最后计算连通图个数，那么可以移除的石子的最大数量为 n - 连通图个数
'''


class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        parent = list(range(n))  # 初始化并查集

        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        for i in range(n):
            for j in range(i + 1, n):
                # 在同一行或者同一列则合并
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    union(i, j)
        ans = 0
        for i in range(n):
            if parent[i] == i:  # 连通图个数
                ans += 1
        return n - ans