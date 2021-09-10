/*
 * @Descroption: 剑指 Offer II 088. 爬楼梯的最少成本
 * @Author: EmoryHuang
 * @Date: 2021-08-09 20:30:44
 * @Method:
 * 动态规划
 * dp[i] 表示到第i个阶梯为止的最小花费
 * 状态转移方程：dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
 */

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        return min(dp[n - 1], dp[n - 2]);
    }
};