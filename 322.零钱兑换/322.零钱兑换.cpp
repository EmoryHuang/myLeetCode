/*
 * @Descroption: LeetCode 322. 零钱兑换
 * @Author: EmoryHuang
 * @Date: 2021-05-20 16:20:51
 * @解题思路:
 * 动态规划问题，背包问题
 * dp[i] 表示组成金额为 i 的最少硬币个数
 * 状态转移方程：dp[i] = min(dp[i], dp[i - coin] + 1)
 * 由于需要金额恰好为 amount，因此初始化时将dp[0]=0外，其他均初始化为INT_MAX
 */

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0x3f3f3f3f);  // 初始化为INT_MAX
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {  // 遍历金额
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) 
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] != 0x3f3f3f3f ? dp[amount] : -1;
    }
};