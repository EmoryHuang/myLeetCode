/*
 * @Descroption: LeetCode 931. 下降路径最小和
 * @Author: EmoryHuang
 * @Date: 2021-09-18 19:34:30
 * @Method:
 * 动态规划
 * 经典求路径和问题，正向，反向都可以
 * 状态转移方程：dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1])
 */

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[0][i] = matrix[0][i];
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                else if (j == n - 1)
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                else
                    dp[i][j] = matrix[i][j] + min(min(dp[i - 1][j], dp[i - 1][j + 1]), dp[i - 1][j - 1]);
            }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};