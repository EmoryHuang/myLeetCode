'''
Descroption: LeetCode 2351. 第一个出现两次的字母
Author: EmoryHuang
Date: 2023-01-01 09:10:15
Method:
位运算
记录出现字符的位置即可
'''


class Solution:
    def repeatedCharacter(self, s: str) -> str:
        ans = 0
        for c in s:
            if ans & (1 << ord(c) - ord('a')):
                return c

            ans |= 1 << ord(c) - ord('a')