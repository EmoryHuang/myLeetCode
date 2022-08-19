/*
 * @Descroption: LeetCode 392. �ж�������
 * @Author: EmoryHuang
 * @Date: 2021-05-20 20:33:37
 * @����˼·:
 * ����һ��˫ָ��
 * �����ַ����ı����λ�ã���ô������˫ָ��ͬʱ����
 *
 * ����������̬�滮
 * dp[i][j]��ʾ�ַ��� s ��ǰ i ��Ԫ�غ��ַ��� t ��ǰ j ��Ԫ���й��������еĳ���
 * �� s[i - 1] == t[j - 1] ��ô���ȼ�1 dp[i][j] = d[i - 1][j - 1] + 1
 * �� s[i - 1] != t[j - 1] ��ôʹ��֮ǰ�ĳ��� dp[i][j] = dp[i][j - 1]
 */

class Solution {
   public:
    // ����һ��˫ָ��
    // bool isSubsequence(string s, string t) {
    //     int n = s.size(), m = t.size();
    //     int i = 0, j = 0;
    //     while (i < n && j < m) {
    //         if (s[i] == t[j]) i++;
    //         j++;
    //     }
    //     return i == n;
    // }

    // ����������̬�滮
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
        return dp[n][m] == n;
    }
};