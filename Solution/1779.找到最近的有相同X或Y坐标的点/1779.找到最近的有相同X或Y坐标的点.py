'''
Descroption: LeetCode 1779. 找到最近的有相同 X 或 Y 坐标的点
Author: EmoryHuang
Date: 2022-12-01 09:30:02
Method:
遍历坐标数组，在有效坐标中找到曼哈顿距离最小的位置
'''


class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        ans = -1
        min_d = 0xffffff
        for i, (a, b) in enumerate(points):
            if x == a or y == b:
                d = abs(x - a) + abs(y - b)
                if d < min_d:
                    ans = i
                    min_d = d
        return ans
