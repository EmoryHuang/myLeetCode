/*
 * @Descroption: 剑指 Offer 47. 礼物的最大价值
 * @Author: EmoryHuang
 * @Date: 2021-08-09 14:18:34
 * @Method:
 * 动态规划
 * 状态转移方程
 * dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1])
 */

class Solution {
   public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        vector<int> dp(n + 1);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                // dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
                dp[j] = grid[i - 1][j - 1] + max(dp[j], dp[j - 1]);
        // return dp[m][n];
        return dp[n];
    }
};