'''
Descroption: LeetCode 1816. �ضϾ���
Author: EmoryHuang
Date: 2021-06-17 15:23:00
����˼·:
���⣬���ո�
'''


class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        return ' '.join(s.split(' ')[:k])
