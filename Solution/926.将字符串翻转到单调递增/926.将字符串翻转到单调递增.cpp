/*
 * @Descroption: LeetCode 926. ���ַ�����ת����������
 * @Author: EmoryHuang
 * @Date: 2022-06-11 09:25:47
 * @Method:
 * ��̬�滮
 * dp[i][0] ��ʾ�� i ���ַ�Ϊ 0 ʱ s[0,i] ��Ҫ����С��ת����
 * dp[i][1] ��ʾ�� i ���ַ�Ϊ 1 ʱ s[0,i] ��Ҫ����С��ת����
 * ״̬ת�Ʒ���
 * dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + s[i] == '0' ? 1 : 0
 * dp[i][0] = dp[i-1][0] + s[i] == '1' ? 1 : 0
 */

class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for (auto c : s) {
            dp1 = min(dp0, dp1) + (c == '0' ? 1 : 0);
            dp0 = dp0 + (c == '1' ? 1 : 0);
        }
        return min(dp0, dp1);
    }
};