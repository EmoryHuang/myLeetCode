'''
Descroption: 剑指 Offer 53 - I. 在排序数组中查找数字 I
Author: EmoryHuang
Date: 2021-07-16 18:32:41
解题思路:
二分法寻找左端点，然后从左端点开始寻找 target
'''


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        ans = 0
        while l < len(nums) and nums[l] == target:
            ans += 1
            l += 1
        return ans
