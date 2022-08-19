'''
Descroption: LeetCode 452. 用最少数量的箭引爆气球
Author: EmoryHuang
Date: 2021-08-12 19:56:40
Method:
贪心
按照右端点排序，
将左端点与之前引爆的值作比较，找到当前箭能引爆的最大数量
'''


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        # 按照右端点排序
        points.sort(key=lambda x: x[1])
        pre = points[0][1]
        ans = 1
        for l, r in points:
            # 找到当前箭能引爆的最大数量
            if l > pre:
                ans += 1
                pre = r
        return ans