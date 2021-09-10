/*
 * @Descroption: LeetCode 64. 最小路径和
 * @Author: EmoryHuang
 * @Date: 2021-03-23 17:01:36
 * @解题思路:动态规划
 * （i，j）可以通过（i-1，j）和（i，j-1）到达，可以得到，因此选择`dp[i - 1][j]` 和 `dp[i][j - 1]`
 * 中较小的一个，再加上（i，j）即可
 */

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};