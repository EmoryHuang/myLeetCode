'''
Descroption: LeetCode 1401. 圆和矩形是否有重叠
Author: EmoryHuang
Date: 2021-06-05 14:25:00
解题思路:
划分区域, 判定圆心的位置在哪个区域
'''


class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # 判断圆心是否在矩形内
        if x1 <= x_center <= x2 and y1 <= y_center <= y2:
            return True
        # 圆心位于矩形的上下左右四个区域
        elif x_center > x2 and y1 <= y_center <= y2:  # 右
            return radius >= x_center - x2
        elif y_center < y1 and x1 <= x_center <= x2:  # 下
            return radius >= y1 - y_center
        elif x_center < x1 and y1 <= y_center <= y2:  # 左
            return radius >= x1 - x_center
        elif y_center > y2 and x1 <= x_center <= x2:  # 上
            return radius >= y_center - y2
        else:
            # 判断矩形的四个顶点是否在圆的内部
            return min((x1 - x_center) ** 2 + (y2 - y_center) ** 2,
                       (x2 - x_center) ** 2 + (y2 - y_center) ** 2,
                       (x2 - x_center) ** 2 + (y1 - y_center) ** 2,
                       (x1 - x_center) ** 2 + (y1 - y_center) ** 2) <= radius ** 2