'''
Descroption: LeetCode 650. ֻ���������ļ���
Author: EmoryHuang
Date: 2021-09-19 14:26:38
Method:
��ѧ/��̬�滮
��� n ��һ����������ô��������������
��� n ��һ�������������ֽ��������ֽ�
'''


class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        for i in range(2, n + 1):
            while n % i == 0:
                ans += i
                n //= i
        return ans