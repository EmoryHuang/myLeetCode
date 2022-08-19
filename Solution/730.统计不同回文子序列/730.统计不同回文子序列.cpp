/*
 * @Descroption: LeetCode 730. ͳ�Ʋ�ͬ����������
 * @Author: EmoryHuang
 * @Date: 2022-06-10 09:40:47
 * @Method:
 * ��̬�滮
 * �� dp[i][j] ��ʾ�ַ����� i �� j �Ļ������и���
 * �� s[i] == s[j] == x, ��ô���� s[i+1, j-1] �е�����һ�����Ĵ�����������ͷβ���� x ����µĻ��Ĵ�
 *     �� s[i+1, j-1] ��û���ַ��� x ��ȣ������ xx �� x����ʱ���� 2 + dp[i+1][j-1] * 2 �����Ĵ�
 *     �� s[i+1, j-1] ����һ���ַ��� x ��ȣ������ xx����ʱ���� 1 + dp[i+1][j-1] * 2 �����Ĵ�
 *     �� s[i+1, j-1] �������������ϵ��ַ��� x ��ȣ�����Ҫɾ���ظ�����Ĳ��֣���ʱ���� dp[i+1][j-1] * 2 - dp[left + 1][right - 1]
 * �����Ĵ� ���� left �� right ��ʾ s[i+1, j-1] ���� x ��ȵ��ַ�����ʼ����ֹλ�� �� s[i] != s[j], �� dp[i][j] = dp[i+1][j] +
 * dp[i][j-1] - dp[i+1][j-1]
 */

class Solution {
   public:
    int countPalindromicSubsequences(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // ��ʼ�������ַ�
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int j = len - 1; j < n; ++j) {
                int i = j - len + 1;
                if (s[i] == s[j]) {
                    // ���� s[i+1, j-1] ���� s[i] ��ȵ��ַ���λ��
                    int low = i + 1, high = j - 1;
                    while (low <= high && s[low] != s[j]) ++low;
                    while (low <= high && s[high] != s[j]) --high;
                    if (low > high) {
                        // s[i+1, j-1] ��û���ַ��� x ���
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % MOD;
                    } else if (low == high) {
                        // s[i+1, j-1] ����һ���ַ��� x ���
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % MOD;
                    } else {
                        // s[i+1, j-1] �������������ϵ��ַ��� x ���
                        dp[i][j] = (0LL + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD;
                    }
                } else {
                    dp[i][j] = (0LL + dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
};