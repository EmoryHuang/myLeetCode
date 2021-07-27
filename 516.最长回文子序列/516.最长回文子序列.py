'''
Descroption: LeetCode 516. 最长回文子序列
Author: EmoryHuang
Date: 2021-07-27 20:07:53
Method:
动态规划
dp[i][j] 表示 s 的第 i 个字符到第 j 个字符组成的子串中，最长的回文序列长度
状态转移方程：
若 s[i] == s[j] 则 dp[i][j] = dp[i + 1][j - 1] + 2
若 s[i] != s[j] 则 dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
'''


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]
