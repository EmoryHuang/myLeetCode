/*
 * @Descroption: LeetCode 714. 买卖股票的最佳时机含手续费
 * @Author: EmoryHuang
 * @Date: 2023-07-21 10:48:50
 * @Method:
 * 动态规划
 * dp[i][0], dp[i][1] 分别表示在第 i 天不持有/持有股票的最大利润
 * 状态转移方程：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee)
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
 */

import java.util.*;

class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
}