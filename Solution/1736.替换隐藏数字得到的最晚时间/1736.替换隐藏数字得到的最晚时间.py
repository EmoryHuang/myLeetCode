'''
Descroption: LeetCode 1736. �滻�������ֵõ�������ʱ��
Author: EmoryHuang
Date: 2021-07-24 13:02:08
����˼·:
̰��˼��
ö������ ? ���ܳ��ֵ�λ��
'''


class Solution:
    def maximumTime(self, time: str) -> str:
        ls = list(time)
        if ls[0] == '?':
            ls[0] = '2' if ls[1] == '?' or ls[1] < '4' else '1'
        if ls[1] == '?':
            ls[1] = '3' if ls[0] == '2' else '9'
        if ls[3] == '?':
            ls[3] = '5'
        if ls[4] == '?':
            ls[4] = '9'
        return ''.join(ls)