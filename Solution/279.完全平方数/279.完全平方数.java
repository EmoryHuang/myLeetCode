/*
 * @Description: LeetCode 279. 完全平方数
 * @Author: EmoryHuang
 * @Date: 2023-08-16 10:10:20
 * @解题思路:
 * 动态规划，背包问题
 * dp[i] 表示和为 i 的完全平方数的最少数量
 * dp[i] = min(dp[i], dp[i - j * j] + 1)
 */

import java.util.*;

class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 0x3f3f3f3f);
        dp[0] = 0;
        for (int j = 1; j <= Math.sqrt(n); j++) {
            for (int i = 1; i <= n; i++) {
                if (i >= j * j) {
                    dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
}