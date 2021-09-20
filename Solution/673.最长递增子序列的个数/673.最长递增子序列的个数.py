'''
Descroption: LeetCode 673. 最长递增子序列的个数
Author: EmoryHuang
Date: 2021-09-20 19:02:50
Method:
动态规划
在传统最长递增子序列的基础上增加变量
dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
cnt[i] 表示以 nums[i] 结尾的最长递增子序列的个数
对 dp[i] == dp[j] + 1 有，cnt[i] += cnt[j]
'''


class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        # dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
        # cnt[i] 表示以 nums[i] 结尾的最长递增子序列的个数
        dp, cnt = [0] * n, [0] * n
        l = 1
        for i in range(n):
            dp[i], cnt[i] = 1, 1
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        cnt[i] = cnt[j]
                    elif dp[i] == dp[j] + 1:
                        cnt[i] += cnt[j]  # 累积
            l = max(l, dp[i])  # 记录最长子序列长度
        ans = 0
        for i in range(n):
            if dp[i] == l:
                ans += cnt[i]
        return ans
