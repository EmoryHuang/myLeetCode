/*
 * @Descroption: LeetCode 516. �����������
 * @Author: EmoryHuang
 * @Date: 2021-07-27 20:12:42
 * @Method:
 * ��̬�滮
 * dp[i][j] ��ʾ s �ĵ� i ���ַ����� j ���ַ���ɵ��Ӵ��У���Ļ������г���
 * ״̬ת�Ʒ��̣�
 * �� s[i] == s[j] �� dp[i][j] = dp[i + 1][j - 1] + 2
 * �� s[i] != s[j] �� dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
 */

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};