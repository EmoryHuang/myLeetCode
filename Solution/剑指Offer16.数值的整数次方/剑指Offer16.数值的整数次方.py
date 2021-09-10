'''
Descroption: 剑指 Offer 16. 数值的整数次方
Author: EmoryHuang
Date: 2021-06-27 15:20:00
解题思路:
快速幂算法
'''


class Solution:
    def myPow(self, x: float, n: int) -> float:
        ans = 1
        flag = n >= 0
        n = abs(n)
        while n:
            if n & 1:  # 若 n 的二进制末尾为 1
                ans = ans * x  # ans 累加上 x
            x = x * x   # x 取平方
            n >>= 1
        return ans if flag else 1 / ans
