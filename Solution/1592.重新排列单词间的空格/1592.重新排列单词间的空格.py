'''
Descroption: LeetCode 1592. 重新排列单词间的空格
Author: EmoryHuang
Date: 2021-06-20 14:23:00
解题思路:
记录空格和单词的个数，之后补齐
'''


class Solution:
    def reorderSpaces(self, text: str) -> str:
        c = text.count(' ')
        word = text.split()
        if len(word) == 1:
            return word[0] + ' ' * c
        a, b = divmod(c, len(word) - 1)
        return (' ' * a).join(word) + ' ' * b
