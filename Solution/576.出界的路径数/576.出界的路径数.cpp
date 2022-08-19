/*
 * @Descroption: LeetCode 576. 出界的路径数
 * @Author: EmoryHuang
 * @Date: 2021-08-15 12:10:15
 * @Method:
 * 动态规划
 * 刚开始没想直接dfs,然而超时了...
 * dp[i][j][k]表示(i,j)位置上k步内移除边界的路径数
 * 状态转移方程
 * dp[i][j][k] = dp[i-1][j][k-1] + dp[i+1][j][k-1] + dp[i][j-1][k-1] + dp[i][j+1][k-1]
 */

class Solution {
   public:
    // 无空间优化
    // int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    //     if (maxMove == 0) return 0;
    //     vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1)));
    //     vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    //     for (int k = 1; k <= maxMove; ++k) {
    //         for (int x = 0; x < m; ++x) {
    //             for (int y = 0; y < n; ++y) {
    //                 for (int i = 0; i < 4; i++) {
    //                     int newx = x + dx[i], newy = y + dy[i];
    //                     if (newx < 0 || newy < 0 || newx >= m || newy >= n)
    //                         dp[x][y][k]++;
    //                     else
    //                         dp[x][y][k] = (dp[x][y][k] + dp[newx][newy][k - 1]) % 1000000007;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[startRow][startColumn][maxMove];
    // }

    // 空间优化
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n));
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        for (int k = 1; k <= maxMove; ++k) {
            // 保存第 k-1 步的结果
            vector<vector<int>> tmp(m, vector<int>(n));
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    for (int i = 0; i < 4; i++) {
                        int newx = x + dx[i], newy = y + dy[i];
                        if (newx < 0 || newy < 0 || newx >= m || newy >= n)
                            tmp[x][y]++;
                        else
                            tmp[x][y] = (tmp[x][y] + dp[newx][newy]) % 1000000007;
                    }
                }
            }
            dp = tmp;
        }
        return dp[startRow][startColumn];
    }
};