'''
Descroption: LeetCode 743. 网络延迟时间
Author: EmoryHuang
Date: 2021-08-02 14:06:11
Method:
从 k 点出发，到其他点 x 的最短距离的最大值
方法一：SPFA算法
方法二：Floyd算法
方法三：朴素dijkstra算法
'''


class Solution:
    # 方法一：SPFA算法
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # 建立邻接表
        mp = defaultdict(list)
        for u, v, w in times:
            mp[u].append([v, w])
        d = [float('inf')] * (n + 1)
        q = deque()
        inq = [False] * (n + 1)
        d[k] = d[0] = 0
        q.append(k)
        inq[k] = True  # 节点是否在队列中

        while q:
            u = q.popleft()  # 取队首元素
            inq[u] = False  # 出队
            for j in range(len(mp[u])):  # 遍历与u相邻的节点
                v = mp[u][j][0]  # 节点编号
                w = mp[u][j][1]  # 边权
                if d[v] > d[u] + w:  # 更新最短距离
                    d[v] = d[u] + w
                    if not inq[v]:
                        q.append(v)
                        inq[v] = True
        for dis in d:
            if dis == float('inf'):
                return -1
        return max(d)

    # 方法二：Floyd算法
    # def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
    #     # 建立邻接矩阵
    #     mp = [[float('inf')] * (n + 1) for _ in range(n + 1)]
    #     for i in range(n + 1):
    #         mp[i][i] = mp[i][0] = mp[0][i] = 0
    #     for u, v, w in times:
    #         mp[u][v] = w

    #     for t in range(1, n + 1):
    #         for i in range(1, n + 1):
    #             for j in range(1, n + 1):
    #                 mp[i][j] = min(mp[i][j], mp[i][t] + mp[t][j])
    #     for i in range(1, n + 1):
    #         if mp[k][i] == float('inf'):
    #             return -1
    #     return max(mp[k])

    # 方法三：朴素dijkstra算法
    # def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
    #     # 建立邻接矩阵
    #     mp = [[float('inf')] * (n + 1) for _ in range(n + 1)]
    #     for i in range(n + 1):
    #         mp[i][i] = 0
    #     for u, v, w in times:
    #         mp[u][v] = w

    #     d = [float('inf')] * (n + 1)
    #     vis = [False] * (n + 1)
    #     d[k] = d[0] = 0  # 起点到自身的距离为0
    #     for i in range(1, n + 1):
    #         u = -1  # 寻找距离最小的点
    #         for j in range(1, n + 1):
    #             if not vis[j] and (u == -1 or d[u] > d[j]):
    #                 u = j
    #         vis[u] = True
    #         for v in range(1, n + 1):
    #             d[v] = min(d[v], d[u] + mp[u][v])  # 以u为中介点
    #     for dis in d:
    #         if dis == float('inf'):
    #             return -1
    #     return max(d)
