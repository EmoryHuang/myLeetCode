/*
 * @Descroption: LeetCode 139. 单词拆分
 * @Author: EmoryHuang
 * @Date: 2021-05-13 15:07:36
 * @解题思路: 动态规划
 * `dp[i]` 表示符串 `s` 前 `i` 个字符组成的字符串能否拆分
 * 具体来说枚举前 `i` 个字符串的分割点 `j`，判断字符串能否拆分
 */

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};