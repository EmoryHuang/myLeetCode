'''
Descroption: ��ָ Offer 58 - II. ����ת�ַ���
Author: EmoryHuang
Date: 2021-07-07 19:42:11
����˼·:
����, ��Ƭ�����ƴ��
'''


class Solution:
    # ��Ƭ
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:] + s[:n]

    # ����ƴ��
    # def reverseLeftWords(self, s: str, n: int) -> str:
    #     ans = ''
    #     for i in range(n, n + len(s)):
    #         ans += s[i % len(s)]
    #     return ans
