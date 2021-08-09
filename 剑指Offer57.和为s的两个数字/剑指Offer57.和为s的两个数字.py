'''
Descroption: 剑指 Offer 57. 和为s的两个数字
Author: EmoryHuang
Date: 2021-08-09 14:29:44
Method:
双指针遍历，寻找和为target的数对
'''


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] + nums[r] == target:
                return [nums[l], nums[r]]
            elif nums[l] + nums[r] > target:
                r -= 1
            else:
                l += 1
        return []
