'''
Descroption: LeetCode 875. 爱吃香蕉的珂珂
Author: EmoryHuang
Date: 2021-07-21 20:01:15
解题思路:
二分法寻找所有可能的速度，判断当前速度是否满足要求
'''


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(k: int) -> bool:
            cnt = 0
            for pile in piles:
                cnt += math.ceil(pile / k)
            return cnt <= h

        if len(piles) == 1:
            return math.ceil(piles[0] / h)
        l, r = 1, max(piles)
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l
