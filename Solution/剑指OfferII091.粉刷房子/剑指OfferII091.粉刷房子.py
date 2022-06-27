'''
Descroption: 剑指 Offer II 091. 粉刷房子
Author: EmoryHuang
Date: 2022-06-25 08:59:07
Method:
动态规划
dp[i][j]表示前i个房子第j种颜色的最小花费
状态转移方程：
dp[i][j] = min(dp[i-1][q], dp[i-1][k]) + cost[k][j]
'''


class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        # dp[i][j]表示前i个房子第j种颜色的最小花费
        dp = [[0] * 3 for _ in range(len(costs))]
        for i in range(len(costs)):
            for j in range(3):
                if i == 0:
                    dp[i][j] = costs[i][j]
                else:
                    dp[i][j] = min(dp[i - 1][(j - 1) % 3],
                                   dp[i - 1][(j + 1) % 3]) + costs[i][j]
        return min(dp[-1])