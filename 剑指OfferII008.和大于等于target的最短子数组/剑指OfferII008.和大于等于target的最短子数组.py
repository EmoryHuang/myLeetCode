'''
Descroption: 剑指 Offer II 008. 和大于等于 target 的最短子数组
Author: EmoryHuang
Date: 2021-08-07 14:36:28
Method:
滑动窗口
如果窗口中的和大于 target，则左端点向右移动，并更新最小长度
'''


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n, l, r = len(nums), 0, 0
        ans, sum = float('inf'), 0
        while r < n:
            sum += nums[r]
            r += 1
            while sum >= target:
                ans = min(ans, r - l)
                sum -= nums[l]
                l += 1
        return 0 if ans == float('inf') else ans
