'''
Descroption: LeetCode 994. 腐烂的橘子
Author: EmoryHuang
Date: 2021-08-04 15:58:17
Method:
bfs
首先将所有腐烂的橘子加入队列
bfs查找它的相邻元素，若为新鲜橘子，则入队，每查找一层，时间加一
最后遍历矩阵，若还有新鲜橘子，则返回-1
'''


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dx = [0, -1, 0, 1]
        dy = [1, 0, -1, 0]
        mins = 0
        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append([i, j, mins])
        while q:
            lenq = len(q)
            for _ in range(lenq):
                x, y, mins = q.popleft()
                for i in range(4):
                    new_x = x + dx[i]
                    new_y = y + dy[i]
                    if 0 <= new_x < n and 0 <= new_y < m and grid[new_x][
                            new_y] == 1:
                        grid[new_x][new_y] = 2
                        q.append([new_x, new_y, mins + 1])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1
        return mins
