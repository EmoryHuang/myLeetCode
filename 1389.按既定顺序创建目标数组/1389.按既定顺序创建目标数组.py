'''
Descroption: LeetCode 1387. ��������Ȩ������
Author: EmoryHuang
Date: 2021-08-27 15:22:49
Method:
ֱ�� insert
'''


class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        ans = []
        for i in range(len(nums)):
            ans.insert(index[i], nums[i])
        return ans