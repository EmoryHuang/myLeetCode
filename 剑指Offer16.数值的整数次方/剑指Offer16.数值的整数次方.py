'''
Descroption: ��ָ Offer 16. ��ֵ�������η�
Author: EmoryHuang
Date: 2021-06-27 15:20:00
����˼·:
�������㷨
'''


class Solution:
    def myPow(self, x: float, n: int) -> float:
        ans = 1
        flag = n >= 0
        n = abs(n)
        while n:
            if n & 1:  # �� n �Ķ�����ĩβΪ 1
                ans = ans * x  # ans �ۼ��� x
            x = x * x   # x ȡƽ��
            n >>= 1
        return ans if flag else 1 / ans
