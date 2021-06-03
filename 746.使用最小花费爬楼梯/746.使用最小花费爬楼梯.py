'''
Descroption: LeetCode 746. 使用最小花费爬楼梯
Author: EmoryHuang
Date: 2021-06-03 16:25:00
解题思路:
动态规划
dp[i] 表示达到下标 i 的最小花费
由于可以选择下标 0 或 1 作为初始阶梯，因此有 dp[0] = dp[1] = 0
状态转移方程：dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
'''


class Solution:
    # 空间复杂度：O(n)
    # def minCostClimbingStairs(self, cost: List[int]) -> int:
    #     n = len(cost)
    #     dp = [0] * (n + 1)
    #     for i in range(2, n + 1):
    #         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
    #     return dp[n]

    # 空间复杂度：O(1)
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        pre, cur = 0, 0
        for i in range(2, n + 1):
            next = min(cur + cost[i - 1], pre + cost[i - 2])
            pre, cur = cur, next
        return cur
