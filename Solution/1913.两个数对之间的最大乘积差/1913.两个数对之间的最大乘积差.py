'''
Descroption: LeetCode 1913. ��������֮������˻���
Author: EmoryHuang
Date: 2021-09-23 19:09:19
Method:
���⣬����֮��ȡͷβ4��Ԫ��
'''


class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        nums.sort()
        return nums[-1] * nums[-2] - nums[0] * nums[1]