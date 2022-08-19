'''
Descroption: LeetCode 1763. 最长的美好子字符串
Author: EmoryHuang
Date: 2022-02-01 18:06:25
Method:
分治
如果某个字符在当前字符串中没有它对应的大写或小写字符，那么答案只能在它左边或在它右边
返回该点左边或右边更长的子字符串
'''


class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if len(s) < 2:
            return ''
        for i, c in enumerate(s):
            if c.upper() not in s or c.lower() not in s:
                return max(self.longestNiceSubstring(s[:i]),
                           self.longestNiceSubstring(s[i + 1:]),
                           key=len)
        return s
