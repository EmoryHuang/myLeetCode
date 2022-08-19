'''
Descroption: LeetCode 1455. 检查单词是否为句中其他单词的前缀
Author: EmoryHuang
Date: 2021-08-07 14:26:33
Method:
简单题，split分割
'''


class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        for i, word in enumerate(words):
            if word.startswith(searchWord):
                return i + 1
        return -1