'''
Descroption: LeetCode 343. 整数拆分
Author: EmoryHuang
Date: 2021-06-30 19:55:00
解题思路:
动态规划
dp[i] 表示剪长度为 i 的绳子能得到的最大乘积
状态转移方程
dp[i] = max(dp[i], dp[j] * dp[i - j])
'''


class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
        # dp[i] 表示剪长度为 i 的绳子能得到的最大乘积
        dp = [0] * (n + 1)
        dp[0], dp[1], dp[2], dp[3] = 0, 1, 2, 3
        # 遍历要剪的绳子
        for i in range(4, n + 1):
            # j 只需遍历一半，因为对称
            for j in range(1, i // 2 + 1):
                # 剪为 i 和 i - j 的两端
                dp[i] = max(dp[i], dp[j] * dp[i - j])
        return dp[n]
