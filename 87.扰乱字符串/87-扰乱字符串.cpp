/*
 * @Descroption: LeetCode 87. �����ַ���
 * @Author: EmoryHuang
 * @Date: 2021-04-16 18:43:36
 * @����˼·: ����Ķ�̬�滮
 * `dp[i][j][len]` ��ʾ���ַ��� S1 �� i ��ʼ����Ϊ len ���ַ����Ƿ��ܱ任Ϊ
 * ���ַ��� s2 �� j ��ʼ����Ϊ len ���ַ���
 */

class Solution {
   public:
    bool isScramble(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (n != m) return false;
        int dp[30][30][31] = {0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        // ö�����䳤��
        for (int len = 2; len <= n; len++) {
            // ö��s1�е����λ��
            for (int i = 0; i <= n - len; i++) {
                // ö��s2�е����λ��
                for (int j = 0; j <= n - len; j++) {
                    // ö�ٻ���λ��
                    for (int k = 1; k <= len - 1; k++) {
                        // ����
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                        // ������
                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};