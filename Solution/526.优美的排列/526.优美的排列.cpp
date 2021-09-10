/*
 * @Descroption: LeetCode 526. 优美的排列
 * @Author: EmoryHuang
 * @Date: 2021-08-16 16:29:44
 * @Method:
 * 方法一：状态压缩 + 回溯
 * 使用二进制串记录数字的访问状态
 * 回溯法进行深度优先遍历，直到访问完所有数
 *
 * 方法二：状态压缩 + dp
 * dp[i][state] 表示前i个数状态为state的方案数
 * 枚举i个数,这i个数的状态state以及第i个数的值k
 * 状态转移方程：dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))]
 * 其中，state & (~(1 << (k - 1))) 将 state 中的第 k 位置 0，也就是未选取 k 时的状态
 */

class Solution {
   public:
    // 方法一：状态压缩 + 回溯
    // int dfs(int n, int i, int vis) {
    //     if (vis == (1 << n) - 1) return 1;
    //     int ans = 0;
    //     for (int ind = 0; ind < n; ind++) {
    //         // 跳过已访问过的数
    //         if ((1 << ind) & vis) continue;
    //         // 如果是优美的排列
    //         if (i % (ind + 1) == 0 || (ind + 1) % i == 0) {
    //             vis ^= (1 << ind);
    //             ans += dfs(n, i + 1, vis);
    //             vis ^= (1 << ind);
    //         }
    //     }
    //     return ans;
    // }
    // int countArrangement(int n) {
    //     return dfs(n, 1, 0);
    // }

    // 方法二：状态压缩 + dp
    int countArrangement(int n) {
        int mask = 1 << n;
        // dp[i][state] 表示前i个数状态为state的方案数
        vector<vector<long>> dp(n + 1, vector<long>(mask));
        dp[0][0] = 1;
        // 遍历所有位置
        for (int i = 1; i <= n; i++) {
            // 遍历所有状态
            for (int state = 0; state < mask; state++) {
                // 遍历位置 i 的数 k
                for (int k = 1; k <= n; k++) {
                    // 位置 k 必须是 1
                    if ((state >> (k - 1)) & 1 == 0) continue;
                    if (i % k != 0 && k % i != 0) continue;
                    // state & (~(1 << (k - 1))) 表示将 state 中的第 k 位置 0
                    // 也就是未选取 k 时的状态
                    dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))];
                }
            }
        }
        return dp[n][mask - 1];
    }
};