/*
 * @Descroption: LeetCode 552. 学生出勤记录 II
 * @Author: EmoryHuang
 * @Date: 2021-08-18 19:07:32
 * @Method:
 * 方法一：dfs + 记忆化搜索
 * 暴力搜索
 * 方法二：动态规划
 * dp[i][j][k]表示第i天，在缺席了j次，以及连续迟到了k次的情况下，还可以拿到奖励的出席排列的数量。
 * j∈{0,1}  k∈{0,1,2}，因此 dp[i][j][k]一共有六种
 * 状态转移方程
 * dp[i][0][0] += dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]
 * dp[i][0][1] += dp[i-1][0][0]
 * dp[i][0][2] += dp[i-1][0][1]
 * dp[i][1][0] += dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]
 * dp[i][1][1] += dp[i-1][1][0]
 * dp[i][1][2] += dp[i-1][1][1]
 */

class Solution {
   public:
    // 方法一：dfs + 记忆化搜索
    // int dfs(vector<vector<vector<int>>>& cache, int r, int acnt, int lcnt) {
    //     if (acnt >= 2 || lcnt >= 3) return 0;
    //     if (r == 0) return 1;
    //     if (cache[r][acnt][lcnt] != -1) return cache[r][acnt][lcnt];
    //     int ans = 0;
    //     int mod = 1000000007;
    //     ans = dfs(cache, r - 1, acnt + 1, 0) % mod;             // A
    //     ans = (ans + dfs(cache, r - 1, acnt, lcnt + 1)) % mod;  // L
    //     ans = (ans + dfs(cache, r - 1, acnt, 0)) % mod;         // P
    //     cache[r][acnt][lcnt] = ans;
    //     return ans;
    // }
    // int checkRecord(int n) {
    //     vector<vector<vector<int>>> cache(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    //     return dfs(cache, n, 0, 0);
    // }

    // 方法二：动态规划
    int checkRecord(int n) {
        // dp[i][j][k]表示第i天，在缺席了j次，以及连续迟到了k次的情况下，
        // 还可以拿到奖励的出席排列的数量。
        // j∈{0,1}  k∈{0,1,2}
        // 因此 dp[i][j][k]一共有六种
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        int mod = 1000000007;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == 1 && k == 0) {  // A
                        // 共1种情况 (1,0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][0]) % mod;
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][1]) % mod;
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][2]) % mod;
                    }
                    if (k != 0)  // L
                        // 共4种情况 (0,1),(0,2),(1,1),(1,2)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
                    if (k == 0) {  // P
                        // 共1种情况 (0,0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][0]) % mod;
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][1]) % mod;
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][2]) % mod;
                    }
                }
            }
        }
        long ans = 0;
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 3; k++) ans += dp[n][j][k];
        return ans % mod;
    }
};