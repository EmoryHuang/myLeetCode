'''
Descroption: LeetCode 844. �ȽϺ��˸���ַ���
Author: EmoryHuang
Date: 2021-06-13 16:14:00
����˼·:
ģ��ķ��������� # ��ɾ���ַ�
'''


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:

        def backspace(s: str) -> str:
            a = ''
            for i in range(len(s)):
                if s[i] != '#':
                    a += s[i]
                elif s[i] == '#' and len(a) > 0:
                    a = a[:-1]
            return a

        return backspace(s) == backspace(t)
