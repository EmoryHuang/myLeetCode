'''
Descroption: LeetCode 813. 最大平均值和的分组
Author: EmoryHuang
Date: 2022-11-28 09:33:03
Method:
前缀和 + 动态规划
类似背包问题，将 n 个数分为 k 份
'''


class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        n = len(nums)
        # 计算前缀和
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] + nums[i]
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            dp[i] = pre[i] / i
        for j in range(2, k + 1):
            for i in range(n, j - 1, -1):
                for x in range(j - 1, i):
                    dp[i] = max(dp[i], dp[x] + (pre[i] - pre[x]) / (i - x))
        return dp[n]
