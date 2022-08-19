/*
 * @Descroption: LeetCode 221. 最大正方形
 * @Author: EmoryHuang
 * @Date: 2021-05-23 15:12:11
 * @解题思路:
 * 动态规划
 * 如果该位置的值是 1，则 dp(i,j) 的值由其上方、左方和左上方的三个相邻位置的 dp 值决定
 * dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
 */

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};