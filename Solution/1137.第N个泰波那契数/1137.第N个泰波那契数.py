'''
Descroption: LeetCode 1137. �� N ��̩��������
Author: EmoryHuang
Date: 2021-07-17 15:11:33
����˼·:
ͨ����Ŀ���Ĺ�ʽ���㼴��
'''


class Solution:
    def tribonacci(self, n: int) -> int:
        a, b, c = 0, 1, 1
        for _ in range(n):
            a, b, c = b, c, a + b + c
        return a
