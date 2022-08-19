/*
 * @Descroption: LeetCode 279. ��ȫƽ����
 * @Author: EmoryHuang
 * @Date: 2021-05-23 16:44:11
 * @����˼·:
 * ��ȫ��������
 * dp[j]��ʾ��ɺ�Ϊ j ��������������
 * ״̬ת�Ʒ��� dp[j] = min(dp[j], dp[j - i * i] + 1), i = 0 ... sqrt(n)
 */

class Solution {
   public:
    int numSquares(int n) {
        // dp[i]��ʾ��ɺ�Ϊ i ��������������
        vector<int> dp(n + 1, 0x3f3f3f3f);  // ǡ��װ���ĳ�ʼ��
        dp[0] = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            for (int j = 0; j <= n; j++) {                  // �����ݻ�
                if (j >= i * i)                              // �������������ݻ�
                    dp[j] = min(dp[j], dp[j - i * i] + 1);  // ����ѡ�����Сֵ
            }
        }
        return dp[n];
    }
};