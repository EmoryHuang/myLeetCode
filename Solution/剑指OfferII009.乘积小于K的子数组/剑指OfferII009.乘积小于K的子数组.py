'''
Descroption: 剑指 Offer II 009. 乘积小于 K 的子数组
Author: EmoryHuang
Date: 2021-08-10 20:18:11
Method:
滑动窗口
遍历数组，若当前乘积未超过 k，则加入窗口，否则移动左窗口
'''


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k == 0 or k == 1: return 0
        l, r = 0, 0
        ans, mul = 0, 1
        for r in range(len(nums)):
            mul *= nums[r]
            while mul >= k:
                mul //= nums[l]
                l += 1
            ans += r - l + 1
        return ans