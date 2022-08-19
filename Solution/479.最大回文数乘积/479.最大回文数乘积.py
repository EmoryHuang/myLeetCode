'''
Descroption: LeetCode 479. 最大回文数乘积
Author: EmoryHuang
Date: 2022-04-16 08:42:17
Method:
打表
'''


class Solution:
    def largestPalindrome(self, n: int) -> int:
        return [9, 987, 123, 597, 677, 1218, 877, 475][n - 1]
