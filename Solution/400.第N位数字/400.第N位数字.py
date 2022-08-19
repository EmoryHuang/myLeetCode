'''
Descroption: LeetCode 400. �� N λ����
Author: EmoryHuang
Date: 2021-11-30 09:03:10
Method:
ģ��
����Ϊ l �������� [10^(l - 1), 10^l - 1)] ���� 9 * 10^(l - 1) ��
�����жϵ� n λ�������ֵĳ��ȣ�Ȼ������� n λ�������ֵ�ֵ
�� n �������� 10^(l - 1) + (n_l - 1) / l
'''


class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10:
            return n
        # ����Ϊ l �������� [10^(l - 1), 10^l - 1)] ���� 9 * 10^(l - 1) ��
        # �� n λ�������ֵĳ���
        l, base = 1, 9
        while n > l * base:
            n -= l * base
            l += 1
            base *= 10
        # ����Ϊ l �����ֵĵ� 1 �������� 10^(l - 1)
        # �� n �������� 10^(l - 1) + (n - 1) / l
        num = 10**(l - 1) + (n - 1) // l
        # �� n λ�� num[(n - 1) % l]
        return int(str(num)[(n - 1) % l])