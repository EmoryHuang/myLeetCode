/*
 * @Descroption: LeetCode 664. ��ֵĴ�ӡ��
 * @Author: EmoryHuang
 * @Date: 2021-05-24 19:22:11
 * @����˼·:
 * ��̬�滮
 * dp[i][j]��ʾ��ӡ��s[i]��s[j]��Ҫ�����ٴ�ӡ����
 * �ж����������ַ�s[i],s[j]�Ƿ����
 * ��s[i] == s[j]������dp[i][j] = dp[i][j - 1]������"aba"��"ab"�Ĵ�ӡ������Ϊ2
 * ��s[i] != s[j]������Ҫö�����еĿ�����ϣ��ҵ�һ���ָ��k��Ȼ��ȡ�����Ž�
 * dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]
 */

class Solution {
   public:
    int strangePrinter(string s) {
        int n = s.size();
        // dp[i][j]��ʾ��ӡ��s[i]��s[j]��Ҫ�����ٴ�ӡ����
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));  // ��ʼ��Ϊ���ɴ�
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])  // �ж����������ַ��Ƿ����
                    dp[i][j] = dp[i][j - 1];
                else  // �������ȣ���ö�����еĿ�����ϣ��ҵ�һ���ָ�㣬Ȼ��ȡ�����Ž�
                    for (int k = i; k < j; k++) 
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};