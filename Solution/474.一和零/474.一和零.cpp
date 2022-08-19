/*
 * @Descroption: LeetCode 474. һ����
 * @Author: EmoryHuang
 * @Date: 2021-06-06 15:07:00
 * @����˼·:
 * 0-1 �������⣬�� m �� n �������
 * dp[i][j]��ʾ�� i �� 0 �� j �� 1 ʱ����Ӽ���С
 * ״̬ת�Ʒ��̣�dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1)
 */

class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j]��ʾ��i��0��j��1ʱ����Ӽ���С
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto str : strs) {
            int cnt0 = 0, cnt1 = 0;
            for (auto c : str) {
                if (c == '0') cnt0++;
                if (c == '1') cnt1++;
            }
            for (int i = m; i >= cnt0; i--)
                for (int j = n; j >= cnt1; j--)
                    dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
        }
        return dp[m][n];
    }
};