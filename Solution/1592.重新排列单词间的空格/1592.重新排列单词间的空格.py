'''
Descroption: LeetCode 1592. �������е��ʼ�Ŀո�
Author: EmoryHuang
Date: 2021-06-20 14:23:00
����˼·:
��¼�ո�͵��ʵĸ�����֮����
'''


class Solution:
    def reorderSpaces(self, text: str) -> str:
        c = text.count(' ')
        word = text.split()
        if len(word) == 1:
            return word[0] + ' ' * c
        a, b = divmod(c, len(word) - 1)
        return (' ' * a).join(word) + ' ' * b
