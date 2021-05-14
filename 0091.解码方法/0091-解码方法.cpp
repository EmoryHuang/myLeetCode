/*
 * @Descroption: LeetCode 91. 解码方法
 * @Author: EmoryHuang
 * @Date: 2021-04-21 12:47:36
 * @解题思路:
 * 动态规划问题，设 `dp[i]` 表示字符串 s 的前 i 个字符 `s[1..i]` 的解码方法数
 * 考虑两种情况，使用一个字符或者两个字符，其中要注意 0 的处理
 */

class Solution {
   public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len + 1);
        dp[0] = 1;
        for (int i = 1; i <= len; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[len];
    }
};