'''
Descroption: LeetCode 1266. 访问所有点的最小时间
Author: EmoryHuang
Date: 2021-10-09 19:59:30
Method:
数学，取 x 和 y 距离的最大值
'''


class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        ans = 0
        for i in range(1, len(points)):
            x1, y1 = points[i - 1]
            x2, y2 = points[i]
            ans += max(abs(x1 - x2), abs(y1 - y2))
        return ans
