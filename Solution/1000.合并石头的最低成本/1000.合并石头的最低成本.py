'''
Descroption: LeetCode 1000. 合并石头的最低成本
Author: EmoryHuang
Date: 2023-04-04 09:44:40
Method:
动态规划，区间dp
dp[i][j][k]为合并第i堆到第j堆石头为k堆的成本
状态转移方程：
dp[l][r][k] = min(dp[l][r][k], dp[l][p][k - 1] + dp[p + 1][r][1])
'''


class Solution:
    def mergeStones(self, stones: List[int], k: int) -> int:
        n = len(stones)
        if (n - 1) % (k - 1) != 0:
            return -1
        # dp[i][j][k]为合并第i堆到第j堆石头为k堆的成本
        dp = [[[inf] * (k + 1) for _ in range(n + 1)] for _ in range(n + 1)]
        # 前缀和
        s = [0] * (n + 1)
        for i in range(1, n + 1):
            s[i] = s[i - 1] + stones[i - 1]
            dp[i][i][1] = 0
        # 枚举区间长度
        for sz in range(2, n + 1):
            # 枚举左端点
            for l in range(1, n - sz + 2):
                r = l + sz - 1
                for k in range(2, k + 1):
                    # 枚举分界点
                    for p in range(l, r):
                        dp[l][r][k] = min(dp[l][r][k], dp[l][p][k - 1] + dp[p + 1][r][1])
                dp[l][r][1] = min(dp[l][r][1], dp[l][r][k] + s[r] - s[l - 1])
        return dp[1][n][1]