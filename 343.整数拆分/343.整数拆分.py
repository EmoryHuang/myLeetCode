'''
Descroption: LeetCode 343. �������
Author: EmoryHuang
Date: 2021-06-30 19:55:00
����˼·:
��̬�滮
dp[i] ��ʾ������Ϊ i �������ܵõ������˻�
״̬ת�Ʒ���
dp[i] = max(dp[i], dp[j] * dp[i - j])
'''


class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
        # dp[i] ��ʾ������Ϊ i �������ܵõ������˻�
        dp = [0] * (n + 1)
        dp[0], dp[1], dp[2], dp[3] = 0, 1, 2, 3
        # ����Ҫ��������
        for i in range(4, n + 1):
            # j ֻ�����һ�룬��Ϊ�Գ�
            for j in range(1, i // 2 + 1):
                # ��Ϊ i �� i - j ������
                dp[i] = max(dp[i], dp[j] * dp[i - j])
        return dp[n]
