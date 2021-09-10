'''
Descroption: 面试题 16.17. 连续数列
Author: EmoryHuang
Date: 2021-07-28 19:14:13
Method:
动态规划
'''


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre, ans = 0, nums[0]
        for num in nums:
            pre = max(pre + num, num)
            ans = max(ans, pre)
        return ans