/*
 * @Descroption: LeetCode 787. K 站中转内最便宜的航班
 * @Author: EmoryHuang
 * @Date: 2021-08-24 10:56:44
 * @Method:
 * 动态规划
 * dp[i][k]表示经过k个中转站后到达站i的最低费用
 * 状态转移方程：dp[v][k] = min(dp[v][k], dp[u][k - 1] + p);
 */

class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // dp[i][k]表示经过k个中转站后到达站i的最低费用
        vector<int> dp(n, 0x3f3f3f3f);
        dp[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> tmp = dp;
            for (auto f : flights) {
                int u = f[0], v = f[1], p = f[2];
                // dp[v][k] = min(dp[v][k], dp[u][k - 1] + p);
                dp[v] = min(dp[v], tmp[u] + p);
            }
        }
        return dp[dst] == 0x3f3f3f3f ? -1 : dp[dst];
    }
};