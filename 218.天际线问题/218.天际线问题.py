'''
Descroption: LeetCode 218. 天际线问题
Author: EmoryHuang
Date: 2021-07-13 19:47:32
解题思路:
维护一个大根堆，遍历所有端点
如果是左端点，则将其高度加入大根堆
如果是右端点，则将其高度移出大根堆
每次取当前最大值与上一个最大值比较
'''

from sortedcontainers import SortedList


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ans = []
        points = []
        # 为了方便排序，对于左端点，令高度为负；对于右端点令高度为正
        for l, r, h in buildings:
            points.append((l, -h))
            points.append((r, h))
        # 按照横坐标进行排序
        # 如果横坐标相同，则按照左端点排序
        # 如果相同的左/右端点，则按照高度进行排序
        points.sort()
        pre = 0
        q = SortedList([pre])
        # 遍历所有端点
        for point, height in points:
            if height < 0:  # 如果是左端点，则加入大根堆
                q.add(-height)
            else:  # 如果是右端点，则移出大根堆
                q.remove(height)
            # 取当前最大值比较
            cur = q[-1]
            if cur != pre:
                ans.append([point, cur])
                pre = cur
        return ans