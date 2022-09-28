/*
 * @Descroption: LeetCode 1043. 分隔数组以得到最大和
 * @Author: EmoryHuang
 * @Date: 2022-09-13 21:09:08
 * @Method:
 * 动态规划
 * dp[i]表示前i个数进行分割的最大值
 * 状态转移方程：dp[i] = max(dp[i], dp[j] + (i - j) * submax)
 */

class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int submax = -1; // 局部最大值
            for (int j = i - 1; j >= 0; j--) {
                if (i - j <= k){
                    submax = Math.max(submax, arr[j]);
                    dp[i] = Math.max(dp[i], dp[j] + (i - j) * submax);
                }
            }
        }
        return dp[n];
    }
}