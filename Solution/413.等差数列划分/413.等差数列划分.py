'''
Descroption: LeetCode 413. 等差数列划分
Author: EmoryHuang
Date: 2021-08-10 13:08:30
Method:
动态规划
考虑以nums[i]结尾的等差数列的个数
'''


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        # 考虑以nums[i]结尾的等差数列的个数
        ans, cnt = 0, 0
        for i in range(2, n):
            if nums[i] + nums[i - 2] == 2 * nums[i - 1]:
                cnt += 1
                ans += cnt
            else:
                cnt = 0
        return ans