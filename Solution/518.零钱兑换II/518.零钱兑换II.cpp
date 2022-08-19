/*
 * @Descroption: LeetCode 518. 零钱兑换 II
 * @Author: EmoryHuang
 * @Date: 2021-05-30 17:53:00
 * @解题思路:
 * 完全背包问题
 * dp[j]表示总金额为 j 的硬币组合总数
 * 状态转移方程
 * dp[j] = dp[j] + dp[j - coin]
 */

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[j]表示总金额为 j 的硬币组合总数
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};