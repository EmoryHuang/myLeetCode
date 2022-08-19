'''
Descroption: LeetCode 309. ���������Ʊʱ�����䶳��
Author: EmoryHuang
Date: 2021-10-22 20:10:49
Method:
��̬�滮
dp[i][j] (j = 0, 1, 2), 0 ��ʾ�����й�Ʊ��1 ��ʾ���й�Ʊ��2 ��ʾ�䶳��
״̬ת�Ʒ���
dp[i][0] = max(dp[i - 1][0], dp[i - 1][2])
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
dp[i][2] = dp[i - 1][1] + prices[i]
'''


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # dp[i][0], dp[i][1], dp[i][2]
        # 0 ��ʾ�����й�Ʊ��1 ��ʾ���й�Ʊ��2 ��ʾ�䶳��
        dp = [[0] * 3 for _ in range(n)]
        dp[0][0], dp[0][1], dp[0][2] = 0, -prices[0], 0
        for i in range(1, n):
            # �� i - 1 �첻���й�Ʊ���� i �첻����
            # �� i - 1 �촦���䶳��
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2])
            # �� i- 1 ����й�Ʊ���� i �첻����
            # �� i- 1 �첻���й�Ʊ���� i ������
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
            # �� i - 1 ����й�Ʊ������
            dp[i][2] = dp[i - 1][1] + prices[i]
        return max(dp[n - 1][0], dp[n - 1][2])
