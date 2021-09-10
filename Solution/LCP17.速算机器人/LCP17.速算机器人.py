'''
Descroption: LCP 17. 速算机器人
Author: EmoryHuang
Date: 2021-07-08 18:55:49
解题思路:
简单题，按照题目给的式子计算
'''


class Solution:
    def calculate(self, s: str) -> int:
        x, y = 1, 0
        for c in s:
            if c == 'A':
                x = 2 * x + y
            if c == 'B':
                y = 2 * y + x
        return x + y
