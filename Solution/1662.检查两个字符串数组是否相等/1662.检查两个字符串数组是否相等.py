'''
Descroption: LeetCode 1662. 检查两个字符串数组是否相等
Author: EmoryHuang
Date: 2022-11-01 09:10:55
Method:
简单题，直接检查两个字符串数组是否相等
'''


class Solution:

    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return ''.join(word1) == ''.join(word2)