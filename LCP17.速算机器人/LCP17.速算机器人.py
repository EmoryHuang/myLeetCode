'''
Descroption: LCP 17. ���������
Author: EmoryHuang
Date: 2021-07-08 18:55:49
����˼·:
���⣬������Ŀ����ʽ�Ӽ���
'''


class Solution:
    def calculate(self, s: str) -> int:
        x, y = 1, 0
        for c in s:
            if c == 'A':
                x = 2 * x + y
            if c == 'B':
                y = 2 * y + x
        return x + y
