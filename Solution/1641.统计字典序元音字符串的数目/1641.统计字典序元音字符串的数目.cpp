/*
 * @Descroption: LeetCode 1641. ͳ���ֵ���Ԫ���ַ�������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-04-21 16:08:36
 * @����˼·:
 * ��̬�滮����
 * `dp[i]`�ֱ��ʾ�� a,e,i,o,u ��ͷ���ַ�������
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