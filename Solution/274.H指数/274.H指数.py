'''
Descroption: LeetCode 274. H 指数
Author: EmoryHuang
Date: 2021-07-11 13:20:30
解题思路:
排序后二分，二分法寻找右端点
'''


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        l, r = 0, len(citations)
        while l < r:
            mid = l + (r - l + 1) // 2
            # 倒数第 mid 个数如果满足条件
            if citations[len(citations) - mid] >= mid:
                l = mid
            else:
                r = mid - 1
        return l
