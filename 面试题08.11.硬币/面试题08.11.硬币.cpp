/*
 * @Descroption: 面试题 08.11. 硬币
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:50:05
 * @解题思路:
 * 背包问题
 * dp[j]表示和为 j 的方案总数
 * 状态转移方程：dp[j] += dp[j - coins[i]]
 */

class Solution {
   public:
    int waysToChange(int n) {
        vector<int> coins = {25, 10, 5, 1};
        vector<long> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < 4; i++)
            for (int j = coins[i]; j <= n; j++) 
                dp[j] += dp[j - coins[i]];
        return dp[n] % 1000000007;
    }
};