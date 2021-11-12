'''
Descroption: LeetCode 375. 猜数字大小 II
Author: EmoryHuang
Date: 2021-11-12 19:18:37
Method:
方法一: dfs
递归得到当前区间下选择数字的最坏情况下最好的结果

方法二: 动态规划
dp[i][j] 表示在区间 [i, j] 中选择的最小成本
cur = max(dp[l][i - 1], dp[i + 1][r]) + i
'''


class Solution:
    # 方法一: dfs
    # def getMoneyAmount(self, n: int) -> int:
    #     def dfs(l: int, r: int):
    #         if l >= r:
    #             return 0
    #         if cache[l][r]:
    #             return cache[l][r]
    #         ans = float('inf')
    #         # 遍历选择的数字
    #         for i in range(l, r + 1):
    #             cur = max(dfs(l, i - 1), dfs(i + 1, r)) + i
    #             ans = min(ans, cur)
    #         cache[l][r] = ans
    #         return ans

    #     cache = [[0] * 200 for _ in range(200)]
    #     return dfs(1, n)

    # 方法二: 动态规划
    def getMoneyAmount(self, n: int) -> int:
        # dp[i][j] 表示在区间 [i, j] 中选择的最小成本
        dp = [[0] * (n + 5) for _ in range(n + 5)]
        # 遍历选择次数
        for len in range(2, n + 1):
            # 遍历左端点
            for l in range(1, n - len + 2):
                r = l + len - 1
                dp[l][r] = float('inf')
                for i in range(l, r + 1):
                    cur = max(dp[l][i - 1], dp[i + 1][r]) + i
                    dp[l][r] = min(dp[l][r], cur)
        return dp[1][n]
