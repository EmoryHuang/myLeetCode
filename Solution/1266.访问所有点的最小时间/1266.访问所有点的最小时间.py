'''
Descroption: LeetCode 1266. �������е����Сʱ��
Author: EmoryHuang
Date: 2021-10-09 19:59:30
Method:
��ѧ��ȡ x �� y ��������ֵ
'''


class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        ans = 0
        for i in range(1, len(points)):
            x1, y1 = points[i - 1]
            x2, y2 = points[i]
            ans += max(abs(x1 - x2), abs(y1 - y2))
        return ans
