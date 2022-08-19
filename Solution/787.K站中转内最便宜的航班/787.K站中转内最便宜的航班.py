'''
Descroption: LeetCode 787. K 站中转内最便宜的航班
Author: EmoryHuang
Date: 2021-08-24 10:16:43
Method:
方法一：堆（超时）
根据给出的航班信息建立邻接矩阵，同时建堆存储路线
采用最小堆，每次弹出当前价格最小的路线，直到到达终点

方法二：动态规划
dp[i][k]表示经过k个中转站后到达站i的最低费用
状态转移方程：dp[v][k] = min(dp[v][k], dp[u][k - 1] + p);
'''


class Solution:
    # 方法一：堆（超时）
    # def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int,
    #                       k: int) -> int:
    #     if src == dst: return 0
    #     mp = defaultdict(list)
    #     for f, t, p in flights:
    #         mp[f].append([t, p])
    #     q = [(0, src, 0)]
    #     while q:
    #         total, u, step = heapq.heappop(q)
    #         # 如果中转的数量超过了 k 站
    #         if step - 1 > k:
    #             continue
    #         # 如果到达了终点站
    #         if u == dst:
    #             return total
    #         # 遍历当前站的邻接
    #         for v, p in mp[u]:
    #             heapq.heappush(q, (total + p, v, step + 1))
    #     return -1

    # 方法二：动态规划
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int,
                          k: int) -> int:
        if src == dst: return 0
        # dp[i][k]表示经过k个中转站后到达站i的最低费用
        dp = [float('inf')] * n
        dp[src] = 0
        for i in range(k + 1):
            tmp = dp[:]
            for u, v, p in flights:
                # dp[v][k] = min(dp[v][k], dp[u][k - 1] + p);
                dp[v] = min(dp[v], tmp[u] + p)
        return dp[dst] if dp[dst] != float('inf') else -1
