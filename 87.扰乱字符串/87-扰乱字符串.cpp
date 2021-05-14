/*
 * @Descroption: LeetCode 87. 扰乱字符串
 * @Author: EmoryHuang
 * @Date: 2021-04-16 18:43:36
 * @解题思路: 区间的动态规划
 * `dp[i][j][len]` 表示从字符串 S1 中 i 开始长度为 len 的字符串是否能变换为
 * 从字符串 s2 中 j 开始长度为 len 的字符串
 */

class Solution {
   public:
    bool isScramble(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (n != m) return false;
        int dp[30][30][31] = {0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        // 枚举区间长度
        for (int len = 2; len <= n; len++) {
            // 枚举s1中的起点位置
            for (int i = 0; i <= n - len; i++) {
                // 枚举s2中的起点位置
                for (int j = 0; j <= n - len; j++) {
                    // 枚举划分位置
                    for (int k = 1; k <= len - 1; k++) {
                        // 交换
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                        // 不交换
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};