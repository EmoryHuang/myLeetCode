'''
Descroption: LeetCode 1641. 统计字典序元音字符串的数目
Author: EmoryHuang
Date: 2023-03-29 09:21:40
Method:
动态规划，dp[i] 表示以i开头的字符数目
'''


class Solution:
    def countVowelStrings(self, n: int) -> int:
        # dp[i] 表示以i开头的字符数目
        dp = [1] * 5
        for i in range(1, n):
            dp[0] = dp[0] + dp[1] + dp[2] + dp[3] + dp[4]
            dp[1] = dp[1] + dp[2] + dp[3] + dp[4]
            dp[2] = dp[2] + dp[3] + dp[4]
            dp[3] = dp[3] + dp[4]
        return sum(dp)