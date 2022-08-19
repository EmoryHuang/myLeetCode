'''
Descroption: LeetCode 474. 一和零
Author: EmoryHuang
Date: 2021-06-06 14:54:00
解题思路:
0-1 背包问题，有 m 和 n 两个体积
dp[i][j]表示有 i 个 0 和 j 个 1 时最大子集大小
状态转移方程：dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1)
'''


class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # dp[i][j]表示有i个0和j个1时最大子集大小
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for s in strs:
            cnt0 = s.count('0')
            cnt1 = s.count('1')
            for i in range(m, cnt0 - 1, -1):
                for j in range(n, cnt1 - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1)
        return dp[m][n]
