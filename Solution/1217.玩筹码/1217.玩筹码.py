'''
Descroption: LeetCode 1217. �����
Author: EmoryHuang
Date: 2021-09-11 20:25:55
Method:
�����ƶ�������λ�������ģ�ż���ƶ���ż��λ��������
��ôֻ��Ҫͳ������ż����������Ȼ����ѡ���������ٵ�һ��
'''


class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        odd, even = 0, 0
        for num in position:
            if num % 2 == 0:
                even += 1
            else:
                odd += 1
        return min(even, odd)
