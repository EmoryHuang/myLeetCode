'''
Descroption: LeetCode 976. �����ε�����ܳ�
Author: EmoryHuang
Date: 2021-07-10 15:21:06
����˼·:
�����Ӻ���ǰ�������飬����������������������Σ���Ϊ����ܳ�
'''


class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        # �����Ӻ���ǰ��������
        for i in range(len(nums) - 1, 1, -1):
            # �����������������������
            if nums[i] < nums[i - 1] + nums[i - 2]:
                return nums[i] + nums[i - 1] + nums[i - 2]
        return 0
