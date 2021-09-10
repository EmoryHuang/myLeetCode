'''
Descroption: LeetCode 1848. 到目标元素的最小距离
Author: EmoryHuang
Date: 2021-06-17 15:17:00
解题思路:
简单题，遍历一遍数组，找到 target ，然后寻找最小距离
'''


class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        ans = 0x3f3f3f3f
        for i in range(len(nums)):
            if nums[i] == target:
                ans = min(ans, abs(i - start))
        return ans
