'''
Descroption: LeetCode 151. ��ת�ַ�����ĵ���
Author: EmoryHuang
Date: 2021-07-07 19:32:46
����˼·:
����, ʹ��split
'''


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
