'''
Descroption: LeetCode 686. �ظ������ַ���ƥ��
Author: EmoryHuang
Date: 2021-12-22 08:54:45
Method:
��� A �ĳ���С�� B �ĳ��ȣ���ʱ B �� A ���ظ��Ӵ���
�� A ���ظ����������� len(B) / len(A) + 2
'''


class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        n = len(b) // len(a)
        rep = a
        # ��� A �ĳ���С�� B �ĳ��ȣ���ʱ B �� A ���ظ��Ӵ���
        # �� A ���ظ����������� len(B) / len(A) + 2
        for i in range(1, n + 3):
            if b in rep:
                return i
            rep += a
        return -1