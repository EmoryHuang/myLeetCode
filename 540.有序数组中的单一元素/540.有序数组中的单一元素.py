'''
Descroption: LeetCode 540. ���������еĵ�һԪ��
Author: EmoryHuang
Date: 2021-07-30 14:34:29
Method:
��������
��һԪ��ֻ�������ż���±�λ��
'''


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if mid % 2 == 1:
                mid -= 1
            if nums[mid] != nums[mid + 1]:
                r = mid
            else:
                l = mid + 2
        return nums[l]