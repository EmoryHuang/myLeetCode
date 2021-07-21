'''
Descroption: LeetCode 1935. 可以输入的最大单词数
Author: EmoryHuang
Date: 2021-07-21 20:43:24
解题思路:
使用 split 的话可以直接分割，比较简单
'''


class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        cnt = len(words)
        for word in words:
            for c in word:
                if c in brokenLetters:
                    cnt -= 1
                    break
        return cnt
