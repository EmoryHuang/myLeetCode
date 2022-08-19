'''
Descroption: 剑指 Offer 10- II. 青蛙跳台阶问题
Author: EmoryHuang
Date: 2021-06-29 20:12:00
解题思路:
简单题，按照公式计算斐波那契数列
f(n) = f(n - 1) + f(n - 2)
'''


class Solution:
    def numWays(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        a, b = 0, 1
        for i in range(n):
            b = a + b
            a = b - a
            b %= 1000000007
        return b
