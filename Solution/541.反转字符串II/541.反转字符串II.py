'''
Descroption: LeetCode 541. ��ת�ַ��� II
Author: EmoryHuang
Date: 2021-08-20 15:28:12
Method:
ģ�⣬������ÿ�� 2k ���ַ���תǰ k ��
'''


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        t = list(s)
        for i in range(0, len(t), 2 * k):
            t[i:i + k] = reversed(t[i:i + k])
        return "".join(t)
