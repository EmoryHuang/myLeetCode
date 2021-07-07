'''
Descroption: LeetCode 151. 翻转字符串里的单词
Author: EmoryHuang
Date: 2021-07-07 19:32:46
解题思路:
简单题, 使用split
'''


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
