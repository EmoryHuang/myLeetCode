'''
Descroption: ��ָ Offer 64. ��1+2+��+n
Author: EmoryHuang
Date: 2021-07-04 14:07:08
����˼·:
�ݹ鲢�����յ�
'''


class Solution:
    def sumNums(self, n: int) -> int:
        return n and (n + self.sumNums(n - 1))
