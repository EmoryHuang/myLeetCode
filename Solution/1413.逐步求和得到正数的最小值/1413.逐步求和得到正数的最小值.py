'''
Descroption: LeetCode 1413. 逐步求和得到正数的最小值
Author: EmoryHuang
Date: 2021-06-05 15:11:00
解题思路:
找到数组中依次累积的最小和sum，满足要求的最小正数为 1 - sum
'''


class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        ans, sum = 0, 0
        for num in nums:
            sum += num
            ans = min(sum, ans)
        return 1 - ans
