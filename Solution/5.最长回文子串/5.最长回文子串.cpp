/*
 * @Descroption: LeetCode 5. 最长回文子串
 * @Author: EmoryHuang
 * @Date: 2021-03-17 17:20:36
 * @解题思路: 首先是暴力算法，遍历每个子串，判断其是否为回文串，但 c++会超时
 * 这里使用动态规划，`dp[i][j]` 表示 `s[i]` 到 `s[j]` 所表示的串是否为回文串，是则为 1，否则为 0
 * 若 `s[i] == s[j]` ，那么只要 `s[i+1] `到` s[j-1]` 是回文串， `s[i]` 到 `s[j]`所表示的串就为回文串
 * 若 `s[i] != s[j]` ，那么 `s[i]` 到 `s[j]` 所表示的串就不是回文串
 * dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1])
 * dp[i][j] = (s[i] == s[j]) ? 1 : 0
 * 边界：`dp[i][i]=1`,`dp[i][i+1]=(s[i]==s[i+1])?1:0`
 */

class Solution {
   public:
    string longestPalindrome(string s) {
        int len = s.size();
        string ans;
        vector<vector<int>> dp(len, vector<int>(len));
        for (int l = 0; l < len; l++) {          //遍历子串长度
            for (int i = 0; i + l < len; i++) {  //遍历起点位置
                int j = i + l;                   //右端点位置
                if (l == 0)
                    dp[i][j] = 1;  //边界，不是回文串
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]) ? 1 : 0;  //边界，不是回文串
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);  //回文子串
                }
            }
        }
        return ans;
    }
};