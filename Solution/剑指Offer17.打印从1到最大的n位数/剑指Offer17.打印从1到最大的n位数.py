'''
Descroption: 剑指 Offer 17. 打印从 1 到最大的 n 位数
Author: EmoryHuang
Date: 2021-06-27 15:41:00
解题思路:
不考虑大数问题的话直接往里加就行
'''


class Solution:
    def printNumbers(self, n: int) -> List[int]:
        return list(range(1, 10**n))
