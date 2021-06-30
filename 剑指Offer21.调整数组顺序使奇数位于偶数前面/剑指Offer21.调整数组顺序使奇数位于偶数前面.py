'''
Descroption: ��ָ Offer 21. ��������˳��ʹ����λ��ż��ǰ��
Author: EmoryHuang
Date: 2021-06-30 20:35:00
����˼·:
ά������ָ��
����һ������ָ��
fast ��������Ԫ�أ�slow ��¼����λ��
��������ͷβָ��
'''


class Solution:
    # ����һ������ָ��
    def exchange(self, nums: List[int]) -> List[int]:
        slow = fast = 0
        while fast < len(nums):
            if nums[fast] & 1:  # ���������
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow += 1
            fast += 1
        return nums

    # ��������ͷβָ��
    # def exchange(self, nums: List[int]) -> List[int]:
    #     l, r = 0, len(nums) - 1
    #     while l < r:
    #         while l < r and nums[l] & 1:  # ���������
    #             l += 1
    #         while l < r and not nums[r] & 1:
    #             r -= 1
    #         nums[l], nums[r] = nums[r], nums[l]
    #         l += 1
    #         r -= 1
    #     return nums
