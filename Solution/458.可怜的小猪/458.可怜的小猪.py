'''
Descroption: LeetCode 458. ������С��
Author: EmoryHuang
Date: 2021-11-25 08:38:14
Method:
t = minutesToTest / minutesToDie �����һֻ����Բ��Ե�������
��ôһֻ����Լ���� t + 1 ��Ͱ��ˮ
ͬ���ģ����� n ֻ��ֻ��Ҫ n ���� (t + 1)**n >= buckets
�� n = log(buckets, (t + 1))
'''


class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        # t = minutesToTest / minutesToDie �����һֻ����Բ��Ե�������
        # ��ôһֻ����Լ���� t + 1 ��Ͱ��ˮ
        # ͬ���ģ����� n ֻ��ֻ��Ҫ n ���� (t + 1)**n >= buckets
        # �� n = log(buckets, (t + 1))
        return math.ceil(math.log(buckets, minutesToTest / minutesToDie + 1))