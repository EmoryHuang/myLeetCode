'''
Descroption: LeetCode 1800. 最大升序子数组和
Author: EmoryHuang
Date: 2022-10-07 10:55:55
Method:
简单题，遍历数组寻找最大升序子数组和
'''


class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans, cur = nums[0], nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                cur += nums[i]
            else:
                cur = nums[i]
            ans = max(ans, cur)
        return ans