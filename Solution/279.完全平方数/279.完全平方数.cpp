/*
 * @Descroption: LeetCode 279. 完全平方数
 * @Author: EmoryHuang
 * @Date: 2021-05-23 16:44:11
 * @解题思路:
 * 完全背包问题
 * dp[j]表示组成和为 j 的数的最少数量
 * 状态转移方程 dp[j] = min(dp[j], dp[j - i * i] + 1), i = 0 ... sqrt(n)
 */

class Solution {
   public:
    int numSquares(int n) {
        // dp[i]表示组成和为 i 的数的最少数量
        vector<int> dp(n + 1, 0x3f3f3f3f);  // 恰好装满的初始化
        dp[0] = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            for (int j = 0; j <= n; j++) {                  // 遍历容积
                if (j >= i * i)                              // 若不超过背包容积
                    dp[j] = min(dp[j], dp[j - i * i] + 1);  // 两种选择的最小值
            }
        }
        return dp[n];
    }
};