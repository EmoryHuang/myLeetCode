'''
Descroption: 剑指 Offer 10- I. 斐波那契数列
Author: EmoryHuang
Date: 2021-06-29 20:04:00
解题思路:
简单题，按照公式计算斐波那契数列
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
