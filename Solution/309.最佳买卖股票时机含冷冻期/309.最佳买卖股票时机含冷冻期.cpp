/*
 * @Descroption: LeetCode 309. 最佳买卖股票时机含冷冻期
 * @Author: EmoryHuang
 * @Date: 2021-10-22 20:15:19
 * @Method:
 * 动态规划
 * dp[i][j] (j = 0, 1, 2), 0 表示不持有股票，1 表示持有股票，2 表示冷冻期
 * 状态转移方程
 * dp[i][0] = max(dp[i - 1][0], dp[i - 1][2])
 * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
 * dp[i][2] = dp[i - 1][1] + prices[i]
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][0], dp[i][1], dp[i][2]
        // 0 表示不持有股票，1 表示持有股票，2 表示冷冻期
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = 0, dp[0][1] = -prices[0], dp[0][2] = 0;
        for (int i = 1; i < n; i++) {
            // 第 i - 1 天不持有股票，第 i 天不操作
            // 第 i - 1 天处于冷冻期，第 i 天不操作
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            // 第 i- 1 天持有股票，第 i 天不操作
            // 第 i- 1 天不持有股票，第 i 天买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            // 第 i - 1 天持有股票且卖出
            dp[i][2] = dp[i - 1][1] + prices[i];
        }
        return max(dp[n - 1][0], dp[n - 1][2]);
    }
};