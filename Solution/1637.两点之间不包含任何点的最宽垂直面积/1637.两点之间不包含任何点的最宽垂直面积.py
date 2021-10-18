'''
Descroption: LeetCode 1637. 两点之间不包含任何点的最宽垂直面积
Author: EmoryHuang
Date: 2021-10-18 18:42:33
Method:
按 x 从小到大排序，寻找最大间隔
'''


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[0])
        ans = 0
        for i in range(len(points) - 1):
            ans = max(ans, points[i + 1][0] - points[i][0])
        return ans
