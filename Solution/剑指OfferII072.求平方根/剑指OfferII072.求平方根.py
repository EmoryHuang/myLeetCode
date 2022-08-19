'''
Descroption: ��ָ Offer II 072. ��ƽ����
Author: EmoryHuang
Date: 2021-10-21 19:16:24
Method:
���⣬���ַ���ƽ����
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
