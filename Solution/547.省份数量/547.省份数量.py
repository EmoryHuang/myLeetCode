'''
Descroption: LeetCode 547. 省份数量
Author: EmoryHuang
Date: 2021-08-01 13:44:25
Method:
经典问题，求连通分量数
方法一：并查集
如果两个城市属于相同的连通分量，则合并
方法二：dfs
遍历所有城市，对于每个城市，如果该城市尚未被访问过，则从该城市开始深度优先搜索
遍历完全部城市以后，即可得到连通分量的总数
'''


class Solution:
    # 方法一：并查集
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def find(x: int) -> int:
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int) -> None:
            parent[find(x)] = find(y)

        n = len(isConnected)  # 城市的数量
        parent = list(range(n))  # 初始化并查集
        for i in range(n):
            for j in range(i + 1, n):
                if isConnected[i][j] == 1:
                    union(i, j)
        ans = 0
        for i, p in enumerate(parent):
            if p == i:
                ans += 1
        return ans

    # 方法二：dfs
    # def findCircleNum(self, isConnected: List[List[int]]) -> int:
    #     def dfs(i: int):
    #         for j in range(n):
    #             if isConnected[i][j] == 1 and j not in vis:
    #                 vis.add(j)
    #                 dfs(j)

    #     n = len(isConnected)
    #     vis = set()
    #     ans = 0
    #     for i in range(n):
    #         if i not in vis:
    #             dfs(i)
    #             ans += 1
    #     return ans
