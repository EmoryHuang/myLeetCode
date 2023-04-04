'''
Descroption: LeetCode 2367. 算术三元组的数目
Author: EmoryHuang
Date: 2023-03-31 09:13:30
Method:
暴力遍历，寻找所有三元组
'''


class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        ans = 0
        n = len(nums)
        for k in range(2, n):
            for j in range(k):
                for i in range(j):
                    if nums[k] - nums[j] == diff and nums[j] - nums[i] == diff:
                        ans += 1
        return ans