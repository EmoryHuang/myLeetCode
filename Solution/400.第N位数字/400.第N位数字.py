'''
Descroption: LeetCode 400. 第 N 位数字
Author: EmoryHuang
Date: 2021-11-30 09:03:10
Method:
模拟
长度为 l 的数字有 [10^(l - 1), 10^l - 1)] ，共 9 * 10^(l - 1) 个
首先判断第 n 位所在数字的长度，然后求出第 n 位所在数字的值
第 n 个数字是 10^(l - 1) + (n_l - 1) / l
'''


class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10:
            return n
        # 长度为 l 的数字有 [10^(l - 1), 10^l - 1)] ，共 9 * 10^(l - 1) 个
        # 第 n 位所在数字的长度
        l, base = 1, 9
        while n > l * base:
            n -= l * base
            l += 1
            base *= 10
        # 长度为 l 的数字的第 1 个数字是 10^(l - 1)
        # 第 n 个数字是 10^(l - 1) + (n - 1) / l
        num = 10**(l - 1) + (n - 1) // l
        # 第 n 位是 num[(n - 1) % l]
        return int(str(num)[(n - 1) % l])