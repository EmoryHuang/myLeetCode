'''
Descroption: LeetCode 714. ������Ʊ�����ʱ����������
Author: EmoryHuang
Date: 2021-10-27 20:05:43
Method:
��̬�滮
dp[i][0], dp[i][1] �ֱ��ʾ�ڵ� i �첻����/���й�Ʊ���������
�ٶ���������Ʊʱ��ȡ������
״̬ת�Ʒ���
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
'''


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        if n < 2:
            return 0
        # dp[i][0], dp[i][1] �ֱ��ʾ�ڵ� i �첻����/���й�Ʊ���������
        dp = [[0] * 2 for _ in range(n)]
        dp[0][0], dp[0][1] = 0, -prices[0]
        for i in range(1, n):
            # �� i - 1 �첻���й�Ʊ���� i �첻���й�Ʊ
            # �� i - 1 ��������Ʊ���� i �첻���й�Ʊ
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
            # �� i - 1 ����й�Ʊ���� i ����й�Ʊ
            # �� i - 1 �������Ʊ���� i ����й�Ʊ
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        return dp[n - 1][0]
