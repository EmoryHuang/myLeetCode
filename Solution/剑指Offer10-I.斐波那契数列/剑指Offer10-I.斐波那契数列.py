'''
Descroption: ��ָ Offer 10- I. 쳲���������
Author: EmoryHuang
Date: 2021-06-29 20:04:00
����˼·:
���⣬���չ�ʽ����쳲���������
'''


class Solution:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            return n
        a, b = 0, 1
        for i in range(1, n):
            b = a + b
            a = b - a
            b %= 1000000007
        return b
