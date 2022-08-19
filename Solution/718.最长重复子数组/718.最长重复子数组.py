'''
Descroption: LeetCode 718. 最长重复子数组
Author: EmoryHuang
Date: 2021-06-25 20:34:00
解题思路:
动态规划
dp[i][j]表示以 A[i-1], B[j-1] 结尾的最长重复子数组
状态转移方程：
当 A[i - 1] == B[j - 1] 时，dp[i][j] = dp[i - 1][j - 1] + 1
当 A[i - 1] != B[j - 1] 时，dp[i][j] = 0
'''


class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        # dp[i][j]表示以 A[i-1], B[j-1] 结尾的最长重复子数组
        dp = [[0 for _ in range(m + 1)]for _ in range(n + 1)]
        ans = 0
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    ans = max(ans, dp[i][j])
        return ans
