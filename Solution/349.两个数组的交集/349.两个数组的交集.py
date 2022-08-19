'''
Descroption: LeetCode 349. ��������Ľ���
Author: EmoryHuang
Date: 2021-06-11 16:25:00
����˼·:
����һ��ʹ�÷�װ����

������������ + ˫ָ��
������Ȼ��ʹ��˫ָ��������飬��Ԫ����ͬ����뼯��
���򽫽�Сһ����ָ�����
'''


class Solution:
    # ����һ��ʹ�÷�װ����
    # def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
    #     return list(set(nums1) & set(nums2))

    # ������������ + ˫ָ��
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        unit = set()
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                unit.add(nums1[i])
                i, j = i + 1, j + 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                i += 1
        return list(unit)
