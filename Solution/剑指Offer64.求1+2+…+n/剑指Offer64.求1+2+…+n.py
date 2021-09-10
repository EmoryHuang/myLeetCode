'''
Descroption: 剑指 Offer 64. 求1+2+…+n
Author: EmoryHuang
Date: 2021-07-04 14:07:08
解题思路:
递归并设置终点
'''


class Solution:
    def sumNums(self, n: int) -> int:
        return n and (n + self.sumNums(n - 1))
