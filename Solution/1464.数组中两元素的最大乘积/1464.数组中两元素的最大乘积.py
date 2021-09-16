'''
Descroption: LeetCode 1464. ��������Ԫ�ص����˻�
Author: EmoryHuang
Date: 2021-09-15 15:31:50
Method:
��������
һ�α����õ����ֵ�ʹδ�ֵ
'''


class Solution:
    # ��������
    # def maxProduct(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     ans = 0
    #     for i in range(n):
    #         for j in range(i + 1, n):
    #             ans = max(ans, (nums[i] - 1) * (nums[j] - 1))
    #     return ans

    # һ�α���
    def maxProduct(self, nums: List[int]) -> int:
        # max1, max2 �ֱ��ʾ���͵ڶ������
        max1, max2 = 0, 0
        for num in nums:
            if num > max2:
                max2 = num
            if max2 > max1:
                max1, max2 = max2, max1
        return (max1 - 1) * (max2 - 1)
