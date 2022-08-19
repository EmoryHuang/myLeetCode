'''
Descroption: LeetCode 1995. 统计特殊四元组
Author: EmoryHuang
Date: 2021-12-29 09:12:30
Method:
方法一: 暴力
简单题，由于 N 的范围很小，可以直接暴力遍历

# 方法二: 背包问题
定义 dp[i][j][k] 为考虑前 i 个物品，凑成数值恰好 j，使用个数恰好为 k 的方案数
状态转移方程
如果不加入物品 nums[i-1], 那么 f[i][j][k] = f[i - 1][j][k]
如果加入物品 nums[i-1], 那么 f[i][j][k] = f[i - 1][j - nums[i - 1]][k - 1]

空间优化: 通过倒序遍历降低空间复杂度
'''


class Solution:
    # 方法一: 暴力
    # def countQuadruplets(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     ans = 0
    #     for a in range(n):
    #         for b in range(a + 1, n):
    #             for c in range(b + 1, n):
    #                 for d in range(c + 1, n):
    #                     if nums[a] + nums[b] + nums[c] == nums[d]:
    #                         ans += 1
    #     return ans

    # 方法二: 背包问题
    # def countQuadruplets(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     # dp[i][j][k] 为考虑前 i 个物品，凑成数值恰好 j，使用个数恰好为 k 的方案数
    #     dp = [[[0] * 4 for _ in range(101)] for _ in range(n + 1)]
    #     dp[0][0][0] = 1
    #     for i in range(1, n + 1):
    #         for j in range(101):
    #             for k in range(4):
    #                 dp[i][j][k] += dp[i - 1][j][k]
    #                 # 如果还能放下第 i 个物品
    #                 if j - nums[i - 1] >= 0 and k - 1 >= 0:
    #                     dp[i][j][k] += dp[i - 1][j - nums[i - 1]][k - 1]
    #     ans = 0
    #     for i in range(3, n + 1):
    #         ans += dp[i][nums[i - 1]][3]
    #     return ans

    # 方法二: 背包问题(空间优化)
    def countQuadruplets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        # dp[i][j][k] 为考虑前 i 个物品，凑成数值恰好 j，使用个数恰好为 k 的方案数
        dp = [[0] * 4 for _ in range(101)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            ans += dp[nums[i - 1]][3]
            # 倒序遍历
            for j in range(100, -1, -1):
                for k in range(4):
                    if j - nums[i - 1] >= 0 and k - 1 >= 0:
                        dp[j][k] += dp[j - nums[i - 1]][k - 1]
        return ans
