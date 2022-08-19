/*
 * @Descroption: LeetCode 730. 统计不同回文子序列
 * @Author: EmoryHuang
 * @Date: 2022-06-10 09:40:47
 * @Method:
 * 动态规划
 * 设 dp[i][j] 表示字符串从 i 到 j 的回文序列个数
 * 若 s[i] == s[j] == x, 那么对于 s[i+1, j-1] 中的任意一个回文串，都可以在头尾加上 x 组成新的回文串
 *     若 s[i+1, j-1] 中没有字符与 x 相等，则加上 xx 与 x，此时共有 2 + dp[i+1][j-1] * 2 个回文串
 *     若 s[i+1, j-1] 中有一个字符与 x 相等，则加上 xx，此时共有 1 + dp[i+1][j-1] * 2 个回文串
 *     若 s[i+1, j-1] 中有两个及以上的字符与 x 相等，则需要删除重复计算的部分，此时共有 dp[i+1][j-1] * 2 - dp[left + 1][right - 1]
 * 个回文串 其中 left 和 right 表示 s[i+1, j-1] 中与 x 相等的字符的起始和终止位置 若 s[i] != s[j], 则 dp[i][j] = dp[i+1][j] +
 * dp[i][j-1] - dp[i+1][j-1]
 */

class Solution {
   public:
    int countPalindromicSubsequences(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // 初始化单个字符
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int j = len - 1; j < n; ++j) {
                int i = j - len + 1;
                if (s[i] == s[j]) {
                    // 查找 s[i+1, j-1] 中与 s[i] 相等的字符的位置
                    int low = i + 1, high = j - 1;
                    while (low <= high && s[low] != s[j]) ++low;
                    while (low <= high && s[high] != s[j]) --high;
                    if (low > high) {
                        // s[i+1, j-1] 中没有字符与 x 相等
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % MOD;
                    } else if (low == high) {
                        // s[i+1, j-1] 中有一个字符与 x 相等
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % MOD;
                    } else {
                        // s[i+1, j-1] 中有两个及以上的字符与 x 相等
                        dp[i][j] = (0LL + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD;
                    }
                } else {
                    dp[i][j] = (0LL + dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
};