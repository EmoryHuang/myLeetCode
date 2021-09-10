'''
Descroption: LeetCode 120. 三角形最小路径和
Author: EmoryHuang
Date: 2021-07-29 14:48:42
Method:
动态规划
dp[i][j] 表示第i行j列的最小路径和
状态转移方程：dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])
'''


class Solution:
    # 经典动态规划
    # def minimumTotal(self, triangle: List[List[int]]) -> int:
    #     n = len(triangle)
    #     if n == 1:
    #         return triangle[0][0]
    #     # dp[i][j] 表示第i行j列的最小路径和
    #     dp = [[0] * n for _ in range(n)]
    #     for i, num in enumerate(triangle[-1]):
    #         dp[n - 1][i] = num
    #     for i in range(n - 2, -1, -1):
    #         for j in range(i + 1):
    #             dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])
    #     return dp[0][0]

    # 原地修改
    # def minimumTotal(self, triangle: List[List[int]]) -> int:
    #     n = len(triangle)
    #     for i in range(n - 1, 0, -1):
    #         for j in range(i):
    #             triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1])
    #     return triangle[0][0]

    # 一维空间
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        if n == 1:
            return triangle[0][0]
        dp = triangle[-1]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])
        return dp[0]