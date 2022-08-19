'''
Descroption: LeetCode 1880. 检查某单词是否等于两单词之和
Author: EmoryHuang
Date: 2021-09-24 19:20:18
Method:
简单题，将字母转换成对应数字即可
'''


class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def tonum(s: str) -> int:
            n, num = len(s), 0
            for i in range(n):
                num = num * 10 + (ord(s[i]) - ord('a'))
            return num

        return tonum(firstWord) + tonum(secondWord) == tonum(targetWord)
