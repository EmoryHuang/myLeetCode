/*
 * @Descroption: 剑指 Offer 14- I. 剪绳子
 * @Author: EmoryHuang
 * @Date: 2021-06-30 19:58:00
 * @解题思路:
 * 动态规划
 * dp[i] 表示剪长度为 i 的绳子能得到的最大乘积
 * 状态转移方程
 * dp[i] = max(dp[i], dp[j] * dp[i - j])
 */

class Solution {
   public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        // dp[i] 表示剪长度为 i 的绳子能得到的最大乘积
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        // 遍历要剪的绳子
        for (int i = 4; i <= n; i++)
            // j 只需遍历一半，因为对称
            for (int j = 1; j <= i / 2; j++) dp[i] = max(dp[i], dp[j] * dp[i - j]);
        return dp[n];
    }
};