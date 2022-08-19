/*
 * @Descroption: ��ָ Offer 14- I. ������
 * @Author: EmoryHuang
 * @Date: 2021-06-30 19:58:00
 * @����˼·:
 * ��̬�滮
 * dp[i] ��ʾ������Ϊ i �������ܵõ������˻�
 * ״̬ת�Ʒ���
 * dp[i] = max(dp[i], dp[j] * dp[i - j])
 */

class Solution {
   public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        // dp[i] ��ʾ������Ϊ i �������ܵõ������˻�
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        // ����Ҫ��������
        for (int i = 4; i <= n; i++)
            // j ֻ�����һ�룬��Ϊ�Գ�
            for (int j = 1; j <= i / 2; j++) dp[i] = max(dp[i], dp[j] * dp[i - j]);
        return dp[n];
    }
};