'''
Descroption: LeetCode 2012. 数组美丽值求和
Author: EmoryHuang
Date: 2021-10-15 20:15:11
Method:
模拟
使用 l2r, r2l 分别记录 [0, i) 中的最大值，[i + 1, n) 中的最小值
之后按题意计算美丽值
'''


class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        # l2r, r2l 分别记录第 i 个位置之前的最大值，之后的最小值
        l2r, r2l = [0] * n, [0] * n
        l2r[0], r2l[n - 1] = nums[0], nums[n - 1]
        for i in range(1, n):
            l2r[i] = max(l2r[i - 1], nums[i])
            r2l[n - i - 1] = min(r2l[n - i], nums[n - i - 1])
        # 按题意计算美丽值
        for i in range(1, n - 1):
            if nums[i] > l2r[i - 1] and nums[i] < r2l[i + 1]:
                ans += 2
            elif nums[i] > nums[i - 1] and nums[i] < nums[i + 1]:
                ans += 1
        return ans