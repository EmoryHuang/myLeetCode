'''
Descroption: 剑指 Offer II 088. 爬楼梯的最少成本
Author: EmoryHuang
Date: 2021-08-09 20:19:15
Method:
动态规划
dp[i] 表示到第i个阶梯为止的最小花费
状态转移方程：dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
'''


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * n
        dp[0], dp[1] = cost[0], cost[1]
        for i in range(2, n):
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
        return min(dp[-1], dp[-2])
