'''
Descroption: LeetCode 516. 最长回文子序列
Author: EmoryHuang
Date: 2021-08-11 18:33:42
Method:
动态规划
dp[i][j]表示从s[i]到s[j]的最长回文子序列
状态转移方程
当 s[i] == s[j] 时，dp[i][j] = d[i+1][j-1] + 2
当 s[i] != s[j] 时，dp[i][j] = max(dp[i+1][j], dp[i][j-1])
'''


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        # dp[i][j]表示从s[i]到s[j]的最长回文子序列
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]