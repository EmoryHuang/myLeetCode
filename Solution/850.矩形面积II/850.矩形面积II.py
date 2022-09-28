'''
Descroption: LeetCode 850. 矩形面积 II
Author: EmoryHuang
Date: 2022-09-16 14:31:32
Method:
扫描线
按x轴坐标对矩形进行排序，并进行x轴方向的扫描
计算在每段区间的矩形高度，最后计算总和
'''


class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        # 将x轴坐标进行排序
        bound = []
        for rect in rectangles:
            bound.append(rect[0])
            bound.append(rect[2])
        bound.sort()
        ans = 0
        # 按x轴进行扫描
        for i in range(1, len(bound)):
            # 计算当前区间宽度
            x1, x2 = bound[i - 1], bound[i]
            width = x2 - x1
            if width == 0:
                continue
            # 获取在当前区间内的矩形在y轴的上下界
            lines = []
            for rect in rectangles:
                if rect[0] <= x1 and x2 <= rect[2]:
                    lines.append((rect[1], rect[3]))
            lines.sort()
            # 计算当前区间在y轴的覆盖范围
            height, l, r = 0, -1, -1
            for y1, y2 in lines:
                if y1 > r:
                    height += r - l
                    l, r = y1, y2
                elif y2 > r:
                    r = y2
            height += r - l
            ans += height * width
        return ans % 1000000007