'''
Descroption: LeetCode 1935. �����������󵥴���
Author: EmoryHuang
Date: 2021-07-21 20:43:24
����˼·:
ʹ�� split �Ļ�����ֱ�ӷָ�Ƚϼ�
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
