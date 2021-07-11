'''
Descroption: 面试题 17.16. 按摩师
Author: EmoryHuang
Date: 2021-07-11 14:51:45
解题思路:
动态规划，打家劫舍
状态转移方程：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
'''


class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) < 3:
            return max(nums)
        dp = [0] * len(nums)
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        return dp[len(nums) - 1]
