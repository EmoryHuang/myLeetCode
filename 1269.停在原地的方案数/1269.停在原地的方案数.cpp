/*
 * @Descroption: LeetCode 1269. 停在原地的方案数
 * @Author: EmoryHuang
 * @Date: 2021-05-13 14:20:36
 * @解题思路: 动态规划
 * `dp[j]` 表示在下标 `j` 处的方案数，`next`为下一步操作后的 dp
 * 不动：`next[j] = dp[j]`
 * 向右：`next[j] = dp[j - 1] + next[j]`
 * 向左：`next[j] = dp[j + 1] + next[j]`
 */

class Solution {
   public:
    const int M = 1000000007;
    int numWays(int steps, int arrLen) {
        int n = min(arrLen - 1, steps);
        vector<int> dp(n + 1);  // dp[j]表示在下标j处的方案数
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<int> next(n + 1);  //下一步操作后的dp
            for (int j = 0; j <= n; j++) {
                next[j] = dp[j];                          // 不动
                if (j - 1 >= 0) {                         // 边界
                    next[j] = (dp[j - 1] + next[j]) % M;  // 向右
                }
                if (j + 1 <= n) {                         // 边界
                    next[j] = (dp[j + 1] + next[j]) % M;  // 向左
                }
            }
            dp = next;
        }
        return dp[0];
    }
};