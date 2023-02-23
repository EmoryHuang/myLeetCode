/*
 * @Descroption: LeetCode 813. 最大平均值和的分组
 * @Author: EmoryHuang
 * @Date: 2022-11-28 09:38:47
 * @Method:
 * 前缀和 + 动态规划
 * 类似背包问题，将 n 个数分为 k 份
 */

class Solution {
    public double largestSumOfAverages(int[] nums, int k) {
        int n = nums.length;
        double[] pre = new double[n + 1];
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        double[] dp = new double[n + 1];
        for (int i = 1; i <= n; i++) {
            dp[i] = pre[i] / i;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = n; i >= j; i--) {
                for (int x = j - 1; x < i; x++) {
                    dp[i] = Math.max(dp[i], dp[x] + (pre[i] - pre[x]) / (i - x));
                }
            }
        }
        return dp[n];
    }
}