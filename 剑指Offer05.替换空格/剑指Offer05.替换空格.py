'''
Descroption: 剑指 Offer 05. 替换空格
Author: EmoryHuang
Date: 2021-06-28 16:34:00
解题思路:
简单题，替换空格，遍历或者直接 replace
'''


class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(" ", "%20")
