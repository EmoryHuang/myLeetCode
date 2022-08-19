'''
Descroption: LeetCode 446. 等差数列划分 II - 子序列
Author: EmoryHuang
Date: 2021-08-11 14:27:29
Method:
动态规划 + 哈希表
dp[i][d] 表示以 nums[i] 结尾的，公差为 d 的等差数列个数
状态转移方程：dp[i][d] += dp[j][d] + 1
'''


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        # dp[i] 的每个元素均为哈希表 {d: cnt}
        # d 表示等差数列的差值
        # cnt 表示以 nums[i] 结尾的，公差为 d 的等差数列个数
        dp = [defaultdict(int) for _ in range(n)]
        for i in range(n):
            for j in range(i):
                # 计算 nums[i] 和 nums[j] 之间的差值
                d = nums[i] - nums[j]
                # 以 nums[j] 结尾的，公差为 d 的等差数列个数
                cnt = dp[j][d]
                ans += cnt
                # 因为 nums[i] 和 nums[j] 的差值也为 d，所以数量加 1
                dp[i][d] += cnt + 1
        return ans