'''
Descroption: LeetCode 1514. 概率最大的路径
Author: EmoryHuang
Date: 2021-06-16 14:04:00
解题思路:
spfa算法
用邻接矩阵存储图
求得概率最大的路径
'''


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        mp = collections.defaultdict(list)
        for i, (x, y) in enumerate(edges):
            mp[x].append((y, succProb[i]))
            mp[y].append((x, succProb[i]))
        d = [0] * n
        inq = [0] * n
        q = [start]
        inq[start] = 1  # 起点在队列中
        d[start] = 1    # 起点到自身的概率为1
        while q:
            u = q[0]
            q = q[1:]
            inq[u] = 0  # u不在队列中
            # 遍历邻接节点
            for v, dis in mp[u]:
                if d[v] < d[u] * dis:  # 概率更大的路径
                    d[v] = d[u] * dis
                    if not inq[v]:
                        q.append(v)
                        inq[v] = 1
        return d[end]
