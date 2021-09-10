'''
Descroption: LeetCode 1232. 缀点成线
Author: EmoryHuang
Date: 2021-06-21 21:15:00
解题思路:
简单题，判断每两个点之间的斜率是否相等，
注意将除法转换为乘法（斜率可能为无穷）
'''


class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x0, y0 = coordinates[0][0], coordinates[0][1]
        x = coordinates[1][0] - x0
        y = coordinates[1][1] - y0
        for p in coordinates:
            xi, yi = p[0] - x0, p[1] - y0
            if x * yi - y * xi:
                return False
        return True
