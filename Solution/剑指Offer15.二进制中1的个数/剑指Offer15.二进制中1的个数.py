'''
Descroption: ��ָ Offer 15. ��������1�ĸ���
Author: EmoryHuang
Date: 2021-06-23 12:33:00
����˼·:
���⣬�ж϶���������ÿλ�Ƿ�Ϊ 1
'''


class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while n:
            cnt += n & 1
            n >>= 1
        return cnt
