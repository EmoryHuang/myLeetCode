'''
Descroption: LeetCode 684. 冗余连接
Author: EmoryHuang
Date: 2021-08-01 14:28:33
Method:
并查集
如果两个顶点不位于同一个连通分量中，那么合并这两个顶点不会导致环的出现
如果位于同一个连通分量中，那么合并这两个顶点会导致环的出现
'''


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find(x: int) -> int:
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int):
            parent[find(x)] = find(y)

        n = len(edges)
        parent = list(range(n + 1))
        for x, y in edges:
            # 如果不位于同一个连通分量中
            # 那么合并这两个顶点不会导致环的出现
            if find(x) != find(y):
                union(x, y)
            # 如果位于同一个连通分量中
            # 那么合并这两个顶点会导致环的出现
            else:
                return [x, y]
