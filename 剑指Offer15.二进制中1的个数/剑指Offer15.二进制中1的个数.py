'''
Descroption: 剑指 Offer 15. 二进制中1的个数
Author: EmoryHuang
Date: 2021-06-23 12:33:00
解题思路:
简单题，判断二进制数的每位是否为 1
'''


class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while n:
            cnt += n & 1
            n >>= 1
        return cnt
