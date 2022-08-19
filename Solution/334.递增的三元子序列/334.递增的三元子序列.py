'''
Descroption: LeetCode 334. ��������Ԫ������
Author: EmoryHuang
Date: 2021-07-27 19:24:08
Method:
���������������
ά����Сֵ���м�ֵ�����ҵ����м�ֵ�����Ԫ�أ����ҵ�����Ԫ������
'''


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        min, mid = float('inf'), float('inf')
        for num in nums:
            if min >= num:
                min = num
            elif num <= mid:
                mid = num
            else:
                return True
        return False
