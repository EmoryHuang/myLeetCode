'''
Descroption: LeetCode 1283. 使结果不超过阈值的最小除数
Author: EmoryHuang
Date: 2021-07-22 20:11:29
解题思路:
二分法寻找左端点
'''


class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def check(div: int) -> bool:
            cnt = 0
            for num in nums:
                cnt += math.ceil(num / div)
            return cnt <= threshold

        l, r = 1, max(nums)
        while l < r:
            mid = l + r >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l
