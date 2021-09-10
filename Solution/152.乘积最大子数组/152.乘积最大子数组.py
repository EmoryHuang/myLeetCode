'''
Descroption: LeetCode 152. 乘积最大子数组
Author: EmoryHuang
Date: 2021-07-11 13:57:44
解题思路:
遍历数组时计算当前最大值，不断更新
由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值
'''


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dpmax = dpmin = ans = nums[0]
        for i in range(1, len(nums)):
            tmpmax, tmpmin = dpmax, dpmin
            dpmax = max(nums[i], tmpmin * nums[i], tmpmax * nums[i])
            dpmin = min(nums[i], tmpmin * nums[i], tmpmax * nums[i])
            ans = max(ans, dpmax)
        return ans
