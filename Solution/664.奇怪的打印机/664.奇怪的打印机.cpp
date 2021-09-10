/*
 * @Descroption: LeetCode 664. 奇怪的打印机
 * @Author: EmoryHuang
 * @Date: 2021-05-24 19:22:11
 * @解题思路:
 * 动态规划
 * dp[i][j]表示打印从s[i]到s[j]需要的最少打印次数
 * 判断两边区间字符s[i],s[j]是否相等
 * 若s[i] == s[j]，则有dp[i][j] = dp[i][j - 1]，例如"aba"与"ab"的打印次数均为2
 * 若s[i] != s[j]，则需要枚举所有的可能组合，找到一个分割点k，然后取其最优解
 * dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]
 */

class Solution {
   public:
    int strangePrinter(string s) {
        int n = s.size();
        // dp[i][j]表示打印从s[i]到s[j]需要的最少打印次数
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));  // 初始化为不可达
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])  // 判断两边区间字符是否相等
                    dp[i][j] = dp[i][j - 1];
                else  // 如果不相等，则枚举所有的可能组合，找到一个分割点，然后取其最优解
                    for (int k = i; k < j; k++) 
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};