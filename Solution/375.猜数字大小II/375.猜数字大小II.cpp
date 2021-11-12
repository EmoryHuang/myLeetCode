/*
 * @Descroption: LeetCode 375. 猜数字大小 II
 * @Author: EmoryHuang
 * @Date: 2021-11-12 19:27:40
 * @Method:
 * 方法一: dfs
 * 递归得到当前区间下选择数字的最坏情况下最好的结果
 *
 * 方法二: 动态规划
 * dp[i][j] 表示在区间 [i, j] 中选择的最小成本
 * cur = max(dp[l][i - 1], dp[i + 1][r]) + i
 */

class Solution {
   public:
    // 方法一: dfs
    // vector<vector<int>> cache;
    // int dfs(int l, int r) {
    //     if (l >= r) return 0;
    //     if (cache[l][r]) return cache[l][r];
    //     int ans = INT_MAX;
    //     // 遍历选择的数字
    //     for (int i = l; i <= r; i++) {
    //         int cur = max(dfs(l, i - 1), dfs(i + 1, r)) + i;
    //         ans = min(ans, cur);
    //     }
    //     cache[l][r] = ans;
    //     return ans;
    // }
    // int getMoneyAmount(int n) {
    //     cache.resize(201, vector<int>(201));
    //     return dfs(1, n);
    // }

    // 方法二: 动态规划
    int getMoneyAmount(int n) {
        // dp[i][j] 表示在区间 [i, j] 中选择的最小成本
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        // 遍历选择长度
        for (int len = 2; len <= n; len++) {
            // 遍历左端点
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                dp[l][r] = 0x3f3f3f3f;
                for (int i = l; i <= r; i++) {
                    int cur = max(dp[l][i - 1], dp[i + 1][r]) + i;
                    dp[l][r] = min(dp[l][r], cur);
                }
            }
        }
        return dp[1][n];
    }
};