'''
Descroption: LeetCode 629. K个逆序对数组
Author: EmoryHuang
Date: 2021-11-11 14:46:15
Method:
动态规划
dp[i][j] 表示 i 个数字，逆序对个数为 j 时的逆序对数
状态转移方程
dp(i, j) = dp(i - 1, j) + dp(i - 1, j - 1) + ... + dp(i - 1, j - i + 1)

公式推导优化
dp(i, j) = dp(i - 1, j) + dp(i - 1, j - 1) + ... + dp(i - 1, j - i + 1)           (1)
dp(i, j - 1) = dp(i - 1, j - 1) + dp(i - 1, j - 2) + ... + dp(i - 1, j - i)       (2)
(1) - (2)
=> dp(i, j) - dp(i, j - 1) = dp(i - 1, j) - dp(i - 1, j - i)
=> dp(i, j) = dp(i - 1, j) - dp(i - 1, j - i) + dp(i, j - 1)
'''


class Solution:
    # 动态规划（超时）
    # def kInversePairs(self, n: int, k: int) -> int:
    #     mod = 1e9 + 7
    #     # dp[i][j] 表示 i 个数字，逆序对个数为 j 时的逆序对数
    #     # dp(i, j) = dp(i - 1, j) + dp(i - 1, j - 1) + ... + dp(i - 1, j - i + 1)
    #     dp = [[0] * (k + 1) for _ in range(n + 1)]
    #     dp[0][0] = 1
    #     for i in range(1, n + 1):
    #         for j in range(k + 1):
    #             for k in range(max(j - i + 1, 0), j + 1):
    #                 dp[i][j] += dp[i - 1][k]
    #                 dp[i][j] %= mod
    #     return int(dp[n][k])

    # 空间优化（超时）
    # def kInversePairs(self, n: int, k: int) -> int:
    #     mod = 1e9 + 7
    #     # dp[i][j] 表示 i 个数字，逆序对个数为 j 时的逆序对数
    #     # dp(i, j) = dp(i - 1, j) + dp(i - 1, j - 1) + ... + dp(i - 1, j - i + 1)
    #     dp = [0] * (k + 1)
    #     dp[0] = 1
    #     for i in range(1, n + 1):
    #         cur = [0] * (k + 1)
    #         for j in range(k + 1):
    #             for k in range(max(j - i + 1, 0), j + 1):
    #                 cur[j] += dp[k]
    #                 cur[j] %= mod
    #         dp = cur
    #     return int(dp[k])

    # 公式推导优化
    def kInversePairs(self, n: int, k: int) -> int:
        mod = 1e9 + 7
        # dp[i][j] 表示 i 个数字，逆序对个数为 j 时的逆序对数
        # 公式推导
        # dp(i, j) = dp(i - 1, j) + dp(i - 1, j - 1) + ... + dp(i - 1, j - i + 1)           (1)
        # dp(i, j - 1) = dp(i - 1, j - 1) + dp(i - 1, j - 2) + ... + dp(i - 1, j - i)       (2)
        # (1) - (2)
        # => dp(i, j) - dp(i, j - 1) = dp(i - 1, j) - dp(i - 1, j - i)
        # => dp(i, j) = dp(i - 1, j) - dp(i - 1, j - i) + dp(i, j - 1)
        dp = [0] * (k + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            cur = [0] * (k + 1)
            for j in range(k + 1):
                if j >= i:
                    cur[j] = dp[j] - dp[j - i] + cur[j - 1]
                else:
                    cur[j] = dp[j] + cur[j - 1]
                cur[j] %= mod
            dp = cur
        return int(dp[k])
