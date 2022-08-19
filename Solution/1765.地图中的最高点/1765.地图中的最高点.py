'''
Descroption: LeetCode 1765. 地图中的最高点
Author: EmoryHuang
Date: 2021-08-27 16:00:53
Method:
找到所有的水域，放入队列
然后进行广度优先遍历，向4个方向寻找陆地，修改高度 + 1
'''


class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        ans = [[0] * n for _ in range(m)]
        q = deque()
        # 找到所有的水域，放入队列
        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    q.append([i, j])
        while q:
            i, j = q.popleft()
            for dx, dy in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and isWater[x][y] == 0:
                    ans[x][y] = ans[i][j] + 1
                    isWater[x][y] = 1
                    q.append([x, y])
        return ans
