'''
Descroption: LeetCode 1387. 将整数按权重排序
Author: EmoryHuang
Date: 2021-08-27 15:22:49
Method:
直接 insert
'''


class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        ans = []
        for i in range(len(nums)):
            ans.insert(index[i], nums[i])
        return ans