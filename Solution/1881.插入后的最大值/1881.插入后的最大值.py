'''
Descroption: LeetCode 1881. ���������ֵ
Author: EmoryHuang
Date: 2021-09-10 20:15:06
Method:
��� n �Ǹ�����Ѱ�� n �е�һ���� x ���λ�ò���
��� n ��������Ѱ�� n �е�һ���� x С��λ�ò���
'''


class Solution:
    def maxValue(self, n: str, x: int) -> str:
        if n[0] == '-':
            for i, s in enumerate(n):
                if i == 0: continue
                if int(s) > x:
                    return n[:i] + str(x) + n[i:]
            return n + str(x)
        else:
            for i, s in enumerate(n):
                if int(s) < x:
                    return n[:i] + str(x) + n[i:]
            return n + str(x)
