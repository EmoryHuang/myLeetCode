/*
 * @Descroption: LeetCode 918. 环形子数组的最大和
 * @Author: EmoryHuang
 * @Date: 2021-04-27 14:46:36
 * @解题思路:
 * 不使用环：通过动态规划直接计算最大子序和，`dp[i]` 为以 `A[i]` 结尾的最大子段和。
 * 
 * 使用环：若使用到了环，则必定包含 `A[n-1]` 和 `A[0]` 两个元素，并且从 `A[1]` 到 `A[n-2]`
 * 这个子数组中必定包含负数，因此只需要把 `A[1] - A[n-2]` 间的最小和求出来，
 * 用整个数组的和 `sum` 减掉这个负数最小和即可实现环型数组的最大和
 */

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& A) {
        int len = A.size();
        vector<int> dp(len);
        dp[0] = A[0];
        int sum = A[0];        //整个数组的和
        int maxSum = INT_MIN;  //最大子序和
        for (int i = 1; i < len; i++) {
            sum += A[i];
            dp[i] = max(dp[i - 1] + A[i], A[i]);
            maxSum = max(maxSum, dp[i]);
        }
        int minSum = 0;  // A[1]-A[n-1]的最小子序和
        for (int i = 1; i < len - 1; i++) {
            dp[i] = min(dp[i - 1] + A[i], A[i]);
            minSum = min(minSum, dp[i]);
        }
        return max(sum - minSum, maxSum);
    }
};