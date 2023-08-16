/*
 * @Description: LeetCode 322. 零钱兑换
 * @Author: EmoryHuang
 * @Date: 2023-08-16 10:26:58
 * @解题思路:
 * 动态规划，背包问题
 * dp[i] 表示组成和为 i 的零钱的最少数量
 * dp[i] = min(dp[i], dp[i - coins[j]] + 1)
 */

import java.util.*;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < coins.length; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = Math.min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
}