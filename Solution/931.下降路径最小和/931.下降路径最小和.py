'''
Descroption: LeetCode 931. 下降路径最小和
Author: EmoryHuang
Date: 2021-09-18 19:28:58
Method:
动态规划
经典求路径和问题，正向，反向都可以
状态转移方程：dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1])
'''


class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        dp = [[float('inf')] * n for _ in range(n)]
        for i in range(n):
            dp[0][i] = matrix[0][i]
        for i in range(1, n):
            for j in range(n):
                if j == 0:
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1])
                elif j == n - 1:
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1])
                else:
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1],
                                                  dp[i - 1][j + 1])
        return min(dp[n - 1])
