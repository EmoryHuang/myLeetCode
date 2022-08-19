'''
Descroption: LeetCode 1137. 第 N 个泰波那契数
Author: EmoryHuang
Date: 2021-07-17 15:11:33
解题思路:
通过题目给的公式计算即可
'''


class Solution:
    def tribonacci(self, n: int) -> int:
        a, b, c = 0, 1, 1
        for _ in range(n):
            a, b, c = b, c, a + b + c
        return a
