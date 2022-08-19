'''
Descroption: LeetCode 350. ��������Ľ��� II
Author: EmoryHuang
Date: 2021-06-11 16:49:00
����˼·:
��ǰһ�ⲻͬ���ǣ��������ظ�Ԫ��
���� + ˫ָ��
������Ȼ��ʹ��˫ָ��������飬��Ԫ����ͬ����뼯��
���򽫽�Сһ����ָ�����
'''


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        unit = []
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                unit.append(nums1[i])
                i, j = i + 1, j + 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                i += 1
        return unit
