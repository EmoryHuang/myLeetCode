'''
Descroption: LeetCode 1451. 重新排列句子中的单词
Author: EmoryHuang
Date: 2021-07-23 20:16:15
解题思路:
split分割，sort排序
'''


class Solution:
    def arrangeWords(self, text: str) -> str:
        text = sorted(text.lower().split(),key=lambda word: len(word))
        return ' '.join(text).capitalize()