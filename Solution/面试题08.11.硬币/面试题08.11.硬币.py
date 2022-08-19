'''
Descroption: 面试题 08.11. 硬币
Author: EmoryHuang
Date: 2021-07-18 14:47:43
解题思路:
背包问题
dp[j]表示和为 j 的方案总数
状态转移方程：dp[j] += dp[j - coins[i]]
'''


class Solution:
    def waysToChange(self, n: int) -> int:
        coins = [25, 10, 5, 1]
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(len(coins)):
            for j in range(coins[i], n + 1):
                dp[j] += dp[j - coins[i]]
        return dp[-1] % 1000000007
