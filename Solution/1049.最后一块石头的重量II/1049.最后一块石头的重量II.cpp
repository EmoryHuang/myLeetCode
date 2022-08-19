/*
 * @Descroption: LeetCode 1049. 最后一块石头的重量 II
 * @Author: EmoryHuang
 * @Date: 2021-06-08 15:28:00
 * @解题思路:
 * 01背包问题
 * dp[j]表示容量为j的背包最多可以放的石头重量
 * 该题可以抽象为将 n 块石头分为两堆，而后求两堆石头重量总和的最小差值
 * 具体来说，从 stones 数组中选择，凑成总和不超过 sum/2 的最大价值。
 */

class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones) sum += stone;
        // dp[j]表示容量为j的背包最多可以放的石头重量
        // 背包容量上限为石头总重量的一半
        vector<int> dp(sum / 2 + 1);
        for (int stone : stones) {
            for (int j = sum / 2; j >= stone; j--) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }
        return sum - dp[sum / 2] * 2;
    }
};