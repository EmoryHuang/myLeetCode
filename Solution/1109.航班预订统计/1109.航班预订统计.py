'''
Descroption: LeetCode 1109. 航班预订统计
Author: EmoryHuang
Date: 2021-07-17 14:54:59
解题思路:
差分思想，
可以把题目理解为在 l 处上车 num 人，在 r 出下车 num 人
每个座位的人数为前一个座位的人数加上当前人数变化
'''


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        ans = [0] * n
        for booking in bookings:
            # 题目中坐标是从 1 开始的
            l, r, num = booking
            ans[l - 1] += num
            if r < n:
                ans[r] -= num
        for i in range(1, n):
            ans[i] += ans[i - 1]
        return ans
