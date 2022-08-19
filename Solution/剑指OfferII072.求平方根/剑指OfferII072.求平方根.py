'''
Descroption: 剑指 Offer II 072. 求平方根
Author: EmoryHuang
Date: 2021-10-21 19:16:24
Method:
简单题，二分法求平方根
'''


class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1:
            return 1
        l, r = 0, x // 2
        while l < r:
            mid = l + r + 1 >> 1
            if mid <= x // mid:
                l = mid
            else:
                r = mid - 1
        return l
