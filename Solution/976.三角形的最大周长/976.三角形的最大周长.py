'''
Descroption: LeetCode 976. 三角形的最大周长
Author: EmoryHuang
Date: 2021-07-10 15:21:06
解题思路:
排序后从后往前遍历数组，若连续三个数能组成三角形，则为最大周长
'''


class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        # 排序后从后往前遍历数组
        for i in range(len(nums) - 1, 1, -1):
            # 若连续三个数能组成三角形
            if nums[i] < nums[i - 1] + nums[i - 2]:
                return nums[i] + nums[i - 1] + nums[i - 2]
        return 0
