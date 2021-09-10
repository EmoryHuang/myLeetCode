'''
Descroption: LeetCode 1870. 准时到达的列车最小时速
Author: EmoryHuang
Date: 2021-07-22 19:21:39
解题思路:
二分法查找能满足的列车最小时速
计算时间时，除了最后一个时间以外向上取整
另外速度可能是10^7
'''


class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        def check(speed: int) -> bool:
            cnt = 0
            for d in dist[:-1]:
                cnt += math.ceil(d / speed)
            cnt += dist[-1] / speed
            return cnt <= hour

        l, r = 1, 10**7 + 1
        while l < r:
            mid = l + r >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l if l <= 10**7 else -1
