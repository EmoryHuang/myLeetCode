'''
Descroption: LeetCode 812. 最大三角形面积
Author: EmoryHuang
Date: 2021-10-18 18:57:59
Method:
数学
任意多边型面积公式：S = 1 / 2 * ∑ |x_i * y_i+1 - x_i+1 * y_i|
即: S = 1 / 2 * |(x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)|
'''


class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        ans, n = 0, len(points)
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                for k in range(j + 1, n):
                    x1 = points[i][0]
                    y1 = points[i][1]
                    x2 = points[j][0]
                    y2 = points[j][1]
                    x3 = points[k][0]
                    y3 = points[k][1]
                    ans = max(ans, abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)))
        return ans / 2