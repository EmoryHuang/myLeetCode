'''
Descroption: LeetCode 1701. 平均等待时间
Author: EmoryHuang
Date: 2021-07-28 20:04:37
Method:
维护当前时间 cur
若 cur < arrival，则更新 cur = arrival
每个顾客需要等待的时间为 time + (cur - arrival)
'''


class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        n = len(customers)
        cur, ans = 0, 0
        for arrival, time in customers:
            if cur < arrival:
                cur = arrival
            ans += time + (cur - arrival)
            cur += time
        return ans / n
