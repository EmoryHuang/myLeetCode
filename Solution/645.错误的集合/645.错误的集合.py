'''
Descroption: LeetCode 645. ����ļ���
Author: EmoryHuang
Date: 2021-07-04 12:51:42
����˼·:
����һ����ѧ
����������ϣ��
'''


class Solution:
    # ��ѧ
    def findErrorNums(self, nums: List[int]) -> List[int]:
        s = sum(set(nums))
        return [sum(nums) - s, len(nums) * (len(nums) + 1) // 2 - s]

    # ��ϣ��
    # def findErrorNums(self, nums: List[int]) -> List[int]:
    #     hash = [0] * len(nums)
    #     for num in nums:
    #         hash[num - 1] += 1
    #     return [hash.index(2) + 1, hash.index(0) + 1]
