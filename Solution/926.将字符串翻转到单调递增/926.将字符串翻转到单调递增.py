'''
Descroption: LeetCode 926. ���ַ�����ת����������
Author: EmoryHuang
Date: 2022-06-11 09:23:57
Method:
��̬�滮
dp[i][0] ��ʾ�� i ���ַ�Ϊ 0 ʱ s[0,i] ��Ҫ����С��ת����
dp[i][1] ��ʾ�� i ���ַ�Ϊ 1 ʱ s[0,i] ��Ҫ����С��ת����
״̬ת�Ʒ���
dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + s[i] == '0' ? 1 : 0
dp[i][0] = dp[i-1][0] + s[i] == '1' ? 1 : 0
'''


class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        # dp[i][0] ��ʾ�� i ���ַ�Ϊ 0 ʱ s[0,i] ��Ҫ����С��ת����
        # dp[i][1] ��ʾ�� i ���ַ�Ϊ 1 ʱ s[0,i] ��Ҫ����С��ת����
        # ״̬ת�Ʒ���
        # dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + s[i] == '0' ? 1 : 0
        # dp[i][0] = dp[i-1][0] + s[i] == '1' ? 1 : 0

        # ״̬ѹ��
        # dp0 ��ʾ��βΪ 0 ���ַ�����Ҫ����С��ת������dp1 ��ʾ��βΪ 1
        dp0, dp1 = 0, 0
        for c in s:
            dp1 = min(dp0, dp1) + (c == '0')
            dp0 = dp0 + (c == '1')
        return min(dp0, dp1)