'''
Descroption: LeetCode 1451. �������о����еĵ���
Author: EmoryHuang
Date: 2021-07-23 20:16:15
����˼·:
split�ָsort����
'''


class Solution:
    def arrangeWords(self, text: str) -> str:
        text = sorted(text.lower().split(),key=lambda word: len(word))
        return ' '.join(text).capitalize()