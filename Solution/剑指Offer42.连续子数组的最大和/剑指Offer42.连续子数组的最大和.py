'''
Descroption: 剑指 Offer 42. 连续子数组的最大和
Author: EmoryHuang
Date: 2021-07-04 14:45:27
解题思路:
动态规划
状态转移方程：dp[i] = max(dp[i - 1] + nums[i], nums[i])
'''


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        dp[0] = ans = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
            ans = max(ans, dp[i])
        return ans
