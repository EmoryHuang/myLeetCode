'''
Descroption: LeetCode 441. ����Ӳ��
Author: EmoryHuang
Date: 2021-07-22 19:56:01
����˼·:
����һ������
���ַ�Ѱ���Ҷ˵�
���������ⷽ��
x(x+1)/2=n
'''


class Solution:
    # ����һ������
    # def arrangeCoins(self, n: int) -> int:
    #     l, r = 1, n // 2 + 1
    #     while l < r:
    #         mid = l + r + 1 >> 1
    #         if mid * (mid + 1) <= 2 * n:
    #             l = mid
    #         else:
    #             r = mid - 1
    #     return l

    # ���������ⷽ��
    def arrangeCoins(self, n: int) -> int:
        return int((-1 + math.sqrt(1 + 8 * n)) / 2)
