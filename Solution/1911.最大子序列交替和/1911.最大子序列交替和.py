'''
Descroption: LeetCode 1911. ��������н����
Author: EmoryHuang
Date: 2021-07-22 15:04:53
����˼·:
��̬�滮
odd[i],even[i]�ֱ����ǰi��������������У����һ��Ԫ�ص��±�Ϊ����/ż��
ѡ��/��ѡ��ǰԪ��
��odd��˵��ǰһ��ѡ���Ԫ���±���ż����
����even��˵��ǰһ��ѡ���Ԫ���±���������
odd[i] = max(even[i - 1] - nums[i], odd[i - 1])
even[i] = max(odd[i - 1] + nums[i], even[i - 1])
'''


class Solution:
    # def maxAlternatingSum(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     # odd[i],even[i]�ֱ����ǰi��������������У����һ��Ԫ�ص��±�Ϊ����/ż��
    #     odd, even = [0] * n, [0] * n
    #     odd[0], even[0] = 0, nums[0]
    #     for i in range(1, n):
    #         # ѡ��/��ѡ��ǰԪ��
    #         # ��odd��˵��ǰһ��ѡ���Ԫ���±���ż����
    #         # ����even��˵��ǰһ��ѡ���Ԫ���±���������
    #         odd[i] = max(even[i - 1] - nums[i], odd[i - 1])
    #         even[i] = max(odd[i - 1] + nums[i], even[i - 1])
    #     return max(odd[n - 1], even[n - 1])

    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        odd, even = 0, nums[0]
        for i in range(1, n):
            odd, even = max(even - nums[i], odd), max(odd + nums[i], even)
        return even
