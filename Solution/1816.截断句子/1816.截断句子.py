'''
Descroption: LeetCode 1816. 截断句子
Author: EmoryHuang
Date: 2021-06-17 15:23:00
解题思路:
简单题，数空格
'''


class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        return ' '.join(s.split(' ')[:k])
