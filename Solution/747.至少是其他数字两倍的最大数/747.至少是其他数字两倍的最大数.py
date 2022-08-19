'''
Descroption: LeetCode 747. �������������������������
Author: EmoryHuang
Date: 2021-09-27 19:45:05
Method:
����
����һ�����飬�ҳ����ֵ�ʹδ�ֵ
'''


class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        a, b = 0, 0
        pos = 0
        for i, num in enumerate(nums):
            if num > a:
                b = a
                a = num
                pos = i
            elif num > b:
                b = num
        if a >= b * 2:
            return pos
        return -1
