/*
 * @Descroption: LeetCode 474. 一和零
 * @Author: EmoryHuang
 * @Date: 2021-06-06 15:07:00
 * @解题思路:
 * 0-1 背包问题，有 m 和 n 两个体积
 * dp[i][j]表示有 i 个 0 和 j 个 1 时最大子集大小
 * 状态转移方程：dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1)
 */

class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j]表示有i个0和j个1时最大子集大小
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto str : strs) {
            int cnt0 = 0, cnt1 = 0;
            for (auto c : str) {
                if (c == '0') cnt0++;
                if (c == '1') cnt1++;
            }
            for (int i = m; i >= cnt0; i--)
                for (int j = n; j >= cnt1; j--)
                    dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
        }
        return dp[m][n];
    }
};