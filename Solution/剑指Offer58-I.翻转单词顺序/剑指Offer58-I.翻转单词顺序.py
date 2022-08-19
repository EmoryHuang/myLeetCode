'''
Descroption: 剑指 Offer 58 - I. 翻转单词顺序
Author: EmoryHuang
Date: 2021-07-07 19:32:11
解题思路:
简单题, 使用split
'''


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
