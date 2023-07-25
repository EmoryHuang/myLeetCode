/*
 * @Descroption: LeetCode 62. 不同路径
 * @Author: EmoryHuang
 * @Date: 2023-07-21 10:35:20
 * @Method:
 * 动态规划
 * 状态转移方程：
 * dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
 */

import java.util.*;

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
}