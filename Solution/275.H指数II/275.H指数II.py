'''
Descroption: LeetCode 275. H 指数 II
Author: EmoryHuang
Date: 2021-07-12 20:56:30
解题思路:
二分法寻找右端点
'''


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l, r = 0, len(citations)
        while l < r:
            mid = l + (r - l + 1) // 2
            # 倒数第 mid 个数如果满足条件
            if citations[len(citations) - mid] >= mid:
                l = mid
            else:
                r = mid - 1
        return l