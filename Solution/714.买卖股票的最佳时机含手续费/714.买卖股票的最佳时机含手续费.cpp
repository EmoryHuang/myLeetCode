/*
 * @Descroption: LeetCode 714. ������Ʊ�����ʱ����������
 * @Author: EmoryHuang
 * @Date: 2021-10-27 20:10:35
 * @Method:
 * ��̬�滮
 * dp[i][0], dp[i][1] �ֱ��ʾ�ڵ� i �첻����/���й�Ʊ���������
 * �ٶ���������Ʊʱ��ȡ������
 * ״̬ת�Ʒ���
 * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
 * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) return 0;
        // dp[i][0], dp[i][1] �ֱ��ʾ�ڵ� i �첻����/���й�Ʊ���������
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            // �� i - 1 �첻���й�Ʊ���� i �첻���й�Ʊ
            // �� i - 1 ��������Ʊ���� i �첻���й�Ʊ
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            // �� i - 1 ����й�Ʊ���� i ����й�Ʊ
            // �� i - 1 �������Ʊ���� i ����й�Ʊ
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};