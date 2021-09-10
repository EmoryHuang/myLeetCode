/*
 * @Descroption: LeetCode 139. ���ʲ��
 * @Author: EmoryHuang
 * @Date: 2021-05-13 15:07:36
 * @����˼·: ��̬�滮
 * `dp[i]` ��ʾ���� `s` ǰ `i` ���ַ���ɵ��ַ����ܷ���
 * ������˵ö��ǰ `i` ���ַ����ķָ�� `j`���ж��ַ����ܷ���
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