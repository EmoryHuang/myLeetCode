'''
Descroption: LeetCode 1646. 获取生成数组中的最大值
Author: EmoryHuang
Date: 2021-08-23 10:54:15
Method:
简单题，遍历数组，按题目给定的方式赋值，同时记录最大值
'''


class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n == 0: return 0
        nums = [0] * (n + 1)
        nums[1] = 1
        ans = 1
        for i in range(1, n + 1):
            if i % 2 == 0:
                nums[i] = nums[i // 2]
            else:
                nums[i] = nums[i // 2] + nums[(i + 1) // 2]
            ans = max(ans, nums[i])
        return ans
