'''
Descroption: LeetCode 441. 排列硬币
Author: EmoryHuang
Date: 2021-07-22 19:56:01
解题思路:
方法一：二分
二分法寻找右端点
方法二：解方程
x(x+1)/2=n
'''


class Solution:
    # 方法一：二分
    # def arrangeCoins(self, n: int) -> int:
    #     l, r = 1, n // 2 + 1
    #     while l < r:
    #         mid = l + r + 1 >> 1
    #         if mid * (mid + 1) <= 2 * n:
    #             l = mid
    #         else:
    #             r = mid - 1
    #     return l

    # 方法二：解方程
    def arrangeCoins(self, n: int) -> int:
        return int((-1 + math.sqrt(1 + 8 * n)) / 2)
