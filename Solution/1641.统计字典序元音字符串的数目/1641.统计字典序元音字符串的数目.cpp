/*
 * @Descroption: LeetCode 1641. 统计字典序元音字符串的数目
 * @Author: EmoryHuang
 * @Date: 2021-04-21 16:08:36
 * @解题思路:
 * 动态规划问题
 * `dp[i]`分别表示以 a,e,i,o,u 开头的字符串数量
 */

class Solution {
   public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for (int i = 1; i < n; i++) {
            dp[0] = dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
            dp[1] = dp[1] + dp[2] + dp[3] + dp[4];
            dp[2] = dp[2] + dp[3] + dp[4];
            dp[3] = dp[3] + dp[4];
        }
        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};