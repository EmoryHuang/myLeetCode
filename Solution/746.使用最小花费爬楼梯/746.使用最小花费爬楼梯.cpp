/*
 * @Descroption: LeetCode 746. 使用最小花费爬楼梯
 * @Author: EmoryHuang
 * @Date: 2021-06-03 16:28:00
 * @解题思路:
 * 动态规划
 * dp[i] 表示达到下标 i 的最小花费
 * 由于可以选择下标 0 或 1 作为初始阶梯，因此有 dp[0] = dp[1] = 0
 * 状态转移方程：dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
 */

class Solution {
   public:
    // 空间复杂度：O(n)
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n + 1);
    //     dp[0] = dp[1] = 0;
    //     for (int i = 2; i <= n; i++)
    //         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    //     return dp[n];
    // }

    // 空间复杂度：O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int pre = 0, cur = 0;
        for (int i = 2; i <= n; i++) {
            int next = min(pre + cost[i - 2], cur + cost[i - 1]);
            pre = cur;
            cur = next;
        }
        return cur;
    }
};