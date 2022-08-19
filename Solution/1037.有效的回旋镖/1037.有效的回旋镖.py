'''
Descroption: LeetCode 1037. 有效的回旋镖
Author: EmoryHuang
Date: 2021-11-06 15:52:57
Method:
简单题，计算三角形面积，判断是否为 0
S = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;
'''


class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        x, y, z = points
        return (x[0] * (y[1] - z[1]) + y[0] * (z[1] - x[1]) + z[0] *
                (x[1] - y[1])) / 2 != 0
