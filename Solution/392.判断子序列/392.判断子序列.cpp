/*
 * @Descroption: LeetCode 392. 判断子序列
 * @Author: EmoryHuang
 * @Date: 2021-05-20 20:33:37
 * @解题思路:
 * 方法一：双指针
 * 由于字符不改变相对位置，那么就利用双指针同时遍历
 *
 * 方法二：动态规划
 * dp[i][j]表示字符串 s 的前 i 个元素和字符串 t 的前 j 个元素中公共子序列的长度
 * 若 s[i - 1] == t[j - 1] 那么长度加1 dp[i][j] = d[i - 1][j - 1] + 1
 * 若 s[i - 1] != t[j - 1] 那么使用之前的长度 dp[i][j] = dp[i][j - 1]
 */

class Solution {
   public:
    // 方法一：双指针
    // bool isSubsequence(string s, string t) {
    //     int n = s.size(), m = t.size();
    //     int i = 0, j = 0;
    //     while (i < n && j < m) {
    //         if (s[i] == t[j]) i++;
    //         j++;
    //     }
    //     return i == n;
    // }

    // 方法二：动态规划
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
        return dp[n][m] == n;
    }
};