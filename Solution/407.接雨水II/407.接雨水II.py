'''
Descroption: LeetCode 407. 接雨水 II
Author: EmoryHuang
Date: 2021-11-02 09:21:25
Method:
优先队列
维护一个小根堆
确保当前出队的元素对于该中心块来说是它周围四个高度中的最小值，那么就能确定接雨水的大小
首先将边缘加入优先队列，而后不断往内部缩小外围
如果外围的高度大于当前高度，那么可以灌水
'''


class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if len(heightMap) == 0:
            return 0
        m, n = len(heightMap), len(heightMap[0])
        ans = 0
        # vis 标记是否访问
        vis = [[0] * n for _ in range(m)]
        # 维护一个小根堆
        # 确保当前出队的元素对于该中心块来说是它周围四个高度中的最小值
        # 那么就能确定接雨水的大小
        heap = []
        # 将边缘加入优先队列
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    vis[i][j] = 1
        while heap:
            h, i, j = heapq.heappop(heap)
            for dx, dy in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and not vis[x][y]:
                    # 如果外围的高度大于当前高度，那么可以灌水
                    if h > heightMap[x][y]:
                        ans += h - heightMap[x][y]
                    heapq.heappush(heap, (max(h, heightMap[x][y]), x, y))
                    vis[x][y] = 1
        return ans
