/*
 * @Descroption: LeetCode 91. ���뷽��
 * @Author: EmoryHuang
 * @Date: 2021-04-21 12:47:36
 * @����˼·:
 * ��̬�滮���⣬�� `dp[i]` ��ʾ�ַ��� s ��ǰ i ���ַ� `s[1..i]` �Ľ��뷽����
 * �������������ʹ��һ���ַ����������ַ�������Ҫע�� 0 �Ĵ���
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