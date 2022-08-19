'''
Descroption: 剑指 Offer II 089. 房屋偷盗
Author: EmoryHuang
Date: 2021-08-09 19:47:24   
Method:
动态规划
dp[i] 表示到第i个房间为止能偷盗的最大金额
状态转移方程：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
'''


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        dp = [0] * n
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])
        for i in range(2, n):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        return dp[n - 1]