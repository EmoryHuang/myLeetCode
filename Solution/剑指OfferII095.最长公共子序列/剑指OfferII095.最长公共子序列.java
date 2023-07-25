/*
 * @Descroption: LeetCode 1143. 最长公共子序列
 * @Author: EmoryHuang
 * @Date: 2023-07-21 10:41:45
 * @Method:
 * 动态规划
 * dp[i][j] 表示text1[:i], text2[:j] 的最长公共子序列
 * 状态转移方程：
 * dp[i][j] = dp[i-1][j-1] + 1 if text1[i] == text2[j] else dp[i][j] = max(dp[i][j-1], dp[i-1][j])
 */

import java.util.*;

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        if (m == 0 || n == 0) {
            return 0;
        }
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
}