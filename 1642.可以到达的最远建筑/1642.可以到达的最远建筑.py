'''
Descroption: LeetCode 1642. 可以到达的最远建筑
Author: EmoryHuang
Date: 2021-07-24 14:35:07
Method:
维护一个最小堆
将gap加入最小堆，优先将梯子用在间隔最大的地方，小间隔采用砖块
最后砖块的个数小于0时返回
'''


class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        heap = []
        n = len(heights)
        for i in range(1, n):
            gap = heights[i] - heights[i - 1]
            # 只有向上才需要用到梯子
            if gap > 0:
                # 将gap加入最小堆
                heapq.heappush(heap, gap)
                # 优先将梯子用在间隔最大的地方
                if len(heap) > ladders:
                    # 小间隔采用砖块
                    bricks -= heapq.heappop(heap)
                    # 砖块的个数小于i0时返回
                    if bricks < 0:
                        return i - 1
        return n - 1
