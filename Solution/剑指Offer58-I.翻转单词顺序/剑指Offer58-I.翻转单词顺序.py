'''
Descroption: ��ָ Offer 58 - I. ��ת����˳��
Author: EmoryHuang
Date: 2021-07-07 19:32:11
����˼·:
����, ʹ��split
'''


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
