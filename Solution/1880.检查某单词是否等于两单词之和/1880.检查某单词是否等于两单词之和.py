'''
Descroption: LeetCode 1880. ���ĳ�����Ƿ����������֮��
Author: EmoryHuang
Date: 2021-09-24 19:20:18
Method:
���⣬����ĸת���ɶ�Ӧ���ּ���
'''


class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def tonum(s: str) -> int:
            n, num = len(s), 0
            for i in range(n):
                num = num * 10 + (ord(s[i]) - ord('a'))
            return num

        return tonum(firstWord) + tonum(secondWord) == tonum(targetWord)
