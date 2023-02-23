'''
Descroption: LeetCode 1760. 袋子里最少数目的球
Author: EmoryHuang
Date: 2022-12-20 10:45:22
Method:
二分搜索可能的开销
'''


class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        left, right = 1, max(nums)
        ans = 0
        while left < right:
            mid = left + right >> 1
            cnt = sum([(x - 1) // mid for x in nums])
            if cnt <= maxOperations:
                right = mid
            else:
                left = mid + 1
        return left