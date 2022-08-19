'''
Descroption: LeetCode 639. ���뷽�� II
Author: EmoryHuang
Date: 2021-09-27 19:23:54
Method:
��̬�滮
dp[i]��ʾǰi���ַ��Ľ��뷽����
dp[i] = �� * dp[i-1] + �� * dp[i-2]
�ֱ���һλ������λ���Ľ��뷽��
���뵥���ַ����ֳ� 0��1~9��* ���ֱ�����
���������ַ����ֳ� **��*X��X*��XX ���ֱ�����
'''


class Solution:
    def numDecodings(self, s: str) -> int:
        def decode1(c: str):
            # ���뵥���ַ�
            if c == '0':
                return 0
            elif c == '*':
                return 9  # [1 - 9]
            return 1

        def decode2(c1: str, c2: str):
            if c1 == c2 == '*':
                return 15  # [11 - 19] and [21 - 26] �� 15 �ֿ���
            if c1 == '*':
                if c2 <= '6':
                    return 2  # c1 == 1 �� c1 == 2
                return 1  # c1 == 1
            if c2 == '*':
                if c1 == '1':
                    return 9  # c2 == 1 - 9
                elif c1 == '2':
                    return 6  # c2 == 1 - 6
                return 0
            sum = int(c1) * 10 + int(c2)
            if 10 <= sum <= 26:
                return 1
            return 0

        # dp[i]��ʾǰi���ַ��Ľ��뷽����
        # a = f[i-2], b = f[i-1], c = f[i]
        a, b, c = 0, 1, 0
        for i in range(1, len(s) + 1):
            # ����һλ���Ľ��뷽��
            c = decode1(s[i - 1]) * b
            if i > 1:
                # ������λ���Ľ��뷽��
                c += decode2(s[i - 2], s[i - 1]) * a
            c %= 10**9 + 7
            a, b = b, c
        return c
