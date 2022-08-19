'''
Descroption: LeetCode 1725. 可以形成最大正方形的矩形数目
Author: EmoryHuang
Date: 2022-02-04 10:18:25
Method:
简单题，枚举每个矩形能切出的最大正方形边长，然后求最大值并计数
'''


class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        e = [min(w, l) for w, l in rectangles]
        return e.count(max(e))
