'''
Descroption: ��ָ Offer 49. ����
Author: EmoryHuang
Date: 2021-07-04 15:01:49
����˼·:
ͨ�������жϳ����ᳬʱ

ʹ�ö�̬�滮��������������ָ��`p2`��`p3`��`p5`����`dp[0]=1`
`p2`��`p3`��`p5`�ֱ�ָ��`dp[i]`�� 2 ����3 ����5 ������
����������������`dp[n-1]`��Ϊ����
'''


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        # ά������ָ��
        p2 = p3 = p5 = 0
        dp = [0] * n
        dp[0] = 1
        for i in range(1, n):
            n2, n3, n5 = dp[p2] * 2, dp[p3] * 3, dp[p5] * 5
            dp[i] = min(n2, n3, n5)
            if dp[i] == n2:
                p2 += 1
            if dp[i] == n3:
                p3 += 1
            if dp[i] == n5:
                p5 += 1
        return dp[n - 1]
