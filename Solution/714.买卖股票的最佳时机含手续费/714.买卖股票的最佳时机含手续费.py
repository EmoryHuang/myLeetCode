'''
Descroption: LeetCode 714. 买卖股票的最佳时机含手续费
Author: EmoryHuang
Date: 2021-10-27 20:05:43
Method:
动态规划
dp[i][0], dp[i][1] 分别表示在第 i 天不持有/持有股票的最大利润
假定在卖出股票时收取手续费
状态转移方程
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
'''


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        if n < 2:
            return 0
        # dp[i][0], dp[i][1] 分别表示在第 i 天不持有/持有股票的最大利润
        dp = [[0] * 2 for _ in range(n)]
        dp[0][0], dp[0][1] = 0, -prices[0]
        for i in range(1, n):
            # 第 i - 1 天不持有股票，第 i 天不持有股票
            # 第 i - 1 天卖出股票，第 i 天不持有股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
            # 第 i - 1 天持有股票，第 i 天持有股票
            # 第 i - 1 天买入股票，第 i 天持有股票
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        return dp[n - 1][0]
