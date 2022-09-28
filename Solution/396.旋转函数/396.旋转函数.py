'''
Descroption: LeetCode 396. 旋转函数
Author: EmoryHuang
Date: 2022-04-22 08:51:27
Method:
迭代
可以通过式子找到规律
F(i) = F(i - 1) + sum(nums) - n * num[n - i]
'''


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        # F(i) = F(i - 1) + sum(nums) - n * num[n - i]
        f, n, sumnum = 0, len(nums), sum(nums)
        for i in range(n):
            f += i * nums[i]
        maxf = f
        for i in range(n - 1, 0, -1):
            f = f + sumnum - n * nums[i]
            maxf = max(maxf, f)
        return maxf