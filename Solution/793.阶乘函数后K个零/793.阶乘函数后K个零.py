'''
Descroption: LeetCode 793. 阶乘函数后 K 个零
Author: EmoryHuang
Date: 2022-08-28 10:52:37
Method:
数学 + 二分
通过记录5的数量判断阶乘末尾零的个数
之后通过二分求解
'''


class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        def getCnt(x: int) -> int:
            cnt = 0
            while x:
                x //= 5
                cnt += x
            return cnt

        def help(x: int):
            left, right = 0, 5 * x
            while left < right:
                mid = left + right >> 1
                if getCnt(mid) >= x:
                    right = mid
                else:
                    left = mid + 1
            return right

        if k <= 1: return 5
        return help(k + 1) - help(k)
