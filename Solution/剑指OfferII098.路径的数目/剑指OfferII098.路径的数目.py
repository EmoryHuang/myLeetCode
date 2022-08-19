'''
Descroption: 剑指 Offer II 098. 路径的数目
Author: EmoryHuang
Date: 2021-08-04 16:48:19
Method:
动态规划
状态转移方程：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
'''


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j - 1]
        return dp[-1]
