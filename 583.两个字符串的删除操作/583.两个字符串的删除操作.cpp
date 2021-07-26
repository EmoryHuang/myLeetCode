/*
 * @Descroption: LeetCode 583. 两个字符串的删除操作
 * @Author: EmoryHuang
 * @Date: 2021-07-26 15:05:33
 * @Method:
 * 本质上就是求最长公共子串
 */

class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return m + n - 2 * dp[n][m];
    }
};