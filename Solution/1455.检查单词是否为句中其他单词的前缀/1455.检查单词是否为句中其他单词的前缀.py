'''
Descroption: LeetCode 1455. ��鵥���Ƿ�Ϊ�����������ʵ�ǰ׺
Author: EmoryHuang
Date: 2021-08-07 14:26:33
Method:
���⣬split�ָ�
'''


class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        for i, word in enumerate(words):
            if word.startswith(searchWord):
                return i + 1
        return -1