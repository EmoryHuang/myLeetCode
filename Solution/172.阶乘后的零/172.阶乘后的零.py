'''
Descroption: LeetCode 172. 阶乘后的零
Author: EmoryHuang
Date: 2022-03-25 08:47:53
Method:
阶乘后的零的个数取决于展开式中 10 的个数，而 10 = 2 * 5
因此结果取决于「2 的数量」和「5 的数量」中的较小值
而 5 的个数必然不会超过 2 的个数
因此只统计 5 的个数即可
'''


class Solution:
    def trailingZeroes(self, n: int) -> int:
        cnt = 0
        while n:
            n //= 5
            cnt += n
        return cnt